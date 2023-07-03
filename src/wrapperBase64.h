#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>
#include <Base64/Base64.hpp>

namespace chipher::base64
{

    void encoding(void);
    void encoding(const std::string &data);
    void decoding(void);
    void decoding(const std::string &data);
    void decoding_string(void);

}
