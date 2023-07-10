#include "wrapperBinary.h"

void chipher::binary::encoding(void) {
    std::string inputFilename;
    std::string outputFilename;
    std::string inputDataBuffer;
    std::string outputData;
    std::vector<std::bitset<8>> binaryOutputVector;
    binaryOutputVector.reserve(100);

    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::cout << std::endl;

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Binary-Encoded.txt";

    if (Tanja84dk::tools::file_exists(inputFilename)) {
        std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        inputDataBuffer.reserve(inputFileHandler.tellg());
        inputFileHandler.seekg(0, std::ios::beg);
        inputDataBuffer.assign((std::istreambuf_iterator<char>(inputFileHandler)), std::istreambuf_iterator<char>());

        for (std::size_t i = 0; i < inputDataBuffer.size(); i++) {
            binaryOutputVector.push_back(std::bitset<8>(inputDataBuffer.c_str()[i]));
        }

        // Printing the vector to the console
        for (size_t i = 0; i < binaryOutputVector.size(); i++) {
            std::cout << binaryOutputVector[i];
            if (i != binaryOutputVector.size() - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    if (!Tanja84dk::tools::file_exists(outputFilename)) {
        Tanja84dk::tools::write_file(binaryOutputVector, outputFilename);
        printf("The output is written to a file called %s in the folder you have the program in\n\n",
               outputFilename.c_str());
    }
}

void chipher::binary::encoding(const std::string &data) {
    std::vector<std::bitset<8>> binaryOutputVector;
    std::string outputFilename;

    for (std::size_t i = 0; i < int(data.size()); i++) {
        binaryOutputVector.push_back(std::bitset<8>(data.c_str()[i]));
    }

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-8Bit-Binary.txt";

    if (!Tanja84dk::tools::file_exists(outputFilename)) {
        Tanja84dk::tools::write_file(binaryOutputVector, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n",
               outputFilename.c_str());
    }
}

void chipher::binary::decoding_string(const std::string &inputFilename) {
    std::string outputFilename;
    std::string inputDataBuffer;
    std::string outputData;
    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Binary-Decoded.txt";

    if (Tanja84dk::tools::file_exists(inputFilename) == true) {
        std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        inputDataBuffer.reserve(inputFileHandler.tellg());
        inputFileHandler.seekg(0, std::ios::beg);
        inputDataBuffer.assign((std::istreambuf_iterator<char>(inputFileHandler)), std::istreambuf_iterator<char>());

        std::stringstream binaryStringStream(inputDataBuffer);

        while (binaryStringStream.good()) {
            std::bitset<8> bits;
            binaryStringStream >> bits;
            char characterDecoded = char(bits.to_ulong());
            outputData += characterDecoded;
        }

        printf("\n%s\n", outputData.c_str());
    }

    if (Tanja84dk::tools::file_exists(outputFilename) == false) {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n",
               outputFilename.c_str());
    }
}
