. "$(dirname "$0")/common.sh"

run suggest "$SCHEMAS/minor.json" --base "$SCHEMAS/base.json"
expect_code 0
expect stdout << 'JSON'
{
  "version": null,
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
