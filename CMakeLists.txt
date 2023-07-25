# CMakeList.txt : CMake project for ArgTools, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.16)

project (ArgTools VERSION 0.3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(ArgTools_BUILD_TESTING OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(cmake/Tanja84dkWarnings.cmake)

find_package(CPM REQUIRED)
find_package(fmtlib REQUIRED)
find_package(tanja84dk_tools REQUIRED)
find_package(tanja84dk_crypt REQUIRED)

include(cmake/get_licenses.cmake)

configure_file(${PROJECT_NAME}Config.h.in include/${PROJECT_NAME}Config.h)

set(SourceFiles
    "src/main.cpp"
    "src/menu.cpp")

set(HeaderFiles
    "src/main.h"
    "src/menu.h"
    "src/pxx.h"
    "src/licenses.h")

# Add source to this project's executable.
add_executable(${PROJECT_NAME} ${SourceFiles})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        ${tanja84dk_crypt_BINARY_DIR}/include
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        ${WERROR_FLAG}
        ${PEDANTIC_COMPILE_FLAGS}
)


target_compile_features(${PROJECT_NAME}
    PRIVATE
        cxx_std_17
)

target_link_libraries(${PROJECT_NAME} PRIVATE Tanja84dk::tools Tanja84dk::crypt fmt::fmt)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        CXX_STANDARD 17
        VERSION ${${PROJECT_NAME}_VERSION}
        SOVERSION ${${PROJECT_NAME}_VERSION_MAJOR}
)

if(NOT CMAKE_BUILD_TYPE STREQUAL Release)
    if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR OR ArgTools_BUILD_TESTING STREQUAL ON)
        enable_testing()
        add_subdirectory(test)
    endif()
endif()