. "$(dirname "$0")/common.sh"

# The default is the major level
run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1
expect_code 0
grep -q '"version": "1.0.0"' "$TMP/stdout"

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --breaking major
expect_code 0
grep -q '"version": "1.0.0"' "$TMP/stdout"

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --breaking minor
expect_code 0
grep -q '"version": "0.4.0"' "$TMP/stdout"

run suggest "$SCHEMAS/minor.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --breaking minor
expect_code 0
grep -q '"version": "0.4.0"' "$TMP/stdout"

run suggest "$SCHEMAS/patch.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --breaking minor
expect_code 0
grep -q '"version": "0.3.2"' "$TMP/stdout"

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.0.3 -k patch
expect_code 0
grep -q '"version": "0.0.4"' "$TMP/stdout"

# The base version is too high for the breaking level
run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --breaking patch
expect_code 1
expect stdout < /dev/null
expect stderr << 'TEXT'
error: A breaking change cannot bump the patch number of version 0.3.1: the `breaking` level must be `minor` or `major`
TEXT

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 1.3.1 --breaking minor
expect_code 1
expect stdout < /dev/null
expect stderr << 'TEXT'
error: A breaking change cannot bump the minor number of version 1.3.1: the `breaking` level must be `major`
TEXT

run suggest "$SCHEMAS/major.json" --base "$SCHEMAS/base.json" --base-version 0.3.1 --breaking huge
expect_code 1
expect stderr << 'TEXT'
error: The --breaking option must be one of major, minor or patch, not: huge
TEXT
