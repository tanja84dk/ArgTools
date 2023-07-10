#ifndef TANJA84DK_ARGTOOLS_LICENSES_H
#define TANJA84DK_ARGTOOLS_LICENSES_H
#include <ArgTools_licenses_macro.h>
#include <Tanja84dk/crypt/licenses.h>

#include <string>

namespace Tanja84dk {
namespace argtools {
namespace license {
namespace {
void print_title_for_licenses(const std::string &title) {
    printf(
        "---------------------------\n"
        "    %s\n"
        "---------------------------\n",
        title.c_str());
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
    printf("%s\n\n", get_argtools_license().c_str());

    print_title_for_licenses("tanja84dk_crypt");
    printf("%s\n\n", get_tanja84dk_crypt_license().c_str());

    print_title_for_licenses("tanja84dk_tools");
    printf("%s\n\n", get_tanja84dk_tools_license().c_str());

    print_title_for_licenses("fmtlib");
    printf("%s\n\n", get_fmtlib_license().c_str());

    print_title_for_licenses("cryptopp-cmake");
    printf("%s\n\n", get_cryptopp_cmake_license().c_str());

    print_title_for_licenses("cryptopp");
    printf("%s\n\n", get_cryptopp_license().c_str());
}
}  // namespace license
}  // namespace argtools
}  // namespace Tanja84dk
#endif  // TANJA84DK_ARGTOOLS_LICENSES_H
