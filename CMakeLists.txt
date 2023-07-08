# CMakeList.txt : CMake project for ArgTools, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.16)

project ("ArgTools" VERSION 0.3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(cmake/Tanja84dkWarnings.cmake)

find_package(CPM REQUIRED)
find_package(Tanja84dkTools REQUIRED)
find_package(tanja84dk_crypt REQUIRED)

include(cmake/get_licenses.cmake)

configure_file(${PROJECT_NAME}Config.h.in include/${PROJECT_NAME}Config.h)

set(SourceFiles
    "src/main.cpp"
    "src/caesarChipher.cpp"
    "src/wrapperBinary.cpp")

set(HeaderFiles
    "src/main.h"
    "src/pxx.h"
    "src/licenses.h"
    "src/caesarChipher.h"
    "src/wrapperBinary.h")

# Add source to this project's executable.
add_executable(${PROJECT_NAME} ${SourceFiles})

target_link_libraries(${PROJECT_NAME} Tanja84dk::tools Tanja84dk::crypt)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_BINARY_DIR}/include
        ${tanja84dk_crypt_BINARY_DIR}/include)

if(DEFINED ENABLE_TEST)
    enable_testing()
    add_subdirectory(src/test)
endif(DEFINED ENABLE_TEST)
