. "$(dirname "$0")/common.sh"

run --version
expect_code 0
test -s "$TMP/stdout"
expect stderr < /dev/null

run --help
expect_code 0
grep --quiet '^Usage: json-schema-semver' "$TMP/stdout"

# No command at all
run
expect_code 1
grep --quiet '^Usage: json-schema-semver' "$TMP/stderr"
