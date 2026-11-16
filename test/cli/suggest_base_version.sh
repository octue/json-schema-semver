. "$(dirname "$0")/common.sh"

run suggest "$SCHEMAS/minor.json" --base "$SCHEMAS/base.json" --base-version 2.3.1
expect_code 0
expect stderr < /dev/null
expect stdout << 'JSON'
{
  "version": "2.4.0",
  "change": "minor",
  "traces": [
    {
      "compatibility": "incompatible",
      "left": "/const",
      "right": "/enum"
    }
  ]
}
JSON

run suggest "$SCHEMAS/patch.json" -b "$SCHEMAS/base.json" -v 2.3.1
expect_code 0
expect stdout << 'JSON'
{
  "version": "2.3.2",
  "change": "patch",
  "traces": []
}
JSON

run suggest "$SCHEMAS/major.json" --base="$SCHEMAS/base.json" --base-version=2.3.1
expect_code 0
grep --quiet '"version": "3.0.0"' "$TMP/stdout"
grep --quiet '"change": "major"' "$TMP/stdout"

run suggest "$SCHEMAS/base.json" --base "$SCHEMAS/base.json" --base-version 2.3.1
expect_code 0
expect stdout << 'JSON'
{
  "version": "2.3.1",
  "change": "equal",
  "traces": []
}
JSON

# A pre-release is always bumped, even if the schemas are equal
run suggest "$SCHEMAS/base.json" --base "$SCHEMAS/base.json" --base-version 2.3.1-rc.1
expect_code 0
expect stdout << 'JSON'
{
  "version": "2.3.1-rc.2",
  "change": "equal",
  "traces": []
}
JSON
