#pragma once
#include "pxx.h"

void caesarEncoding(const int keyValue, const std::string &inputData);
void ceasarDecoding(const int keyValue, const std::string &inputData);

void ceasarDecodingBruteforce(const std::string &data);