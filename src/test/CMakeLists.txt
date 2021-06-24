# CMakeLists.txt for Base64Tests
#
# © 2018 by Richard Walters

cmake_minimum_required(VERSION 3.5)
set(This ArgToolsTest)

set(Sources
    src/main.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

target_include_directories(${This} PRIVATE ..)

target_link_libraries(${This} PUBLIC
    Utf8
	Base64
	Tools
	gtest_main
    Base64
)

