#ifndef TANJA84DK_ARGTOOLS_LICENSES_H_PRIVATE
#define TANJA84DK_ARGTOOLS_LICENSES_H_PRIVATE
#include <Tanja84dk/crypt/licenses.h>
#include <fmt/core.h>

#include <string>

#include "ArgTools_licenses_macro.h"
#include "pxx.h"

namespace Tanja84dk {
namespace argtools {
namespace license {
namespace {
void print_title_for_licenses(const std::string &title) {
    fmt::print(
        "---------------------------\n"
        "    {}\n"
        "---------------------------\n",
        title);
}

void replace_all(std::string &str, const std::string &from, const std::string &to) {
    if (from.empty()) return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
}  // namespace
std::string get_argtools_license() {
    std::string license = tanja84dk_argtools_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};

std::string get_tanja84dk_crypt_license() {
    std::string license = tanja84dk_crypt_LICENSE;
    replace_all(license, ";", "\n");
    return license;
}

std::string get_tanja84dk_tools_license() {
    std::string license = tanja84dk_tools_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};

std::string get_cryptopp_cmake_license() {
    std::string license = cryptopp_cmake_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};

std::string get_cryptopp_license() {
    std::string license = cryptopp_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};

std::string get_fmtlib_license() {
    std::string license = fmtlib_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};

void print_all_licenses() {
    print_title_for_licenses("ArgTools");
    fmt::print("{}\n\n", get_argtools_license());

    print_title_for_licenses("tanja84dk_crypt");
    fmt::print("{}\n\n", get_tanja84dk_crypt_license());

    print_title_for_licenses("tanja84dk_tools");
    fmt::print("{}\n\n", get_tanja84dk_tools_license());

    print_title_for_licenses("fmtlib");
    fmt::print("{}\n\n", get_fmtlib_license());

    print_title_for_licenses("cryptopp-cmake");
    fmt::print("{}\n\n", get_cryptopp_cmake_license());

    print_title_for_licenses("cryptopp");
    fmt::print("{}\n\n", get_cryptopp_license());
}
}  // namespace license
}  // namespace argtools
}  // namespace Tanja84dk
#endif  // TANJA84DK_ARGTOOLS_LICENSES_H_PRIVATE
