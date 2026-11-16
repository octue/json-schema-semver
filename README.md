# JSON Schema Semver 

Compare two JSON Schemas and work out the semantic version difference between them.

Given a base schema and a proposed schema, `json-schema-semver` tells you
whether the change is breaking (`major`), additive (`minor`) or neither
(`patch`), and suggests the next version number. It is available as a GitHub
Action, a command-line tool, a C++ library, or Python / WebAssembly
bindings.

Formally, this requires a check that one schema is a *subset* of another, and vice-versa. 

## About strands

This tool was developed as part of the [``strands``](https://strands.octue.com) jsonschema repository. Please consider using strands as your primary repository, to support Octue's ongoing open source work.

## GitHub Action

```yaml
- name: Suggest semantic version
  id: version
  uses: octue/json-schema-semver@v0.2.0
  with:
    path: schema.json
    base_path: previous/schema.json
    base_version: 0.3.1
    breaking: minor
- run: echo "${{ steps.version.outputs.version }} (${{ steps.version.outputs.change }})"
```

The action downloads the command-line tool from the matching release of this
repository. It needs no token. Pin it to a release tag, as above, so that the
action and the tool it downloads are the same version. It runs on Linux
(x86_64 and arm64) and macOS (arm64) runners, and needs `jq`, which
GitHub-hosted runners already have.

| Input | Required | Default | Description |
|---|---|---|---|
| `path` | Yes | | The path to the proposed JSON schema, relative to the repository root. |
| `base_path` | No | | The path to the JSON schema to compare against. If not provided, the suggestion is the initial version. |
| `base_version` | No | | The semantic version of the base schema. If not provided, only the type of change is reported. |
| `breaking` | No | `major` | Which part of the version a breaking change bumps. See [Breaking levels](#breaking-levels). |
| `initial_version` | No | `0.0.1` | The version to suggest when there is no base schema. |
| `cli_version` | No | The version of the action | The release of the command-line tool to download, such as `v0.2.0`. |
| `cli_path` | No | | The path to an existing `json-schema-semver` binary to use instead of downloading one. |

| Output | Description |
|---|---|
| `version` | The suggested semantic version, or empty if no `base_version` was provided. |
| `change` | The type of change: `equal`, `initial`, `patch`, `minor` or `major`. |
| `traces` | The incompatibilities between the schemas that explain the change, as a JSON array. |

The step fails if the schemas cannot be compared (they are too dissimilar or
use unsupported features), or if an input is invalid.

To compare against the schema on another branch, check that branch out into a
separate directory first:

```yaml
- uses: actions/checkout@v4
- uses: actions/checkout@v4
  with:
    ref: main
    path: previous
```

## Breaking levels

The `breaking` level sets which part of the version a breaking change bumps,
so that a project can move from prototyping to a stable release by changing
one setting.

| `breaking` | For | Breaking change | Additive change | Other change | Base version must be |
|---|---|---|---|---|---|
| `major` (default) | Stable projects | X+1.0.0 | X.Y+1.0 | X.Y.Z+1 | Anything |
| `minor` | 0.x development | 0.Y+1.0 | 0.Y+1.0 | 0.Y.Z+1 | Below 1.0.0 |
| `patch` | 0.0.x prototyping | 0.0.Z+1 | 0.0.Z+1 | 0.0.Z+1 | Below 0.1.0 |

Other rules:

- With the default `major` level, a breaking change to a 0.x version suggests
  `1.0.0`. Use `minor` or `patch` to stay below 1.0.0.
- A base version that is too high for the level is an error. For example,
  `patch` with a base version of `0.1.3`.
- If the base version is a pre-release, the pre-release number is bumped
  whatever the change is, even if the schemas are equal: `2.3.1-rc.1` becomes
  `2.3.1-rc.2`. A pre-release with no number in it is left as it is.
- Equal schemas keep the base version, unless it is a pre-release. Schemas
  are equal if they mathematically resolve to equivalence (noting that an
  equivalent constraint could be expressed in different ways). Differences not
  affecting equivalence, such as altered titles, descriptions, whitespacing, 
  line endings or property ordering will result in least a `patch` change.


## Unsupported features

There are a very limited number of unsupported jsonschema features. In this case, ``json-schema-semver`` will barf with an error instead of silently returning a result which might be wrong!


## Command-line tool

Each [release](https://github.com/octue/json-schema-semver/releases) has
pre-built binaries, which can be downloaded without a token:

| Platform | File |
|---|---|
| Linux x86_64 (static, any distribution) | `json-schema-semver-linux-x86_64.tar.gz` |
| Linux arm64 (static, any distribution) | `json-schema-semver-linux-aarch64.tar.gz` |
| macOS 14 or later, Apple silicon | `json-schema-semver-macos-arm64.tar.gz` |

```sh
curl --fail --location https://github.com/octue/json-schema-semver/releases/download/v0.2.0/json-schema-semver-linux-x86_64.tar.gz | tar -xz
./json-schema-semver --version
```

Replace `download/v0.2.0` with `latest/download` to get the latest release.
The `SHA256SUMS` file of each release has the checksum of every file.

```
json-schema-semver suggest <proposed.json> [--base <base.json>] [--base-version <version>]
                           [--breaking major|minor|patch] [--initial-version <version>]
json-schema-semver compare <from.json> <to.json>
```

For example:

```sh
$ json-schema-semver suggest new.json --base old.json --base-version 0.3.1 --breaking minor
{
  "version": "0.4.0",
  "change": "minor",
  "traces": [
    {
      "compatibility": "incompatible",
      "left": "/const",
      "right": "/enum"
    }
  ]
}
```

`version` is `null` if no `--base-version` is given. Each trace points to the
keywords of the base (`left`) and proposed (`right`) schemas that explain the
change. `compare` prints only the type of change, as `{ "version": "minor",
"traces": [ ... ] }`.

| Exit code | Meaning |
|---|---|
| 0 | Success. |
| 1 | Invalid arguments or input, with a message on the standard error. |
| 2 | The schemas could not be compared. The traces are still printed. |

## WebAssembly bindings

The npm package is attached to each release, so it can be installed without a
token:

```sh
npm install https://github.com/octue/json-schema-semver/releases/download/v0.2.0/octue-json-schema-semver-0.2.0.tgz
```

```js
import { suggest, version } from '@octue/json-schema-semver';

await suggest(base, proposed, { baseVersion: '0.3.1', breaking: 'minor' });
// { version: '0.4.0', change: 'minor', traces: [ ... ] }

await suggest(null, proposed);
// { version: '0.0.1', change: 'initial', traces: [] }

await version(base, proposed);
// { version: 'minor', traces: [ ... ] }
```

`suggest` rejects if a version is invalid or too high for the breaking level.
The package is also published to GitHub Packages as
`@octue/json-schema-semver`.

## Python bindings

Wheels are attached to each release.

```python
import json_schema_semver

json_schema_semver.suggest(base, proposed, base_version="0.3.1", breaking="minor")
# {'version': '0.4.0', 'change': 'minor', 'traces': [...]}

json_schema_semver.suggest(None, proposed, initial_version="0.1.0")
# {'version': '0.1.0', 'change': 'initial', 'traces': []}

json_schema_semver.version(base, proposed)
# {'version': 'minor', 'traces': [...]}
```

`suggest` raises `ValueError` if a version is invalid or too high for the
breaking level.

## Renamed from version-cruzer

This project used to be called `version-cruzer`. If you are upgrading:

| Before | Now |
|---|---|
| Repository `octue/version-cruzer` | `octue/json-schema-semver` |
| Python package and module `pycruzer` | Package `json-schema-semver`, module `json_schema_semver` |
| npm package `@octue/version-cruzer` | `@octue/json-schema-semver` |
| C++ namespace `octue::cruzer` and header `octue/cruzer.h` | `octue::jss` and `octue/jss.h` |
| CMake target `octue::cruzer` and options `CRUZER_*` | `octue::jss` and `JSS_*` |

## Developing

To build the project in development mode and run the tests, make sure you have
a working C++23 compiler (either GCC 13+ or a recent Clang will work), CMake
>=3.16, ClangFormat (only for developing the C++ components), and simply run:

```sh
make
```

The command-line tool ends up in `build/cli/json-schema-semver`. To build the
static Linux binary that is attached to releases, run:

```sh
docker build . --file cli/Dockerfile --output dist
```

To generate the WebAssembly package under `bindings/webassembly`, run:

```sh
make webassembly
```

To generate the Python modules under `bindings/python`, run:

```sh
make python
```

## Releasing

To produce a release, create and push a tag of the form `vX.Y.Z`. For example:

```sh
git tag --annotate v1.2.3 --message v1.2.3
```

This builds the command-line tool, the Python wheels and the npm package,
attaches them all to a new GitHub release, publishes the npm package to GitHub
Packages, and then checks that the GitHub Action works against the new
release.

The same artefacts are built and tested on every pull request into `main`,
without publishing anything, so a release should not be the first time a
build problem shows up.

## License

Copyright (c) Octue Ltd. Licensed under the [GNU Affero General Public License v3](LICENSE). Third-party dependency attributions are listed in the [NOTICE](NOTICE) file.
