. "$(dirname "$0")/common.sh"

run compare "$SCHEMAS/base.json" "$SCHEMAS/minor.json"
expect_code 0
expect stdout << 'JSON'
{
  "version": "minor",
  "traces": [
    {
      "compatibility": "incompatible",
      "left": "/const",
      "right": "/enum"
    }
  ]
}
JSON

run compare "$SCHEMAS/base.json" "$SCHEMAS/base.json"
expect_code 0
expect stdout << 'JSON'
{
  "version": "equal",
  "traces": []
}
JSON

run compare "$SCHEMAS/unknown.json" "$SCHEMAS/base.json"
expect_code 2
grep -q '"version": null' "$TMP/stdout"

run compare "$SCHEMAS/base.json"
expect_code 1
expect stderr << 'TEXT'
error: The compare command takes exactly two schemas
TEXT
