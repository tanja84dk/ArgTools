#include "wrapperBase64.h"
/*
void chipher::base64::decoding(void)
{
    std::string inputFilename;
    std::string outputFilename;
    std::string outputData;

    printf("Enter the filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::cout << std::endl;

    if (Tanja84dk::tools::file_exists(inputFilename))
    {
        outputData = Base64::Decode(Tanja84dk::tools::read_file(inputFilename));

        // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
        // Falling back to cout until issue is located
        std::cout << outputData << std::endl;

        outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Decoded-Base64.txt";
        if (!Tanja84dk::tools::file_exists(outputFilename))
        {
            Tanja84dk::tools::write_file(outputData, outputFilename);
            printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
        }
    };
}

void chipher::base64::decoding(const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;
    outputData = Base64::Decode(inputData);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}

void chipher::base64::decoding_string(void)
{
    printf("Enter the string");
    std::string inputData;
    std::getline(std::cin >> std::ws, inputData);
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Decode(inputData);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-From_String-Decoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    };
};

void chipher::base64::encoding(void)
{
    std::string inputFilename;
    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Encode(Tanja84dk::tools::read_file(inputFilename));

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Encoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
};

void chipher::base64::encoding(const std::string &data)
{
    bool statusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Encode(data);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}
*/
std::string Tanja84dk::crypt::base64::decode(const std::string &input_data) noexcept
{
    CryptoPP::Base64Decoder Decoder;
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

std::string Tanja84dk::crypt::base64::encode(const std::string &input_data) noexcept
{
    CryptoPP::Base64Encoder Encoder;
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
