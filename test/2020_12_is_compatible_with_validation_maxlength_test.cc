#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "maxLength": 2
})JSON")};

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$id");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/title");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_type_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxLength",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_type_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxLength",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 4
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_const_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_enum_no_strings) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_enum_half_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "x" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_enum_full_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maxLength",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maxLength",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_minlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxLength",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_minlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxLength",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_minlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxLength",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_maxlength_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxLength",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_maxlength_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maxLength",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_maxlength_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maxLength",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_validation_maxlength,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maxLength",
                                      "/patternProperties");
}
