#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "pattern": "^f"
})JSON")};

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern", "/$id");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern", "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/title");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_type_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_type_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/pattern",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_const_string_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_const_string_no_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "bar"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_const_non_string) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_enum_some_string_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, "foo", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_enum_some_string_no_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, "bar", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_enum_no_strings) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_enum_strings_mixed_match) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar", "baz" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_uniqueitems_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": false
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_uniqueitems_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_pattern_same) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/pattern",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_pattern_different) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "f"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/pattern",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^f"
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 0
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/pattern",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/pattern",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Unknown, "/pattern",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern, validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_validation_pattern,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/pattern",
                                      "/patternProperties");
}
