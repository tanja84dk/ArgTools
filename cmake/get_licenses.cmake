file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE ArgTools_LICENSE)
string(PREPEND ArgTools_LICENSE "R\"(")
string(APPEND ArgTools_LICENSE ")\"")

file(STRINGS ${Tanja84dkTools_SOURCE_DIR}/LICENSE tanja84dk_tools_LICENSE)
string(PREPEND tanja84dk_tools_LICENSE "R\"(")
string(APPEND tanja84dk_tools_LICENSE ")\"")

file(STRINGS ${cryptopp-cmake_SOURCE_DIR}/LICENSE cryptopp_cmake_LICENSE)
string(PREPEND cryptopp_cmake_LICENSE "R\"(")
string(APPEND cryptopp_cmake_LICENSE ")\"")

file(STRINGS ${cryptopp-cmake_BINARY_DIR}/cryptopp/License.txt cryptopp_LICENSE)
string(PREPEND cryptopp_LICENSE "R\"(")
string(APPEND cryptopp_LICENSE ")\"")
