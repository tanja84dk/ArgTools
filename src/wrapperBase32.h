#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>
#include <Base64/Base32.hpp>

namespace chipher::base32
{

    void myBase32Encoding(void);
    void myBase32Encoding(const std::string &data);
    void myBase32Decoding(void);
    void myBase32Decoding(const std::string &data);
    void myBase32DecodingString(void);

}
