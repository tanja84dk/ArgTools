#include "wrapperBinary.h"

#include <fmt/core.h>

#include <string>
void chipher::binary::encoding(void) {
    std::string input_filename = {};
    std::string output_filename = {};
    std::string input_data_buffer = {};
    std::string output_data = {};
    std::vector<std::bitset<8>> binary_output_vector = {};
    binary_output_vector.reserve(100);

    fmt::print("Enter Filename: ");
    std::getline(std::cin >> std::ws, input_filename);
    std::cout << std::endl;

    output_filename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + input_filename + "-Binary-Encoded.txt";

    if (Tanja84dk::tools::file_exist(input_filename)) {
        std::ifstream inputFileHandler(input_filename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        input_data_buffer.reserve(static_cast<std::size_t>(inputFileHandler.tellg()));
        inputFileHandler.seekg(0, std::ios::beg);
        input_data_buffer.assign((std::istreambuf_iterator<char>(inputFileHandler)), std::istreambuf_iterator<char>());

        for (std::size_t i = 0; i < input_data_buffer.size(); i++) {
            binary_output_vector.push_back(std::bitset<8>(input_data_buffer.c_str()[i]));
        }

        // Printing the vector to the console
        for (size_t i = 0; i < binary_output_vector.size(); i++) {
            std::cout << binary_output_vector[i];
            if (i != binary_output_vector.size() - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    if (!Tanja84dk::tools::file_exist(output_filename)) {
        Tanja84dk::tools::write_file(binary_output_vector, output_filename);
        fmt::print("The output is written to a file called {} in the folder you have the program in\n\n",
                   output_filename);
    }
}

void chipher::binary::encoding([[maybe_unused]] const std::string &data) {
    std::vector<std::bitset<8>> binaryOutputVector = {};
    std::string outputFilename = {};

    for (std::size_t i = 0; i < data.size(); i++) {
        std::bitset<8> temporary_bitset_data(data.c_str()[i]);
        binaryOutputVector.push_back(temporary_bitset_data);
        // binaryOutputVector.push_back(std::bitset<8>((char)data.c_str()[i]));
    }

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-8Bit-Binary.txt";

    if (!Tanja84dk::tools::file_exist(outputFilename)) {
        // Tanja84dk::tools::write_file(binaryOutputVector, outputFilename);
        fmt::print("The output is also written to a file called {} in the folder you have the program in\n",
                   outputFilename);
    }
}

void chipher::binary::decoding_string(const std::string &inputFilename) {
    std::string output_filename;
    std::string inputDataBuffer;
    std::string outputData;
    output_filename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Binary-Decoded.txt";

    if (Tanja84dk::tools::file_exist(inputFilename) == true) {
        std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        inputDataBuffer.reserve(static_cast<std::size_t>(inputFileHandler.tellg()));
        inputFileHandler.seekg(0, std::ios::beg);
        inputDataBuffer.assign((std::istreambuf_iterator<char>(inputFileHandler)), std::istreambuf_iterator<char>());

        std::stringstream binaryStringStream(inputDataBuffer);

        while (binaryStringStream.good()) {
            std::bitset<8> bits;
            binaryStringStream >> bits;
            char characterDecoded = char(bits.to_ulong());
            outputData += characterDecoded;
        }

        fmt::print("\n{}\n", outputData);
    }

    if (Tanja84dk::tools::file_exist(output_filename) == false) {
        Tanja84dk::tools::write_file(outputData, output_filename);
        fmt::print("The output is also written to a file called {} in the folder you have the program in\n",
                   output_filename);
    }
}
