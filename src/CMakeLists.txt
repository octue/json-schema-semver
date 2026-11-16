sourcemeta_library(PROJECT octue NAME jss FOLDER "Octue"
  SOURCES jss.cc instance_locations.cc suggest.cc comparator.h helpers.h)

target_link_libraries(octue_jss PUBLIC sourcemeta::core::json)
target_link_libraries(octue_jss PUBLIC sourcemeta::core::jsonpointer)
target_link_libraries(octue_jss PUBLIC sourcemeta::core::jsonschema)
target_link_libraries(octue_jss PRIVATE sourcemeta::core::regex)
target_link_libraries(octue_jss PRIVATE sourcemeta::core::semver)
