. "$(dirname "$0")/common.sh"

# The default is the major level
run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1
expect_code 0
grep -q '"version": "1.0.0"' "$TMP/stdout"

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --stage stable
expect_code 0
grep -q '"version": "1.0.0"' "$TMP/stdout"

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --stage development
expect_code 0
grep -q '"version": "0.4.0"' "$TMP/stdout"

run suggest "$SCHEMAS/minor.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --stage development
expect_code 0
grep -q '"version": "0.4.0"' "$TMP/stdout"

run suggest "$SCHEMAS/patch.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --stage development
expect_code 0
grep -q '"version": "0.3.2"' "$TMP/stdout"

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.0.3 -s prototype
expect_code 0
grep -q '"version": "0.0.4"' "$TMP/stdout"

# The base version is too high for the stage
run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --stage prototype
expect_code 1
expect stdout < /dev/null
expect stderr << 'TEXT'
error: Version 0.3.1 is too high for the `prototype` stage: the stage must be `development` or `stable`
TEXT

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 1.3.1 --stage development
expect_code 1
expect stdout < /dev/null
expect stderr << 'TEXT'
error: Version 1.3.1 is too high for the `development` stage: the stage must be `stable`
TEXT

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --stage huge
expect_code 1
expect stderr << 'TEXT'
error: The --stage option must be one of stable, development or prototype, not: huge
TEXT
