#pragma once
#include "pxx.h"
#include <Tools/Tools.h>
#include <Base64/Base32.hpp>

void myBase32Encoding(void);
void myBase32Encoding(const std::string &data);
void myBase32Decoding(void);
void myBase32Decoding(const std::string &data);
void myBase32DecodingString(void);