#pragma once
#include "pxx.h"
#include <Tools/Tools.h>

void caesarEncoding(const uint_fast8_t keyValue, const std::string &inputData);
void ceasarDecoding(const uint_fast8_t keyValue, const std::string &inputData);

void ceasarDecodingBruteforce(const std::string &data);