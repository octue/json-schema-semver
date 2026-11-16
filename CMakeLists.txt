cmake_minimum_required(VERSION 3.16)
project(json_schema_semver LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
option(JSS_TESTS "Build the JSON Schema SemVer tests" OFF)
option(JSS_PYTHON "Build the JSON Schema SemVer Python bindings" OFF)
option(JSS_CLI "Build the JSON Schema SemVer command-line tool" OFF)
set(JSS_VERSION "0.0.0-dev" CACHE STRING
  "The version reported by the JSON Schema SemVer command-line tool")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
find_package(Core REQUIRED)

if(PROJECT_IS_TOP_LEVEL)
  sourcemeta_target_clang_format(SOURCES
    src/*.h src/*.cc cli/*.cc test/*.h test/*.cc bindings/*.cc)
endif()

add_subdirectory(src)

if(JSS_CLI)
  add_subdirectory(cli)
endif()

if(JSS_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

if(JSS_PYTHON)
  add_subdirectory(vendor/pybind11)
  pybind11_add_module(json_schema_semver bindings/python/wrapper.cc)
  target_link_libraries(json_schema_semver PRIVATE octue_jss)
  # The dependencies disable RTTI on GCC, and pass that on to whatever links
  # to them, but pybind11 needs it. Options set on a source file come last
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set_source_files_properties(bindings/python/wrapper.cc
      PROPERTIES COMPILE_OPTIONS -frtti)
  endif()
  include(GNUInstallDirs)
  install(TARGETS json_schema_semver
    LIBRARY DESTINATION .
    COMPONENT json_schema_semver)
endif()
