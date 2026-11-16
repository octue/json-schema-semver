#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "minLength": 2
})JSON")};

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$id");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/title");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_type_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_type_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_const_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_enum_no_strings) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "x" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/minLength",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/minLength",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_minlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_minlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_minlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_maxlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/minLength",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_maxlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_maxlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/minLength",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_validation_minlength,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/minLength",
                                      "/patternProperties");
}
