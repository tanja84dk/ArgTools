#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>

namespace chipher::ceasar
{

    void encoding(const int keyValue, const std::string &inputData);
    void decoding(const int keyValue, const std::string &inputData);

    void decoding_brute_force(const std::string &data);

}
