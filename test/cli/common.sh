# Helpers shared by the command-line tests. Each test is run as:
#
#   sh <test>.sh <path to json-schema-semver> <path to test/cli/schemas>

set -o errexit
set -o nounset

CLI="$1"
SCHEMAS="$2"
TMP="$(mktemp -d)"
clean() { rm -rf "$TMP"; }
trap clean EXIT

# Run the tool with the given arguments, capturing the standard output,
# the standard error and the exit code
run() {
  set +o errexit
  "$CLI" "$@" > "$TMP/stdout" 2> "$TMP/stderr"
  CODE="$?"
  set -o errexit
}

expect_code() {
  if [ "$CODE" != "$1" ]
  then
    echo "FAIL: expected exit code $1 but got $CODE" 1>&2
    cat "$TMP/stdout" "$TMP/stderr" 1>&2
    exit 1
  fi
}

# Compare a captured stream (stdout or stderr) with the standard input
expect() {
  cat > "$TMP/expected"
  diff "$TMP/$1" "$TMP/expected"
}
