#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "required": [ "foo" ]
})JSON")};

TEST(JSS_is_compatible_with_2020_12_validation_required, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required", "/$id");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/title");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_type_object) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "object"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Incompatible, "/required",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_type_non_object) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "/required",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_const_object) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": {}
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/required",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_const_non_object) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/required",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_enum_with_object) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, {}, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/required",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_enum_without_object) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/required",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_required_same) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "/required",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_required_reorder) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar", "baz" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "bar", "baz", "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "/required",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_required_superset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar", "baz" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Incompatible, "/required",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_required_subset) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "/required",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_required, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_minproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_minproperties_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_minproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/required",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_maxproperties_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/required",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_maxproperties_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_maxproperties_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_mincontains) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/required",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_maxcontains) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/required",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_dependentrequired_true_left) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_dependentrequired_true_left_and_right) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo", "bar" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_dependentrequired_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "required": [ "baz" ]
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/required",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_validation_required,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/required",
                                      "/patternProperties");
}
