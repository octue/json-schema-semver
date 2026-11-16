. "$(dirname "$0")/common.sh"

run suggest "$SCHEMAS/base.json"
expect_code 0
expect stdout << 'JSON'
{
  "version": "0.0.1",
  "change": "initial",
  "traces": []
}
JSON

run suggest "$SCHEMAS/base.json" --initial-version 0.1.0
expect_code 0
expect stdout << 'JSON'
{
  "version": "0.1.0",
  "change": "initial",
  "traces": []
}
JSON

# Without a base schema, the base version and breaking level do not matter
run suggest "$SCHEMAS/base.json" --base-version 3.2.1 --breaking patch
expect_code 0
grep -q '"version": "0.0.1"' "$TMP/stdout"

run suggest "$SCHEMAS/base.json" --initial-version first
expect_code 1
expect stdout < /dev/null
expect stderr << 'TEXT'
error: Not a valid semantic version: first
TEXT
