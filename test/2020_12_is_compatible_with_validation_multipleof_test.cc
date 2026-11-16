#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "multipleOf": 3
})JSON")};

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$id");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/title");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/multipleOf",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_const_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/multipleOf",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_const_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/multipleOf",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/multipleOf",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_enum_one_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 4 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/multipleOf",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_enum_one_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/multipleOf",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/multipleOf",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_uniqueitems) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/multipleOf",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/multipleOf",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, validation_minimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof, validation_maximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_exclusiveminimum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_exclusivemaximum) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_multipleof_true) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 6
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/multipleOf",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_multipleof_false) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/multipleOf",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_validation_multipleof,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/multipleOf",
                                      "/patternProperties");
}
