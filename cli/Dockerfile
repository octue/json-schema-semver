# Builds a fully static `json-schema-semver` binary for Linux, which runs on
# any distribution regardless of its C library. To get the binary out, run:
#
#   docker build . --file cli/Dockerfile --output <directory>

FROM alpine:3.21 AS build

RUN apk add --no-cache build-base cmake linux-headers

COPY . /source

ARG JSS_VERSION=0.0.0-dev

RUN cmake -S /source -B /build \
    -DCMAKE_BUILD_TYPE:STRING=Release \
    -DJSS_CLI:BOOL=ON \
    -DJSS_TESTS:BOOL=OFF \
    -DJSS_PYTHON:BOOL=OFF \
    -DJSS_VERSION:STRING=${JSS_VERSION} \
    -DBUILD_SHARED_LIBS:BOOL=OFF \
    -DCMAKE_EXE_LINKER_FLAGS:STRING=-static
RUN cmake --build /build --config Release --target octue_jss_cli --parallel 4

RUN mkdir /dist && cp "$(find /build -type f -name json-schema-semver)" /dist
RUN sh /source/test/cli/run.sh /dist/json-schema-semver

# Make sure the binary does not depend on any shared library
RUN ! readelf --dynamic /dist/json-schema-semver | grep NEEDED

FROM scratch
COPY --from=build /dist/json-schema-semver /json-schema-semver
