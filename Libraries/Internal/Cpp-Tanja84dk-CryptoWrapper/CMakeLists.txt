# CMakeLists.txt for CryptoWrapper Collection
#
# © 2021 by Tanja84DK

cmake_minimum_required(VERSION 3.8)

set(This CryptoWrapper)

set(Headers
    include/CryptoWrapper/CryptoWrapper.h
)

set(Sources
    src/CryptoWrapper.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC include)

if(DEFINED ENABLE_TEST)
    add_subdirectory(test)
endif(DEFINED ENABLE_TEST)