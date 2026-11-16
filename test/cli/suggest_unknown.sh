. "$(dirname "$0")/common.sh"

run suggest "$SCHEMAS/base.json" --base "$SCHEMAS/unknown.json" --base-version 1.0.0
expect_code 2
expect stdout << 'JSON'
{
  "version": null,
  "change": null,
  "traces": [
    {
      "compatibility": "unknown",
      "left": "/type",
      "right": "/const"
    }
  ]
}
JSON
expect stderr << 'TEXT'
error: The schemas could not be compared. They are too dissimilar or use unsupported features
TEXT
