#pragma once

#include "pxx.h"
#include <string>

void sub_menu_base32(void);
void sub_menu_base64(void);
void sub_menu_8bit(void);
void sub_menu_about() noexcept;
void main_menu(void);
void print_license(std::string &project_name, std::string &license_macro);
