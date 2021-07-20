#pragma once

#include "pxx.h"
#include <Base64/Base32.hpp>
#include <Base64/Base64.hpp>
#include <Tools/Tools.h>

void myBase32Encoding(void);
void myBase32Encoding(const std::string &data);
void myBase32Decoding(void);
void myBase32Decoding(const std::string &data);
void myBase32DecodingString(void);

void myBase64Encoding(void);
void myBase64Encoding(const std::string &data);
void myBase64Decoding(void);
void myBase64Decoding(const std::string &data);
void myBase64DecodingString(void);

void my8BitBinaryEncoding(void);
void my8BitBinaryEncoding(const std::string &data);
void my8BitBinaryDecodingString(const std::string &inputFilename);

void subMenuBase32(void);
void SubMenuBase64(void);
void SubMenu8bit(void);
void MainMenu(void);