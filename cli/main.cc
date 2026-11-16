#include <octue/jss.h>
#include <octue/jss_suggest.h>

#include <sourcemeta/core/json.h>
#include <sourcemeta/core/options.h>

#include <cstdlib>     // EXIT_SUCCESS, EXIT_FAILURE
#include <exception>   // std::exception
#include <filesystem>  // std::filesystem::path
#include <iostream>    // std::cout, std::cerr
#include <optional>    // std::optional, std::nullopt
#include <stdexcept>   // std::runtime_error
#include <string>      // std::string
#include <string_view> // std::string_view

#ifndef JSS_VERSION
#define JSS_VERSION "0.0.0-dev"
#endif

namespace {

// The schemas were read fine, but they cannot be compared
constexpr int EXIT_UNKNOWN{2};

constexpr std::string_view USAGE{
    R"EOF(Usage: json-schema-semver <command> [options]

Commands:

  suggest <proposed.json> [--base <base.json>] [--base-version <version>]
          [--breaking major|minor|patch] [--initial-version <version>]

    Suggest the semantic version of a proposed schema by comparing it to a
    base schema. The result is printed as JSON:

      { "version": "1.3.0", "change": "minor", "traces": [ ... ] }

    --base, -b             The schema to compare against. If omitted, there
                           is nothing to compare against and the suggestion
                           is the initial version
    --base-version, -v     The semantic version of the base schema. If
                           omitted, only the kind of change is reported
    --breaking, -k         Which part of the version a breaking change bumps:
                             major  X+1.0.0 (default)
                             minor  0.Y+1.0, for versions below 1.0.0
                             patch  0.0.Z+1, for versions below 0.1.0
    --initial-version, -i  The version to suggest when there is no base
                           schema (default: 0.0.1)

  compare <from.json> <to.json>

    Compare two schemas and print the kind of change between them as JSON:

      { "version": "minor", "traces": [ ... ] }

Global options:

  --version   Print the version of this tool
  --help, -h  Print this message

Exit codes:

  0  Success
  1  Invalid arguments or input
  2  The schemas could not be compared (too dissimilar, or using
     unsupported features)
)EOF"};

auto read_schema(const std::string_view path) -> sourcemeta::core::JSON {
  const std::filesystem::path file_path{path};
  if (!std::filesystem::is_regular_file(file_path)) {
    throw std::runtime_error{"Cannot read file: " + std::string{path}};
  }

  try {
    return sourcemeta::core::read_json(file_path);
  } catch (const sourcemeta::core::JSONParseError &error) {
    throw std::runtime_error{"Invalid JSON in " + std::string{path} +
                             " at line " + std::to_string(error.line()) +
                             ", column " + std::to_string(error.column())};
  }
}

auto print(const sourcemeta::core::JSON &document) -> void {
  sourcemeta::core::prettify(document, std::cout);
  std::cout << "\n";
}

auto single(const sourcemeta::core::Options &app, const std::string_view name)
    -> std::optional<std::string> {
  if (!app.contains(name)) {
    return std::nullopt;
  } else if (app.at(name).size() > 1) {
    throw std::runtime_error{"The --" + std::string{name} +
                             " option was given more than once"};
  } else {
    return std::string{app.at(name).front()};
  }
}

auto command_suggest(const sourcemeta::core::Options &app) -> int {
  if (app.positional().size() != 2) {
    throw std::runtime_error{
        "The suggest command takes exactly one proposed schema"};
  }

  auto breaking{octue::jss::Breaking::Major};
  if (const auto value{single(app, "breaking")}; value.has_value()) {
    const auto parsed{octue::jss::to_breaking(value.value())};
    if (!parsed.has_value()) {
      throw std::runtime_error{
          "The --breaking option must be one of major, minor or patch, not: " +
          value.value()};
    }

    breaking = parsed.value();
  }

  const auto proposed{read_schema(app.positional().at(1))};
  const auto base_path{single(app, "base")};
  const std::optional<sourcemeta::core::JSON> base{
      base_path.has_value() ? std::optional<sourcemeta::core::JSON>{read_schema(
                                  base_path.value())}
                            : std::nullopt};
  const auto base_version{single(app, "base-version")};
  const auto initial_version{single(app, "initial-version").value_or("0.0.1")};

  const auto suggestion{octue::jss::suggest(base, proposed, base_version,
                                            breaking, initial_version)};
  print(octue::jss::to_json(suggestion));
  if (!suggestion.change.has_value()) {
    std::cerr << "error: The schemas could not be compared. They are too "
                 "dissimilar or use unsupported features\n";
    return EXIT_UNKNOWN;
  }

  return EXIT_SUCCESS;
}

auto command_compare(const sourcemeta::core::Options &app) -> int {
  if (app.positional().size() != 3) {
    throw std::runtime_error{"The compare command takes exactly two schemas"};
  }

  const auto from{read_schema(app.positional().at(1))};
  const auto to{read_schema(app.positional().at(2))};
  const auto result{octue::jss::version(from, to)};
  print(octue::jss::to_json(result));
  if (!result.version.has_value()) {
    std::cerr << "error: The schemas could not be compared. They are too "
                 "dissimilar or use unsupported features\n";
    return EXIT_UNKNOWN;
  }

  return EXIT_SUCCESS;
}

auto run(const int argc, const char *const argv[]) -> int {
  sourcemeta::core::Options app;
  app.flag("help", {"h"});
  app.flag("version", {});
  app.option("base", {"b"});
  app.option("base-version", {"v"});
  app.option("breaking", {"k"});
  app.option("initial-version", {"i"});
  app.parse(argc, argv);

  if (app.contains("help")) {
    std::cout << USAGE;
    return EXIT_SUCCESS;
  } else if (app.contains("version")) {
    std::cout << JSS_VERSION << "\n";
    return EXIT_SUCCESS;
  } else if (app.positional().empty()) {
    std::cerr << USAGE;
    return EXIT_FAILURE;
  }

  const auto &command{app.positional().front()};
  if (command == "suggest") {
    return command_suggest(app);
  } else if (command == "compare") {
    return command_compare(app);
  } else {
    throw std::runtime_error{"Unknown command: " + std::string{command}};
  }
}

} // namespace

auto main(const int argc, char *argv[]) -> int {
  try {
    return run(argc, argv);
  } catch (const sourcemeta::core::OptionsUnknownOptionError &error) {
    std::cerr << "error: Unknown option: " << error.option() << "\n";
    return EXIT_FAILURE;
  } catch (const sourcemeta::core::OptionsMissingOptionValueError &error) {
    std::cerr << "error: Missing value for option: " << error.option() << "\n";
    return EXIT_FAILURE;
  } catch (const std::exception &error) {
    std::cerr << "error: " << error.what() << "\n";
    return EXIT_FAILURE;
  }
}
