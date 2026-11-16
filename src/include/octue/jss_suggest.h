#ifndef OCTUE_JSS_SUGGEST_H_
#define OCTUE_JSS_SUGGEST_H_

#include <sourcemeta/core/json.h>

#include <octue/jss.h>

#ifndef OCTUE_JSS_EXPORT
#include <octue/jss_export.h>
#endif

#include <cstdint>     // std::uint8_t
#include <optional>    // std::optional, std::nullopt
#include <stdexcept>   // std::runtime_error
#include <string>      // std::string
#include <string_view> // std::string_view
#include <vector>      // std::vector

namespace octue::jss {

/// The kind of change between a base schema and a proposed schema
enum class Change : std::uint8_t { Equal, Initial, Patch, Minor, Major };

/// Which part of the version a breaking change bumps. `Major` is standard
/// semantic versioning. `Minor` is for projects in 0.x development, and
/// `Patch` is for projects in 0.0.x prototyping
enum class Breaking : std::uint8_t { Major, Minor, Patch };

struct Suggestion {
  /// Not set if the schemas could not be compared
  std::optional<Change> change;
  /// Not set if no base version was given or the schemas could not be compared
  std::optional<std::string> version;
  std::vector<Trace> traces;
};

/// The base version is too high for the given breaking level. For example,
/// a breaking change cannot bump the patch number of a 0.1.x version
class OCTUE_JSS_EXPORT BreakingLevelError : public std::runtime_error {
public:
  using std::runtime_error::runtime_error;
};

/// A version string is not a valid semantic version
class OCTUE_JSS_EXPORT InvalidVersionError : public std::runtime_error {
public:
  using std::runtime_error::runtime_error;
};

/// Bump a semantic version given the kind of change. This is pure version
/// arithmetic and does not involve any schema
OCTUE_JSS_EXPORT
auto bump(const SemVer change, const std::string_view base_version,
          const Breaking breaking = Breaking::Major) -> std::string;

/// Compare a proposed schema against an optional base schema and suggest the
/// semantic version of the proposed schema. If there is no base schema, the
/// suggestion is the initial version
OCTUE_JSS_EXPORT
auto suggest(const std::optional<sourcemeta::core::JSON> &base,
             const sourcemeta::core::JSON &proposed,
             const std::optional<std::string> &base_version = std::nullopt,
             const Breaking breaking = Breaking::Major,
             const std::string_view initial_version = "0.0.1") -> Suggestion;

OCTUE_JSS_EXPORT
auto to_string(const Compatibility value) noexcept -> std::string_view;
OCTUE_JSS_EXPORT
auto to_string(const SemVer value) noexcept -> std::string_view;
OCTUE_JSS_EXPORT
auto to_string(const Change value) noexcept -> std::string_view;
OCTUE_JSS_EXPORT
auto to_string(const Breaking value) noexcept -> std::string_view;

/// Convert a comparison result into a JSON object of the form
/// `{ "version": "minor", "traces": [ ... ] }`
OCTUE_JSS_EXPORT
auto to_json(const Result &result) -> sourcemeta::core::JSON;

/// Convert a suggestion into a JSON object of the form
/// `{ "version": "1.3.0", "change": "minor", "traces": [ ... ] }`
OCTUE_JSS_EXPORT
auto to_json(const Suggestion &suggestion) -> sourcemeta::core::JSON;

/// Parse `major`, `minor` or `patch`
OCTUE_JSS_EXPORT
auto to_breaking(const std::string_view value) noexcept
    -> std::optional<Breaking>;

} // namespace octue::jss

#endif
