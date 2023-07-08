#include "wrapperBase32.h"

#include <string>
#include <base32.h>


std::string Tanja84dk::crypt::base32::decode(const std::string &input_data) noexcept
{
    CryptoPP::Base32Decoder Decoder;
    std::string decoded_string;
    Decoder.Put((CryptoPP::byte *)input_data.data(), input_data.size());
    Decoder.MessageEnd();

    CryptoPP::word64 size_word64 = Decoder.MaxRetrievable();

    if (size_word64 && size_word64 <= SIZE_MAX)
    {
        decoded_string.resize(size_word64);
        Decoder.Get((CryptoPP::byte *)&decoded_string[0], decoded_string.size());
    }
    return decoded_string;
}

std::string Tanja84dk::crypt::base32::encode(const std::string &input_data) noexcept
{
    CryptoPP::Base32Encoder Encoder;
    std::string encoded_string = {};
    Encoder.Put((CryptoPP::byte *)input_data.data(), input_data.size());
    Encoder.MessageEnd();

    CryptoPP::word64 size_word64 = Encoder.MaxRetrievable();
    if (size_word64)
    {
        encoded_string.resize(size_word64);
        Encoder.Get((CryptoPP::byte *)&encoded_string[0], encoded_string.size());
    }

    return encoded_string;
}

std::string Tanja84dk::crypt::base32hex::decode(const std::string &input_data) noexcept
{
    CryptoPP::Base32HexDecoder Decoder;
    std::string decoded_string;
    Decoder.Put((CryptoPP::byte *)input_data.data(), input_data.size());
    Decoder.MessageEnd();

    CryptoPP::word64 size_word64 = Decoder.MaxRetrievable();

    if (size_word64 && size_word64 <= SIZE_MAX)
    {
        decoded_string.resize(size_word64);
        Decoder.Get((CryptoPP::byte *)&decoded_string[0], decoded_string.size());
    }
    return decoded_string;
}

std::string Tanja84dk::crypt::base32hex::encode(const std::string &input_data) noexcept
{
    CryptoPP::Base32HexEncoder Encoder;
    std::string encoded_string = {};
    Encoder.Put((CryptoPP::byte *)input_data.data(), input_data.size());
    Encoder.MessageEnd();

    CryptoPP::word64 size_word64 = Encoder.MaxRetrievable();
    if (size_word64)
    {
        encoded_string.resize(size_word64);
        Encoder.Get((CryptoPP::byte *)&encoded_string[0], encoded_string.size());
    }

    return encoded_string;
}
