
set(${PROJECT_NAME}_LICENSES_MACRO_FILE ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}_licenses_macro.h.in)

if(EXISTS "${${PROJECT_NAME}_LICENSES_MACRO_FILE}")
    file(WRITE "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "")
endif()

file(APPEND "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "#ifndef TANJA84DK_ARGTOOLS_LICENCES_MACRO_H\n")
file(APPEND "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "#define TANJA84DK_ARGTOOLS_LICENCES_MACRO_H\n\n")

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE tanja84dk_argtools_LICENSE)
    string(PREPEND tanja84dk_argtools_LICENSE "R\"(")
    string(APPEND tanja84dk_argtools_LICENSE ")\"")
    file(APPEND ${${PROJECT_NAME}_LICENSES_MACRO_FILE} "#define tanja84dk_argtools_LICENSE @tanja84dk_argtools_LICENSE@\n")
else()
    message("tanja84dk_argtools_LICENSE is missing")
endif()

if(EXISTS "${Tanja84dk_tools_SOURCE_DIR}/LICENSE")
    file(STRINGS ${Tanja84dk_tools_SOURCE_DIR}/LICENSE Tanja84dk_tools_LICENSE)
    string(PREPEND Tanja84dk_tools_LICENSE "R\"(")
    string(APPEND Tanja84dk_tools_LICENSE ")\"")
    file(APPEND ${${PROJECT_NAME}_LICENSES_MACRO_FILE} "#define Tanja84dk_tools_LICENSE @Tanja84dk_tools_LICENSE@\n")
else()
    message("Tanja84dk_tools_LICENSE is missing")
endif()

if(EXISTS "${fmtlib_SOURCE_DIR}/LICENSE.rst")
    file(STRINGS ${fmtlib_SOURCE_DIR}/LICENSE.rst fmtlib_LICENSE)
    string(PREPEND fmtlib_LICENSE "R\"(")
    string(APPEND fmtlib_LICENSE ")\"")
    file(APPEND ${${PROJECT_NAME}_LICENSES_MACRO_FILE} "#define fmtlib_LICENSE @fmtlib_LICENSE@\n")
else()
    message("fmtlib_LICENSE is missing")
endif()

file(APPEND "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "\n#endif // TANJA84DK_ARGTOOLS_LICENCES_MACRO_H\n")

configure_file(${${PROJECT_NAME}_LICENSES_MACRO_FILE} include/${PROJECT_NAME}_licenses_macro.h)
