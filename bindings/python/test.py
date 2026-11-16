import unittest
import json_schema_semver

class TestJsonSchemaSemver(unittest.TestCase):
    def test_const_to_enum(self):
        from_schema = {
          "$schema": "https://json-schema.org/draft/2020-12/schema",
          "const": "foo"
        };

        to_schema = {
          "$schema": "https://json-schema.org/draft/2020-12/schema",
          "enum": [ "foo", "bar" ]
        };

        expected = {
          "version": "minor",
          "traces": [
            {"compatibility": "incompatible", "left": "/const", "right": "/enum"}
          ]
        }

        result = json_schema_semver.version(from_schema, to_schema)
        self.assertDictEqual(result, expected)

    def test_equal(self):
        from_schema = {
          "$schema": "https://json-schema.org/draft/2020-12/schema",
          "const": "foo"
        };

        to_schema = {
          "$schema": "https://json-schema.org/draft/2020-12/schema",
          "const": "foo"
        };

        expected = {
          "version": "equal",
          "traces": []
        }

        result = json_schema_semver.version(from_schema, to_schema)
        self.assertDictEqual(result, expected)

    def test_base_dialect_2020_12(self):
        schema = {
          "$schema": "https://json-schema.org/draft/2020-12/schema",
          "const": "foo"
        }

        dialect = json_schema_semver.get_base_dialect(schema)
        self.assertEqual(dialect, "https://json-schema.org/draft/2020-12/schema")

    def test_base_dialect_draft7(self):
        schema = {
          "$schema": "http://json-schema.org/draft-07/schema#",
          "const": "foo"
        }

        dialect = json_schema_semver.get_base_dialect(schema)
        self.assertEqual(dialect, "http://json-schema.org/draft-07/schema#")

    def test_base_dialect_unknown(self):
        schema = {
          "const": "foo"
        }

        dialect = json_schema_semver.get_base_dialect(schema)
        self.assertEqual(dialect, None)

SCHEMA_BASE = {
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "const": "foo"
}

SCHEMA_MINOR = {
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "enum": [ "foo", "bar" ]
}

SCHEMA_MAJOR = {
  "$schema": "https://json-schema.org/draft/2020-12/schema",
  "const": "bar"
}

class TestSuggest(unittest.TestCase):
    def test_minor_change_with_base_version(self):
        result = json_schema_semver.suggest(SCHEMA_BASE, SCHEMA_MINOR, "2.3.1")
        self.assertEqual(result, {
          "version": "2.4.0",
          "change": "minor",
          "traces": [
            {
              "compatibility": "incompatible",
              "left": "/const",
              "right": "/enum"
            }
          ]
        })

    def test_no_base_version(self):
        result = json_schema_semver.suggest(SCHEMA_BASE, SCHEMA_MINOR)
        self.assertEqual(result["version"], None)
        self.assertEqual(result["change"], "minor")

    def test_initial(self):
        result = json_schema_semver.suggest(None, SCHEMA_BASE)
        self.assertEqual(result, {
          "version": "0.0.1",
          "change": "initial",
          "traces": []
        })

    def test_custom_initial_version(self):
        result = json_schema_semver.suggest(
            None, SCHEMA_BASE, initial_version="0.1.0")
        self.assertEqual(result["version"], "0.1.0")
        self.assertEqual(result["change"], "initial")

    def test_equal_pre_release(self):
        result = json_schema_semver.suggest(
            SCHEMA_BASE, SCHEMA_BASE, base_version="2.3.1-rc0")
        self.assertEqual(result["version"], "2.3.1-rc1")
        self.assertEqual(result["change"], "equal")

    def test_breaking_levels(self):
        self.assertEqual(json_schema_semver.suggest(
            SCHEMA_BASE, SCHEMA_MAJOR, "0.3.1")["version"], "1.0.0")
        self.assertEqual(json_schema_semver.suggest(
            SCHEMA_BASE, SCHEMA_MAJOR, "0.3.1",
            breaking="major")["version"], "1.0.0")
        self.assertEqual(json_schema_semver.suggest(
            SCHEMA_BASE, SCHEMA_MAJOR, "0.3.1",
            breaking="minor")["version"], "0.4.0")
        self.assertEqual(json_schema_semver.suggest(
            SCHEMA_BASE, SCHEMA_MAJOR, "0.0.3",
            breaking="patch")["version"], "0.0.4")

    def test_base_version_too_high_for_the_breaking_level(self):
        with self.assertRaises(ValueError) as context:
            json_schema_semver.suggest(
                SCHEMA_BASE, SCHEMA_MAJOR, "0.3.1", breaking="patch")
        self.assertEqual(str(context.exception),
            "A breaking change cannot bump the patch number of version "
            "0.3.1: the `breaking` level must be `minor` or `major`")

    def test_invalid_base_version(self):
        with self.assertRaises(ValueError) as context:
            json_schema_semver.suggest(SCHEMA_BASE, SCHEMA_MAJOR, "1.2")
        self.assertEqual(str(context.exception),
            "Not a valid semantic version: 1.2")

    def test_invalid_breaking_level(self):
        with self.assertRaises(ValueError):
            json_schema_semver.suggest(
                SCHEMA_BASE, SCHEMA_MAJOR, "1.2.3", breaking="huge")

    def test_unknown(self):
        schema = {
          "$schema": "https://json-schema.org/draft/2020-12/schema",
          "type": "string",
          "minimum": 1
        }

        result = json_schema_semver.suggest(schema, SCHEMA_BASE, "1.0.0")
        self.assertEqual(result["version"], None)
        self.assertEqual(result["change"], None)
        self.assertEqual(len(result["traces"]), 1)

if __name__ == '__main__':
    unittest.main()
