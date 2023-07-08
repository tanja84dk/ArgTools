#pragma once
#include "pxx.h"
#include <Tanja84dk/tools/tools.h>
#include <base32.h>

namespace Tanja84dk::crypt::base32
{
    std::string decode(const std::string &input_data) noexcept;
    std::string encode(const std::string &input_data) noexcept;
}

namespace Tanja84dk::crypt::base32hex
{
    std::string decode(const std::string &input_data) noexcept;
    std::string encode(const std::string &input_data) noexcept;
}
