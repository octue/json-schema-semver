#include <octue/jss.h>
#include <octue/jss_suggest.h>

// See
// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html
#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <exception> // std::exception
#include <optional>  // std::optional, std::nullopt
#include <string>    // std::string

static auto to_val(const std::vector<octue::jss::Trace> &traces)
    -> emscripten::val {
  emscripten::val traces_json = emscripten::val::array();
  for (const auto &trace : traces) {
    emscripten::val trace_json = emscripten::val::object();
    trace_json.set("compatibility",
                   std::string{octue::jss::to_string(trace.compatibility)});

    if (trace.left.has_value()) {
      trace_json.set("left", sourcemeta::core::to_string(trace.left.value()));
    } else {
      trace_json.set("left", emscripten::val::null());
    }

    if (trace.right.has_value()) {
      trace_json.set("right", sourcemeta::core::to_string(trace.right.value()));
    } else {
      trace_json.set("right", emscripten::val::null());
    }

    traces_json.call<void>("push", std::move(trace_json));
  }

  return traces_json;
}

static auto version(const std::string &from, const std::string &to)
    -> emscripten::val {
  const auto from_json{sourcemeta::core::parse_json(from)};
  const auto to_json{sourcemeta::core::parse_json(to)};
  const auto result{octue::jss::version(from_json, to_json)};
  emscripten::val result_json = emscripten::val::object();

  if (result.version.has_value()) {
    result_json.set("version",
                    std::string{octue::jss::to_string(result.version.value())});
  } else {
    result_json.set("version", emscripten::val::null());
  }

  result_json.set("traces", to_val(result.traces));
  return result_json;
}

// To avoid relying on WebAssembly exception support, problems with the
// arguments are reported as `{ error: "..." }`, and the JavaScript wrapper
// turns that into an exception. An empty base or base version means none
static auto suggest(const std::string &base, const std::string &proposed,
                    const std::string &base_version, const std::string &stage,
                    const std::string &initial_version) -> emscripten::val {
  emscripten::val result_json = emscripten::val::object();
  const auto stage_value{octue::jss::to_stage(stage)};
  if (!stage_value.has_value()) {
    result_json.set(
        "error",
        std::string{
            "`stage` must be one of 'stable', 'development' or 'prototype'"});
    return result_json;
  }

  const std::optional<sourcemeta::core::JSON> base_json{
      base.empty() ? std::nullopt
                   : std::optional<sourcemeta::core::JSON>{
                         sourcemeta::core::parse_json(base)}};
  const auto proposed_json{sourcemeta::core::parse_json(proposed)};

  octue::jss::Suggestion suggestion;
  try {
    suggestion = octue::jss::suggest(
        base_json, proposed_json,
        base_version.empty() ? std::nullopt
                             : std::optional<std::string>{base_version},
        stage_value.value(), initial_version);
  } catch (const octue::jss::InvalidVersionError &error) {
    result_json.set("error", std::string{error.what()});
    return result_json;
  } catch (const octue::jss::StageError &error) {
    result_json.set("error", std::string{error.what()});
    return result_json;
  }

  if (suggestion.version.has_value()) {
    result_json.set("version", suggestion.version.value());
  } else {
    result_json.set("version", emscripten::val::null());
  }

  if (suggestion.change.has_value()) {
    result_json.set("change", std::string{octue::jss::to_string(
                                  suggestion.change.value())});
  } else {
    result_json.set("change", emscripten::val::null());
  }

  result_json.set("traces", to_val(suggestion.traces));
  return result_json;
}

static auto get_base_dialect(const std::string &schema) -> emscripten::val {
  const auto schema_json{sourcemeta::core::parse_json(schema)};
  const auto base_dialect{sourcemeta::core::base_dialect(
      schema_json, sourcemeta::core::schema_resolver)};
  if (base_dialect.has_value()) {
    return emscripten::val(
        std::string{sourcemeta::core::to_string(base_dialect.value())});
  } else {
    return emscripten::val::null();
  }
}

EMSCRIPTEN_BINDINGS(jss) {
  emscripten::function("version", &version);
  emscripten::function("suggest", &suggest);
  emscripten::function("getBaseDialect", &get_base_dialect);
}
