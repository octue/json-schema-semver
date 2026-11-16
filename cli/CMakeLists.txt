sourcemeta_executable(PROJECT octue NAME jss_cli SOURCES main.cc)

set_target_properties(octue_jss_cli PROPERTIES OUTPUT_NAME json-schema-semver)
target_compile_definitions(octue_jss_cli PRIVATE JSS_VERSION="${JSS_VERSION}")
target_link_libraries(octue_jss_cli PRIVATE octue::jss)
target_link_libraries(octue_jss_cli PRIVATE sourcemeta::core::options)
