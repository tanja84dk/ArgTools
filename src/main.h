#pragma once

#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <sstream>
#include <Base64/Base64.hpp>
#include <Tools/Tools.h>

void myBase64Encoding(void);
void myBase64Encoding(const std::string &data);
void myBase64Decoding(void);
void myBase64Decoding(const std::string &data);
void myBase64DecodingString(void);

void my8BitBinaryEncoding(void);
void my8BitBinaryEncoding(const std::string &data);
void my8BitBinaryDecoding(const std::string &inputFilename);
//std::string my8BitBinaryDecoding(const std::string &data);

void SubMenuBase64(void);
void SubMenu8bit(void);
void MainMenu(void);