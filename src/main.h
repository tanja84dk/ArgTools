#ifndef TANJA84DK_ARGTOOLS_MAIN_H_PRIVATE
#define TANJA84DK_ARGTOOLS_MAIN_H_PRIVATE

#include <string>

#include "pxx.h"

void sub_menu_base32(void);
void sub_menu_base64(void);
void sub_menu_8bit(void);
void sub_menu_about() noexcept;
void main_menu(void);
void print_license(std::string &project_name, std::string &license_macro);

#endif  // TANJA84DK_ARGTOOLS_MAIN_H_PRIVATE
