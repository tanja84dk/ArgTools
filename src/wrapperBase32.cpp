#include "wrapperBase32.h"

void myBase32Decoding(void)
{
    std::string inputFilename;
    std::string outputFilename;
    std::string outputData;

    printf("Enter the filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::cout << std::endl;

    if ( Tools::doesFileExist(inputFilename) )
    {
        outputData = Base32::Decode(Tools::readFile(inputFilename));

        // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
        // Falling back to cout until issue is located
        std::cout << outputData << std::endl;
    
        outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Decoded-Base32.txt";
        
        if ( !Tools::doesFileExist(outputFilename) )
        {
            Tools::writeFile(outputData, outputFilename);
            printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
        };
    };
}

void myBase32Decoding(const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;
    outputData = Base32::Decode(inputData);

    // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
    // Falling back to cout until issue is located
    std::cout << outputData << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-Base32.txt";

    if ( Tools::doesFileExist(outputFilename) == false )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}

void myBase32DecodingString(void)
{
    printf("Enter the string");
    std::string inputData;
    std::getline(std::cin >> std::ws, inputData);
    int outStatusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base32::Decode(inputData);

    // Could not get printf to work with the Base32 decoding, guess its a incoding issue.
    // Falling back to cout until issue is located    
    std::cout << std::endl << outputData << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-From_String-Decoded-Base32.txt";

    if ( !Tools::doesFileExist(outputFilename) )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    };
};

void myBase32Encoding(void)
{
    std::string inputFilename;
    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::string outputData;
    std::string outputFilename;

    if ( Tools::doesFileExist(inputFilename) )
    {
        outputData = Base32::Encode(Tools::readFile(inputFilename));

        // Could not get printf to work with the Base32 decoding, guess its a incoding issue.
        // Falling back to cout until issue is located    
        std::cout << std::endl << outputData << std::endl;

        outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Encoded-Base32.txt";

        if ( !Tools::doesFileExist(outputFilename) ) {
            Tools::writeFile(outputData, outputFilename);
            printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
        }
    }
};

void myBase32Encoding(const std::string &data)
{
    bool statusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base32::Encode((data));

    // Could not get printf to work with the Base32 decoding, guess its a incoding issue.
    // Falling back to cout until issue is located    
    std::cout << std::endl << outputData << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-Base32.txt";

    if ( !Tools::doesFileExist(outputFilename) )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}
