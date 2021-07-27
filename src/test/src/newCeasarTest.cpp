#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <sstream>

void ceasarEncode(uint_fast8_t key, std::string inputData)
{
    std::string outputData;
    uint_fast8_t charTemp;
    for ( uint_fast64_t i = 0; i != inputData.length(); i++ )
    {
        charTemp = (uint_fast8_t(inputData[i]) + key);
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
    };
    std::cout << outputData;
};

int main()
{
    ceasarEncode(10, "Look at me still talking when there's Science to do");

    return EXIT_SUCCESS;
}