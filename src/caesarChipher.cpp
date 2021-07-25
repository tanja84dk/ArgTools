#include "caesarChipher.h"

void caesarEncoding(const int keyValue, const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;

    char charBuffer;
    for ( int i = 0; i != inputData.length(); i++ )
    {
        charBuffer = inputData[i];
        if ( charBuffer >= 'a' && charBuffer <= 'z')
        {
            charBuffer = charBuffer + keyValue;
            if ( charBuffer > 'z' )
            {
                charBuffer = charBuffer - 'z' + 'a' - 1;
            }
            outputData += charBuffer;
        } else if ( charBuffer >= 'A' && charBuffer <= 'Z' ) {
            charBuffer = charBuffer + keyValue;
            if ( charBuffer > 'Z' )
            {
                charBuffer = charBuffer - 'Z' + 'a' - 1;
            }
            outputData += charBuffer;
        } else {
            outputData += charBuffer;
        }

    }

    std::cout << outputData << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-CeasarChipher.txt";

    if ( Tools::doesFileExist(outputFilename) == false )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
};

void ceasarDecoding(const int keyValue, const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;

    char charBuffer;
    for ( int i = 0; i != inputData.length(); i++ )
    {        
        charBuffer = inputData[i];
        if (charBuffer >= 'a' && charBuffer <= 'z')
        {
            charBuffer = charBuffer - keyValue;
            if (charBuffer < 'a')
            {
                charBuffer = charBuffer + 'z' - 'a' + 1;
            }
            outputData += charBuffer;
        } else if (charBuffer >= 'A' && charBuffer <= 'Z'){
            charBuffer = charBuffer - keyValue;
            if (charBuffer < 'A')
            {
                charBuffer = charBuffer + 'Z' - 'A' + 1;
            }
            outputData += charBuffer;
        } else {
            outputData += charBuffer;
        }
    }

    std::cout << outputData << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-CeasarChipher.txt";

    if ( Tools::doesFileExist(outputFilename) == false )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
};

void ceasarDecodingBruteforce(const std::string &inputData)
{
    
    for ( int keyValue = 1; keyValue < 27; keyValue++ )
    {

        short unsigned int spaceCounter = 0;
        std::string outputData;
        char charBuffer;
        for ( int i = 0; i != inputData.length() && spaceCounter != 3; i++ )
        {        
            charBuffer = inputData[i];
            if (charBuffer >= 'a' && charBuffer <= 'z')
            {
                charBuffer = charBuffer - keyValue;
                if (charBuffer < 'a')
                {
                    charBuffer = charBuffer + 'z' - 'a' + 1;
                }
                outputData += charBuffer;
            } else if (charBuffer >= 'A' && charBuffer <= 'Z'){
                charBuffer = charBuffer - keyValue;
                if (charBuffer < 'A')
                {
                    charBuffer = charBuffer + 'Z' - 'A' + 1;
                }
                outputData += charBuffer;
            } else {
                if ( charBuffer == ' ')
                {
                    spaceCounter ++;
                    if (spaceCounter == 3)
                    {
                        std::cout << "Key Value " << keyValue << " and the data is: " << outputData << std::endl;
                    }
                }
                outputData += charBuffer;
            }
        }
    }
}