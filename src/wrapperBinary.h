#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>

namespace chipher::binary
{
    void encoding(void);
    void encoding(const std::string &data);
    void decoding_string(const std::string &inputFilename);
}
