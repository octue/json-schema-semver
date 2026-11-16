find_program(JSS_SHELL NAMES sh REQUIRED)

foreach(name IN ITEMS
    suggest_base_version
    suggest_no_base_version
    suggest_initial
    suggest_breaking
    suggest_unknown
    suggest_invalid_input
    compare
    global)
  add_test(NAME "octue.jss.cli.${name}" COMMAND "${JSS_SHELL}"
    "${CMAKE_CURRENT_SOURCE_DIR}/${name}.sh"
    "$<TARGET_FILE:octue_jss_cli>"
    "${CMAKE_CURRENT_SOURCE_DIR}/schemas")
endforeach()
