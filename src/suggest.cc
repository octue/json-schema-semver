#include <octue/jss_suggest.h>

#include <sourcemeta/core/semver.h>

#include <algorithm> // std::max
#include <cassert>   // assert
#include <charconv>  // std::from_chars
#include <cstdint>   // std::uint64_t
#include <limits>    // std::numeric_limits
#include <sstream>   // std::ostringstream
#include <stdexcept> // std::overflow_error
#include <utility>   // std::unreachable

namespace {

auto is_digit(const char character) noexcept -> bool {
  return character >= '0' && character <= '9';
}

// Increment the last run of digits in a string, keeping the width of the run
// if it has leading zeros, and leaving a string without digits untouched.
// This matches `bump_prerelease` from the `semver` Python package:
//   rc0 -> rc1, rc.1 -> rc.2, rc09 -> rc10, rc99 -> rc100, alpha -> alpha
auto increment_last_number(const std::string_view input) -> std::string {
  auto end{input.size()};
  while (end > 0 && !is_digit(input[end - 1])) {
    end -= 1;
  }

  if (end == 0) {
    return std::string{input};
  }

  auto start{end};
  while (start > 0 && is_digit(input[start - 1])) {
    start -= 1;
  }

  std::uint64_t number{0};
  const auto result{
      std::from_chars(input.data() + start, input.data() + end, number)};
  if (result.ec != std::errc{} ||
      number == std::numeric_limits<std::uint64_t>::max()) {
    throw std::overflow_error(
        "The numeric part of the pre-release version overflows");
  }

  const auto next{std::to_string(number + 1)};
  const auto prefix_end{end > next.size() ? std::max(end - next.size(), start)
                                          : start};
  std::string output{input.substr(0, prefix_end)};
  output += next;
  output += input.substr(end);
  return output;
}

auto core_to_string(const std::uint64_t major, const std::uint64_t minor,
                    const std::uint64_t patch) -> std::string {
  std::ostringstream output;
  output << major << '.' << minor << '.' << patch;
  return output.str();
}

auto parse_version(const std::string_view input) -> sourcemeta::core::SemVer {
  const auto result{sourcemeta::core::SemVer::from(input)};
  if (!result.has_value()) {
    throw octue::jss::InvalidVersionError{"Not a valid semantic version: " +
                                          std::string{input}};
  }

  return result.value();
}

enum class Component : std::uint8_t { Major, Minor, Patch };

// Which component of the version a (non-equal) change bumps
auto component(const octue::jss::SemVer change, const octue::jss::Stage stage)
    -> Component {
  using octue::jss::SemVer;
  using octue::jss::Stage;
  assert(change != SemVer::Equal);
  switch (stage) {
    case Stage::Stable:
      switch (change) {
        case SemVer::Major:
          return Component::Major;
        case SemVer::Minor:
          return Component::Minor;
        default:
          return Component::Patch;
      }
    case Stage::Development:
      return change == SemVer::Patch ? Component::Patch : Component::Minor;
    case Stage::Prototype:
      return Component::Patch;
  }

  std::unreachable();
}

auto validate_stage(const sourcemeta::core::SemVer &base,
                    const std::string_view base_version,
                    const octue::jss::Stage stage) -> void {
  using octue::jss::Stage;
  const auto latest{base.major() > 0   ? Stage::Stable
                    : base.minor() > 0 ? Stage::Development
                                       : Stage::Prototype};
  // The enumeration is ordered from the latest to the earliest stage
  if (stage <= latest) {
    return;
  }

  std::ostringstream message;
  message << "Version " << base_version << " is too high for the `"
          << octue::jss::to_string(stage) << "` stage: the stage must be ";
  if (latest == Stage::Stable) {
    message << "`stable`";
  } else {
    message << "`development` or `stable`";
  }

  throw octue::jss::StageError{message.str()};
}

} // namespace

namespace octue::jss {

auto bump(const SemVer change, const std::string_view base_version,
          const Stage stage) -> std::string {
  const auto base{parse_version(base_version)};
  validate_stage(base, base_version, stage);

  // A pre-release moves on to the next pre-release whatever the change is. In
  // this case, we cannot tell a re-published identical schema from one whose
  // formatting changed, so even equal schemas result in a bump
  if (!base.pre_release().empty()) {
    auto result{core_to_string(base.major(), base.minor(), base.patch())};
    result += '-';
    result += increment_last_number(base.pre_release());
    return result;
  }

  if (change == SemVer::Equal) {
    return base.to_string();
  }

  switch (component(change, stage)) {
    case Component::Major:
      return core_to_string(base.major() + 1, 0, 0);
    case Component::Minor:
      return core_to_string(base.major(), base.minor() + 1, 0);
    case Component::Patch:
      return core_to_string(base.major(), base.minor(), base.patch() + 1);
  }

  std::unreachable();
}

auto suggest(const std::optional<sourcemeta::core::JSON> &base,
             const sourcemeta::core::JSON &proposed,
             const std::optional<std::string> &base_version, const Stage stage,
             const std::string_view initial_version) -> Suggestion {
  if (!base.has_value()) {
    // Just to validate it
    const auto initial{parse_version(initial_version)};
    return {.change = Change::Initial,
            .version = initial.to_string(),
            .traces = {}};
  }

  auto result{version(base.value(), proposed)};
  if (!result.version.has_value()) {
    return {.change = std::nullopt,
            .version = std::nullopt,
            .traces = std::move(result.traces)};
  }

  Change change{Change::Equal};
  switch (result.version.value()) {
    case SemVer::Major:
      change = Change::Major;
      break;
    case SemVer::Minor:
      change = Change::Minor;
      break;
    case SemVer::Patch:
      change = Change::Patch;
      break;
    case SemVer::Equal:
      change = Change::Equal;
      break;
  }

  std::optional<std::string> new_version;
  if (base_version.has_value()) {
    new_version = bump(result.version.value(), base_version.value(), stage);
  }

  return {.change = change,
          .version = std::move(new_version),
          .traces = std::move(result.traces)};
}

auto to_string(const Compatibility value) noexcept -> std::string_view {
  switch (value) {
    case Compatibility::Compatible:
      return "compatible";
    case Compatibility::Incompatible:
      return "incompatible";
    case Compatibility::Skip:
      return "skip";
    case Compatibility::Unknown:
      return "unknown";
  }

  std::unreachable();
}

auto to_string(const SemVer value) noexcept -> std::string_view {
  switch (value) {
    case SemVer::Major:
      return "major";
    case SemVer::Minor:
      return "minor";
    case SemVer::Patch:
      return "patch";
    case SemVer::Equal:
      return "equal";
  }

  std::unreachable();
}

auto to_string(const Change value) noexcept -> std::string_view {
  switch (value) {
    case Change::Equal:
      return "equal";
    case Change::Initial:
      return "initial";
    case Change::Patch:
      return "patch";
    case Change::Minor:
      return "minor";
    case Change::Major:
      return "major";
  }

  std::unreachable();
}

auto to_string(const Stage value) noexcept -> std::string_view {
  switch (value) {
    case Stage::Stable:
      return "stable";
    case Stage::Development:
      return "development";
    case Stage::Prototype:
      return "prototype";
  }

  std::unreachable();
}

static auto traces_to_json(const std::vector<Trace> &traces)
    -> sourcemeta::core::JSON {
  auto result{sourcemeta::core::JSON::make_array()};
  for (const auto &trace : traces) {
    auto entry{sourcemeta::core::JSON::make_object()};
    entry.assign("compatibility", sourcemeta::core::JSON{std::string{
                                      to_string(trace.compatibility)}});
    entry.assign("left",
                 trace.left.has_value()
                     ? sourcemeta::core::JSON{sourcemeta::core::to_string(
                           trace.left.value())}
                     : sourcemeta::core::JSON{nullptr});
    entry.assign("right",
                 trace.right.has_value()
                     ? sourcemeta::core::JSON{sourcemeta::core::to_string(
                           trace.right.value())}
                     : sourcemeta::core::JSON{nullptr});
    result.push_back(std::move(entry));
  }

  return result;
}

auto to_json(const Result &result) -> sourcemeta::core::JSON {
  auto output{sourcemeta::core::JSON::make_object()};
  output.assign("version", result.version.has_value()
                               ? sourcemeta::core::JSON{std::string{
                                     to_string(result.version.value())}}
                               : sourcemeta::core::JSON{nullptr});
  output.assign("traces", traces_to_json(result.traces));
  return output;
}

auto to_json(const Suggestion &suggestion) -> sourcemeta::core::JSON {
  auto output{sourcemeta::core::JSON::make_object()};
  output.assign("version",
                suggestion.version.has_value()
                    ? sourcemeta::core::JSON{suggestion.version.value()}
                    : sourcemeta::core::JSON{nullptr});
  output.assign("change", suggestion.change.has_value()
                              ? sourcemeta::core::JSON{std::string{
                                    to_string(suggestion.change.value())}}
                              : sourcemeta::core::JSON{nullptr});
  output.assign("traces", traces_to_json(suggestion.traces));
  return output;
}

auto to_stage(const std::string_view value) noexcept -> std::optional<Stage> {
  if (value == "stable") {
    return Stage::Stable;
  } else if (value == "development") {
    return Stage::Development;
  } else if (value == "prototype") {
    return Stage::Prototype;
  } else {
    return std::nullopt;
  }
}

} // namespace octue::jss
