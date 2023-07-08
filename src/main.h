#pragma once

#include "pxx.h"
#include <string>
#include <Tanja84dk/tools/tools.h>
#include "caesarChipher.h"
#include "wrapperBase32.h"
#include "wrapperBase64.h"
#include "wrapperBinary.h"
#include <ArgToolsConfig.h>

void sub_menu_base32(void);
void sub_menu_base64(void);
void sub_menu_8bit(void);
void sub_menu_about() noexcept;
void main_menu(void);
void print_license(std::string &project_name, std::string &license_macro);
