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

if __name__ == '__main__':
    unittest.main()
