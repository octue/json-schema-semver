#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "maximum": 2
})JSON")};

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum", "/$id");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum", "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/title");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_type_integer) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "integer"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_type_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/type");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_const_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_const_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_const_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_const_non_number) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/const");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 2 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_enum_one_non_numbers) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ "foo", "bar" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Unknown, "/maximum",
                                      "/enum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_required) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maximum",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_uniqueitems) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maximum",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_pattern) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Skip, "/maximum",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_minimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_minimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_minimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_maximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_maximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_maximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusiveminimum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusiveminimum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusiveminimum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_less) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_equal) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Compatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_greater) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_exclusivemaximum_greater_plus_one) {
  const auto left{sourcemeta::core::parse_json(R"JSON({
    "maximum": 2
  })JSON")};

  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(left, right, Incompatible, "/maximum",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 3
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Compatible, "/maximum",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum, validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_validation_maximum,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/maximum",
                                      "/patternProperties");
}
