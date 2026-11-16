#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const sourcemeta::core::JSON schema{true};

TEST(JSS_is_compatible_with_2020_12_boolean_true, true) {
  const sourcemeta::core::JSON right{true};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, false) {
  const sourcemeta::core::JSON right{false};
  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_id) {
  const auto right{sourcemeta::core::parse_json(
      R"JSON({ "$id": "https://www.example.com" })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$id");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/title");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/description");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/default");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/examples");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "", "/format");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/type");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/const");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "", "/enum");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true, validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_boolean_true,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "",
                                      "/patternProperties");
}
