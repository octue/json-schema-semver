#!/usr/bin/env bash

# The implementation of the GitHub Action defined in `action.yml`. It gets the
# `json-schema-semver` command-line tool, runs it on the given schemas, and
# sets the outputs of the action. The inputs come in as `INPUT_*` environment
# variables.

set -o errexit
set -o nounset
set -o pipefail

fail() {
  echo "VERSION SUGGESTION FAILED." 1>&2
  echo "::error::$1"
  exit 1
}

command -v jq > /dev/null || fail "This action needs \`jq\` to be installed"

TMP="$(mktemp -d "${RUNNER_TEMP:-${TMPDIR:-/tmp}}/json-schema-semver.XXXXXX")"

# (1) Get the command-line tool

if [ -n "${INPUT_CLI_PATH:-}" ]
then
  CLI="$INPUT_CLI_PATH"
  [ -x "$CLI" ] || fail "Not an executable file: $CLI"
else
  case "${RUNNER_OS:-}-${RUNNER_ARCH:-}" in
    Linux-X64) PLATFORM="linux-x86_64";;
    Linux-ARM64) PLATFORM="linux-aarch64";;
    macOS-ARM64) PLATFORM="macos-arm64";;
    *) fail "There is no pre-built json-schema-semver for this runner (${RUNNER_OS:-unknown} ${RUNNER_ARCH:-unknown}). Build it and pass it as \`cli_path\`";;
  esac

  # When this action is used as `uses: ./`, there is no action repository
  REPOSITORY="${ACTION_REPOSITORY:-}"
  if [ -z "$REPOSITORY" ]
  then
    REPOSITORY="${GITHUB_REPOSITORY:-octue/json-schema-semver}"
  fi

  # Use the release that matches the version of this action, unless the
  # action is not being used at a release tag (i.e. a branch or a commit)
  RELEASE="${INPUT_CLI_VERSION:-}"
  if [ -z "$RELEASE" ]
  then
    RELEASE="${ACTION_REF:-}"
  fi

  if echo "$RELEASE" | grep -q -E '^v[0-9]+\.[0-9]+\.[0-9]+'
  then
    URL="${GITHUB_SERVER_URL:-https://github.com}/$REPOSITORY/releases/download/$RELEASE"
  elif [ -n "${INPUT_CLI_VERSION:-}" ]
  then
    fail "Not a release tag of the form vX.Y.Z: $INPUT_CLI_VERSION"
  else
    RELEASE="latest"
    URL="${GITHUB_SERVER_URL:-https://github.com}/$REPOSITORY/releases/latest/download"
  fi

  # Only meant for testing this action
  URL="${JSON_SCHEMA_SEMVER_RELEASE_URL:-$URL}"

  ARCHIVE="json-schema-semver-$PLATFORM.tar.gz"
  echo "Downloading $ARCHIVE ($RELEASE) from $URL"
  curl --fail --silent --show-error --location --retry 3 \
    --output "$TMP/$ARCHIVE" "$URL/$ARCHIVE" \
    || fail "Could not download $URL/$ARCHIVE"
  curl --fail --silent --show-error --location --retry 3 \
    --output "$TMP/SHA256SUMS" "$URL/SHA256SUMS" \
    || fail "Could not download $URL/SHA256SUMS"

  if command -v sha256sum > /dev/null
  then
    ACTUAL="$(sha256sum "$TMP/$ARCHIVE" | cut -d ' ' -f 1)"
  else
    ACTUAL="$(shasum -a 256 "$TMP/$ARCHIVE" | cut -d ' ' -f 1)"
  fi

  EXPECTED="$(awk -v name="$ARCHIVE" '$2 == name || $2 == "*" name { print $1 }' "$TMP/SHA256SUMS")"
  if [ -z "$EXPECTED" ] || [ "$ACTUAL" != "$EXPECTED" ]
  then
    fail "The checksum of $ARCHIVE does not match the one in SHA256SUMS"
  fi

  mkdir "$TMP/cli"
  tar -xzf "$TMP/$ARCHIVE" -C "$TMP/cli"
  CLI="$TMP/cli/json-schema-semver"
fi

# (2) Suggest the version

STAGE="$(echo "${INPUT_STAGE:-stable}" | tr '[:upper:]' '[:lower:]')"
ARGUMENTS=(suggest "$INPUT_PATH" --stage "$STAGE")

if [ -n "${INPUT_BASE_PATH:-}" ]
then
  ARGUMENTS+=(--base "$INPUT_BASE_PATH")
fi

if [ -n "${INPUT_BASE_VERSION:-}" ]
then
  ARGUMENTS+=(--base-version "$INPUT_BASE_VERSION")
fi

if [ -n "${INPUT_INITIAL_VERSION:-}" ]
then
  ARGUMENTS+=(--initial-version "$INPUT_INITIAL_VERSION")
fi

set +o errexit
"$CLI" "${ARGUMENTS[@]}" > "$TMP/stdout" 2> "$TMP/stderr"
CODE="$?"
set -o errexit

if [ "$CODE" != "0" ]
then
  # The tool still prints the traces if the schemas cannot be compared
  cat "$TMP/stdout" 1>&2
  fail "$(sed 's/^error: //' "$TMP/stderr" | tr '\n' ' ')"
fi

VERSION="$(jq --raw-output '.version // ""' "$TMP/stdout")"
CHANGE="$(jq --raw-output '.change // ""' "$TMP/stdout")"
TRACES="$(jq --compact-output '.traces' "$TMP/stdout")"

# (3) Report the results

{
  echo "version=$VERSION"
  echo "change=$CHANGE"
  echo "traces=$TRACES"
} >> "${GITHUB_OUTPUT:-/dev/null}"

echo "VERSION SUGGESTION SUCCEEDED."
echo "- Semantic version: ${VERSION:-(no base version given)}"
echo "- Change: $CHANGE"
if [ "$TRACES" != "[]" ]
then
  echo "- Traces:"
  jq --raw-output '.traces[] | "  - \(.compatibility): \(.left // "(none)") -> \(.right // "(none)")"' "$TMP/stdout"
fi

{
  echo "### JSON Schema version suggestion"
  echo ""
  echo "| | |"
  echo "|---|---|"
  echo "| Semantic version | ${VERSION:+\`$VERSION\`} |"
  echo "| Change | \`$CHANGE\` |"
  if [ "$TRACES" != "[]" ]
  then
    echo ""
    echo "| Compatibility | Base | Proposed |"
    echo "|---|---|---|"
    jq --raw-output '.traces[] | "| \(.compatibility) | `\(.left // "")` | `\(.right // "")` |"' "$TMP/stdout"
  fi
} >> "${GITHUB_STEP_SUMMARY:-/dev/null}"
