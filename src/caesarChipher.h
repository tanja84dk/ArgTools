#pragma once
#include "pxx.h"
#include <Tools/Tools.h>

void caesarEncoding(const int keyValue, const std::string &inputData);
void ceasarDecoding(const int keyValue, const std::string &inputData);

void ceasarDecodingBruteforce(const std::string &data);