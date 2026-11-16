# Run all the command-line tests against an existing binary, without CMake:
#
#   sh test/cli/run.sh <path to json-schema-semver>

set -o errexit
set -o nounset

if [ "$#" != 1 ]
then
  echo "Usage: $0 <path to json-schema-semver>" 1>&2
  exit 1
fi

DIRECTORY="$(cd "$(dirname "$0")" && pwd)"
CLI="$(cd "$(dirname "$1")" && pwd)/$(basename "$1")"

for script in "$DIRECTORY"/*.sh
do
  case "$(basename "$script")" in
    common.sh|run.sh) continue ;;
  esac

  echo "-- $(basename "$script" .sh)"
  sh "$script" "$CLI" "$DIRECTORY/schemas"
done

echo "All the command-line tests passed"
