. "$(dirname "$0")/common.sh"

run suggest "$SCHEMAS/missing.json"
expect_code 1
expect stdout < /dev/null
expect stderr << TEXT
error: Cannot read file: $SCHEMAS/missing.json
TEXT

run suggest "$SCHEMAS/base.json" --base "$SCHEMAS/missing.json"
expect_code 1
expect stderr << TEXT
error: Cannot read file: $SCHEMAS/missing.json
TEXT

run suggest "$SCHEMAS/invalid.json"
expect_code 1
expect stderr << TEXT
error: Invalid JSON in $SCHEMAS/invalid.json at line 2, column 1
TEXT

run suggest "$SCHEMAS/minor.json" --base "$SCHEMAS/base.json" --base-version 1.2
expect_code 1
expect stderr << 'TEXT'
error: Not a valid semantic version: 1.2
TEXT

run suggest
expect_code 1
expect stderr << 'TEXT'
error: The suggest command takes exactly one proposed schema
TEXT

run suggest "$SCHEMAS/minor.json" "$SCHEMAS/base.json"
expect_code 1

run suggest "$SCHEMAS/minor.json" --unknown
expect_code 1
expect stderr << 'TEXT'
error: Unknown option: unknown
TEXT

run suggest "$SCHEMAS/minor.json" --base
expect_code 1
expect stderr << 'TEXT'
error: Missing value for option: base
TEXT

run frobnicate
expect_code 1
expect stderr << 'TEXT'
error: Unknown command: frobnicate
TEXT
