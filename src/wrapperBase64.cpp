#include "wrapperBase64.h"


void myBase64Decoding(void)
{
    std::string inputFilename;
    std::string inputData;
    std::string outputFilename;
    std::string outputData;

    printf("Enter the filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::cout << std::endl;

    if ( Tools::doesFileExist(inputFilename) )
    {
    std::ifstream inFileHandler(inputFilename, std::ifstream::in);
    inFileHandler.seekg(0, std::ios::end);
    inputData.reserve(inFileHandler.tellg());
    inFileHandler.seekg(0, std::ios::beg);
    inputData.assign((std::istreambuf_iterator<char>(inFileHandler)),
                                   std::istreambuf_iterator<char>());
    };
    
    outputData = Base64::Decode((inputData));

    // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
    // Falling back to cout until issue is located
    std::cout << outputData << std::endl;
    
    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Decoded-Base64.txt";
    if ( !Tools::doesFileExist(outputFilename) )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}

void myBase64Decoding(const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;
    outputData = Base64::Decode(inputData);

    printf( "\n%s\n", outputData.c_str() );

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-Base64.txt";
    if ( Tools::doesFileExist(outputFilename) == false )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}

void myBase64DecodingString(void)
{
    printf("Enter the string");
    std::string inputData;
    std::getline(std::cin >> std::ws, inputData);
    int outStatusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Decode(inputData);

    std::cout << std::endl << outputData << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-From_String-Decoded-Base64.txt";
    outStatusCode = Tools::doesFileExist(outputFilename);
        if (outStatusCode == false) {
            Tools::writeFile(outputData, outputFilename);
            printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    };
};

void myBase64Encoding(void)
{
    std::string inputFilename;
    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::string inputData;
    std::string outputData;
    std::string outputFilename;
    std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
    inputFileHandler.seekg(0, std::ios::end);
    inputData.reserve(inputFileHandler.tellg());
    inputFileHandler.seekg(0, std::ios::beg);
    inputData.assign((std::istreambuf_iterator<char>(inputFileHandler)),
                                   std::istreambuf_iterator<char>());

    outputData = Base64::Encode(inputData);

    printf( "\n%s\n", outputData.c_str() );

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Encoded-Base64.txt";
    if (Tools::doesFileExist(outputFilename) == false) {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
};

void myBase64Encoding(const std::string &data)
{
    bool statusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Encode((data));

    printf( "\n%s\n", outputData.c_str() );

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-Base64.txt";
    statusCode = Tools::doesFileExist(outputFilename);
    if (statusCode == false) {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}
