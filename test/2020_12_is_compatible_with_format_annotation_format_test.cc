#include <gtest/gtest.h>
#include <octue/jss.h>

#include "macros.h"

static const auto schema{sourcemeta::core::parse_json(R"JSON({
  "format": "email"
})JSON")};

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_schema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$schema": "https://json-schema.org/draft/2020-12/schema"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$schema");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_id) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$id": "https://www.example.com"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/$id");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_comment) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$comment": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$comment");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_ref) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$ref": "#"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/$ref");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_anchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$anchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$anchor");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     core_dynamicanchor) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$dynamicAnchor": "foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$dynamicAnchor");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_vocabulary) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$vocabulary": {
      "https://json-schema.org/draft/2020-12/vocab/core": true
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/$vocabulary");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, core_defs) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "$defs": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/$defs");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     core_definitions) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "definitions": {
      "foo": false
    }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/definitions");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, metadata_title) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "title": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/title");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     metadata_description) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "description": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/description");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     metadata_default) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "default": "Foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/default");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     metadata_deprecated) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "deprecated": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/deprecated");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     metadata_examples) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "examples": [ 1 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/examples");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     metadata_readonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "readOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/readOnly");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     metadata_writeonly) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "writeOnly": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/writeOnly");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     content_contentencoding) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentEncoding": "base64"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/contentEncoding");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     content_contentmediatype) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentMediaType": "application/yaml"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/contentMediaType");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     content_contentschema) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "contentSchema": { "type": "string" }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/contentSchema");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     format_annotation_format) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "format": "email"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/format");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, validation_type) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "type": "string"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/type");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_const) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "const": 1
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/const");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format, validation_enum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "enum": [ 1, 2, 3 ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format", "/enum");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_required) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "required": [ "foo" ]
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/required");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_uniqueitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "uniqueItems": true
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/uniqueItems");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_pattern) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "pattern": "^foo"
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/pattern");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_minimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/minimum");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_maximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/maximum");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_exclusiveminimum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMinimum": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/exclusiveMinimum");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_exclusivemaximum) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "exclusiveMaximum": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/exclusiveMaximum");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_minlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minLength": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/minLength");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_maxlength) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxLength": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/maxLength");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_minitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minItems": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/minItems");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_maxitems) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxItems": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/maxItems");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_minproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minProperties": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/minProperties");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_maxproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxProperties": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/maxProperties");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_mincontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "minContains": 4
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/minContains");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_maxcontains) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "maxContains": 5
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/maxContains");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_multipleof) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "multipleOf": 2
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/multipleOf");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_dependentrequired) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "dependentRequired": { "foo": [ "bar" ] }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/dependentRequired");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_properties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "properties": { "foo": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/properties");
}

TEST(JSS_is_compatible_with_2020_12_format_annotation_format,
     validation_patternproperties) {
  const auto right{sourcemeta::core::parse_json(R"JSON({
    "patternProperties": { "^f": { "type": "string" } }
  })JSON")};

  EXPECT_COMPATIBILITY_SINGLE_2020_12(schema, right, Skip, "/format",
                                      "/patternProperties");
}
