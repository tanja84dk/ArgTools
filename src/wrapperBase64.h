#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>

#include <base64.h>

namespace Tanja84dk::crypt::base64
{
    std::string decode(const std::string &input_data) noexcept;
    std::string encode(const std::string &input_data) noexcept;
}
