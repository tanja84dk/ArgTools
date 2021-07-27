#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <fstream>
#include <streambuf>
#include <algorithm>
#include <sstream>
#include <Tools/Tools.h>

std::string ceasarEncode(uint8_t key, std::string data)
{
    std::string outputData;
    uint8_t charTemp;
    for ( uint64_t i = 0; i != data.length(); i++ )
    {
        charTemp = (uint8_t(data[i]) + key);
        if ( uint8_t(data[i] >= 'A' && uint8_t(data[i]) <= 'Z' ) )
        {
            if ( charTemp > uint8_t('Z') )
            {
                charTemp = charTemp - uint8_t('Z') + (uint8_t('A') - 1);
            }
        } else if ( uint8_t(data[i] >= 'a' && uint8_t(data[i]) <= 'z' ) ) {
            if ( charTemp > uint8_t('z') )
            {
                charTemp = charTemp - uint8_t('z') + (uint8_t('a') - 1);
            }
        } else {
            charTemp = uint8_t(data[i]);
        }
        outputData += char(charTemp);
    };
    return outputData;
};

int main()
{
    std::cout << (ceasarEncode(10, "Look at me still talking when there's Science to do")) << std::endl;

    return EXIT_SUCCESS;
}