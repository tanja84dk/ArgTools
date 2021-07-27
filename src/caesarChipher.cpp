#include "caesarChipher.h"

void caesarEncoding(const uint_fast8_t keyValue, const std::string &inputData)
{

    std::string outputData = "";
    std::string outputFilename = "";
    uint_fast8_t charTemp;

    for ( uint_fast64_t i = 0; i != inputData.length(); i++ )
    {
        charTemp = (uint_fast8_t(inputData[i]) + keyValue);
        if ( uint_fast8_t(inputData[i] >= 'A' && uint_fast8_t(inputData[i]) <= 'Z' ) )
        {
            if ( charTemp > uint_fast8_t('Z') )
            {
                charTemp = charTemp - uint_fast8_t('Z') + (uint_fast8_t('A') - 1);
            }
        } else if ( uint_fast8_t(inputData[i] >= 'a' && uint_fast8_t(inputData[i]) <= 'z' ) ) {
            if ( charTemp > uint_fast8_t('z') )
            {
                charTemp = charTemp - uint_fast8_t('z') + (uint_fast8_t('a') - 1);
            }
        } else {
            charTemp = uint_fast8_t(inputData[i]);
        }
        outputData += char(charTemp);
    }

    std::cout << outputData << std::endl;

    #ifdef WriteFile
    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-CeasarChipher.txt";

    if ( Tools::doesFileExist(outputFilename) == false )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
    #endif
};

void ceasarDecoding(const uint_fast8_t keyValue, const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;

    uint8_t charTemp;

    for ( uint_fast64_t i = 0; i != inputData.length(); i++ )
    {
        charTemp = uint_least8_t(inputData[i]) - keyValue;
        if ( uint8_t(inputData[i]) >= 'a' && uint8_t(inputData[i]) <= 'z' )
        {
            if (charTemp > uint8_t('z') )
            {
                charTemp = charTemp + 'z' - 'a' + 1;
            }
        } else if ( uint8_t(inputData[i]) >= 'A' && uint8_t(inputData[i]) <= 'Z' ) {
            if (charTemp > uint8_t('Z') )
            {
                charTemp = charTemp + 'Z' - 'A' + 1;
            }
        } else {
            charTemp = uint8_t(inputData[i]);
        }
        outputData += char(charTemp);
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
        printf("Key Test: %d\n%lu\n", keyValue, inputData.length());

        uint8_t spaceCounter = 0;
        std::string outputData;
        uint8_t charTemp;

        for ( uint64_t i = 0; i != inputData.length() && spaceCounter != 3; i++ )
        {
            charTemp = uint8_t(inputData[i]) - keyValue;
            if (uint8_t(inputData[i]) >= 'A' && uint8_t(inputData[i]) <= 'Z' )
            {
                if ( charTemp > uint8_t('Z') )
                {
                    charTemp = charTemp - uint8_t('A') + uint8_t('Z') + 1;
                }
            }else if (charTemp > uint8_t('z')) {
                charTemp = charTemp +- uint8_t('a') + uint8_t('z') + 1;
            } else {
                charTemp = inputData[i];
                if (char(charTemp) == ' ')
                {
                    spaceCounter += 1;
                }
            }
            outputData += char(charTemp);
        }
        printf("\n%s\n", outputData.c_str());
    }
}