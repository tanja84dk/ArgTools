#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>

namespace chipher::ceasar
{

    void encoding(const int chipher_shift_key, const std::string &input_data);
    void decoding(const int chipher_shift_key, const std::string &input_data);

    void decoding_brute_force(const std::string &input_data);

}
