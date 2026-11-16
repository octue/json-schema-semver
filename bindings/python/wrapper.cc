#include <octue/jss.h>
#include <octue/jss_suggest.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <optional> // std::optional, std::nullopt
#include <string>   // std::string

static auto to_json(const pybind11::object &value) -> sourcemeta::core::JSON {
  return sourcemeta::core::parse_json(pybind11::module_::import("json")
                                          .attr("dumps")(value)
                                          .cast<std::string>());
}

static auto to_list(const std::vector<octue::jss::Trace> &traces)
    -> pybind11::list {
  pybind11::list traces_list;
  for (const auto &trace : traces) {
    pybind11::dict trace_dict;
    trace_dict["compatibility"] =
        std::string{octue::jss::to_string(trace.compatibility)};

    if (trace.left.has_value()) {
      trace_dict["left"] = sourcemeta::core::to_string(trace.left.value());
    } else {
      trace_dict["left"] = pybind11::none();
    }

    if (trace.right.has_value()) {
      trace_dict["right"] = sourcemeta::core::to_string(trace.right.value());
    } else {
      trace_dict["right"] = pybind11::none();
    }

    traces_list.append(std::move(trace_dict));
  }

  return traces_list;
}

static auto version(pybind11::object from, pybind11::object to)
    -> pybind11::dict {
  // The traces point into the schemas, so these must outlive the result
  const auto from_json{to_json(from)};
  const auto to_json_document{to_json(to)};
  const auto result{octue::jss::version(from_json, to_json_document)};
  pybind11::dict result_dict;

  if (result.version.has_value()) {
    result_dict["version"] =
        std::string{octue::jss::to_string(result.version.value())};
  } else {
    result_dict["version"] = pybind11::none();
  }

  result_dict["traces"] = to_list(result.traces);
  return result_dict;
}

static auto suggest(pybind11::object base, pybind11::object proposed,
                    std::optional<std::string> base_version,
                    const std::string &stage,
                    const std::string &initial_version) -> pybind11::dict {
  const auto stage_value{octue::jss::to_stage(stage)};
  if (!stage_value.has_value()) {
    throw pybind11::value_error(
        "`stage` must be one of 'stable', 'development' or 'prototype'");
  }

  const std::optional<sourcemeta::core::JSON> base_json{
      base.is_none() ? std::nullopt
                     : std::optional<sourcemeta::core::JSON>{to_json(base)}};

  // The traces point into the schemas, so these must outlive the result
  const auto proposed_json{to_json(proposed)};

  octue::jss::Suggestion suggestion;
  try {
    suggestion = octue::jss::suggest(base_json, proposed_json, base_version,
                                     stage_value.value(), initial_version);
  } catch (const octue::jss::InvalidVersionError &error) {
    throw pybind11::value_error(error.what());
  } catch (const octue::jss::StageError &error) {
    throw pybind11::value_error(error.what());
  }

  pybind11::dict result_dict;
  if (suggestion.version.has_value()) {
    result_dict["version"] = suggestion.version.value();
  } else {
    result_dict["version"] = pybind11::none();
  }

  if (suggestion.change.has_value()) {
    result_dict["change"] =
        std::string{octue::jss::to_string(suggestion.change.value())};
  } else {
    result_dict["change"] = pybind11::none();
  }

  result_dict["traces"] = to_list(suggestion.traces);
  return result_dict;
}

static auto get_base_dialect(pybind11::object schema)
    -> std::optional<std::string> {
  const auto schema_json{to_json(schema)};
  const auto base_dialect{sourcemeta::core::base_dialect(
      schema_json, sourcemeta::core::schema_resolver)};
  if (base_dialect.has_value()) {
    return std::string{sourcemeta::core::to_string(base_dialect.value())};
  }
  return std::nullopt;
}

PYBIND11_MODULE(json_schema_semver, m) {
  m.def("get_base_dialect", &get_base_dialect,
        "Infer the base dialect from a JSON Schema");
  m.def("version", &version,
        "Compute the SemVer version bump from two schemas");
  m.def("suggest", &suggest,
        "Suggest the semantic version of a proposed schema, given a base "
        "schema (or None if there is none) and optionally its version",
        pybind11::arg("base"), pybind11::arg("proposed"),
        pybind11::arg("base_version") = pybind11::none(),
        pybind11::arg("stage") = "stable",
        pybind11::arg("initial_version") = "0.0.1");
}
