# CMakeList.txt : CMake project for ArgTools, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.8)

project ("ArgTools" VERSION 0.3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

# Add source to this project's executable.
add_executable(${PROJECT_NAME} "src/main.cpp" "src/main.h" "src/pxx.h")

target_link_libraries(${PROJECT_NAME} "Base64" "Tools" "Utf8")

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE -s)

add_subdirectory(Libraries/Internal/Tools)
add_subdirectory(Libraries/External/Base64)
add_subdirectory(Libraries/External/Utf8)
add_subdirectory(Libraries/External/googletest)

#target_link_libraries(Include/Base64/Base64 LINK_PUBLIC ${PROJECT_NAME})
# TODO: Add tests and install targets if needed.
if(DEFINED ENABLE_TEST)
    add_subdirectory(src/test)
endif(DEFINED ENABLE_TEST)