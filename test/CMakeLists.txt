

find_package(Catch2 3 REQUIRED)
find_package(tanja84dk_crypt REQUIRED)
find_package(tanja84dk_tools REQUIRED)
# These tests can use the Catch2-provided main
add_executable(${PROJECT_NAME}_Test src/main.cpp)
target_link_libraries(${PROJECT_NAME}_Test PRIVATE Catch2::Catch2WithMain Tanja84dk::crypt)
target_include_directories(${PROJECT_NAME}_Test PRIVATE ${tanja84dk_tools_BINARY_DIR}/include)

include(CTest)

# These tests need their own main
#add_executable(custom-main-tests test.cpp test-main.cpp)
#target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)
