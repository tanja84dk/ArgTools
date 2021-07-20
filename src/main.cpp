#include "main.h"
#include "pxx.h"
#include <ArgToolsConfig.h>

void myBase32Decoding(void)
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
    
    outputData = Base32::Decode((inputData));

    // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
    // Falling back to cout until issue is located
    std::cout << outputData << std::endl;
    
    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Decoded-Base32.txt";
    if ( !Tools::doesFileExist(outputFilename) )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}

void myBase32Decoding(const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;
    outputData = Base32::Decode(inputData);

    printf( "\n%s\n", outputData.c_str() );

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
    outStatusCode = Tools::doesFileExist(outputFilename);
        if (outStatusCode == false) {
            Tools::writeFile(outputData, outputFilename);
            printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    };
};

void myBase32Encoding(void)
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

    outputData = Base32::Encode(inputData);

    printf( "\n%s\n", outputData.c_str() );

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Encoded-Base32.txt";
    if (Tools::doesFileExist(outputFilename) == false) {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
};

void myBase32Encoding(const std::string &data)
{
    bool statusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base32::Encode((data));

    printf( "\n%s\n", outputData.c_str() );

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-Base32.txt";
    statusCode = Tools::doesFileExist(outputFilename);
    if (statusCode == false) {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
}

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

void my8BitBinaryEncoding(void)
{

    std::string inputFilename;
    std::string outputFilename;
    std::string inputDataBuffer;
    std::string outputData;
    std::vector<std::bitset<8>> binaryOutputVector;
    binaryOutputVector.reserve(100);

    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::cout << std::endl;

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Binary-Encoded.txt";

    if ( Tools::doesFileExist(inputFilename) )
    {
        std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        inputDataBuffer.reserve(inputFileHandler.tellg());
        inputFileHandler.seekg(0, std::ios::beg);
        inputDataBuffer.assign((std::istreambuf_iterator<char>(inputFileHandler)),
                                std::istreambuf_iterator<char>());
        

        for ( std::size_t i = 0; i < inputDataBuffer.size(); i++ )
        {
            binaryOutputVector.push_back(std::bitset<8>(inputDataBuffer.c_str()[i]));

        }

        // Printing the vector to the console
        for ( size_t i = 0; i < binaryOutputVector.size(); i++ )
        {
            std::cout << binaryOutputVector[i];
            if ( i != binaryOutputVector.size() - 1 )
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    if ( !Tools::doesFileExist(outputFilename) )
    {
        Tools::writeFile(binaryOutputVector, outputFilename);
        printf( "The output is written to a file called %s in the folder you have the program in\n\n", outputFilename.c_str() );
    }

}

void my8BitBinaryEncoding(const std::string &data)
{
    std::vector<std::bitset<8>> binaryOutputVector;
    std::string outputFilename;

    for (std::size_t i = 0; i < int(data.size()); i++ )
    {
        binaryOutputVector.push_back(std::bitset<8>(data.c_str()[i]));
    }

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-8Bit-Binary.txt";

    if ( !Tools::doesFileExist(outputFilename) )
    {
        Tools::writeFile(binaryOutputVector, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }
    
}

void my8BitBinaryDecodingString(const std::string &inputFilename)
{

    std::string outputFilename;
    std::string inputDataBuffer;
    std::string outputData;
    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Binary-Decoded.txt";

    if ( Tools::doesFileExist(inputFilename) == true )
    {
        std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        inputDataBuffer.reserve(inputFileHandler.tellg());
        inputFileHandler.seekg(0, std::ios::beg);
        inputDataBuffer.assign((std::istreambuf_iterator<char>(inputFileHandler)),
                                std::istreambuf_iterator<char>());
        
        std::stringstream binaryStringStream(inputDataBuffer);

        while (binaryStringStream.good())
        {
            std::bitset<8> bits;
            binaryStringStream >> bits;
            char characterDecoded = char(bits.to_ulong());
            outputData += characterDecoded;
        }

        printf( "\n%s\n", outputData.c_str() );
    }
    

    if ( Tools::doesFileExist(outputFilename) == false )
    {
        Tools::writeFile(outputData, outputFilename);
        printf( "The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str() );
    }

}

void subMenuBase32(void)
{
    std::string inputString;
    bool _exitBase32 = false;
    while (_exitBase32 == false)
    {
        short unsigned int menuChoice;

        printf("----------------------------\n"
               "      Base32\n"
               "----------------------------\n"
               "[1] Encoding From File\n"
               "[2] Decoding From File\n"
               "[3] Encoding From String\n"
               "[4] Decoding From String\n"
               "[0] Back To Main Menu\n"
               "----------------------------\n"
               "Enter your choice: ");
        std::cin >> menuChoice;
        std::cout << std::endl;


        switch (menuChoice)
        {
        case 1:
            //Encoding Base64 From File
            printf("You chose Encoding From File\n");
            myBase32Encoding();
            _exitBase32 = true;
            break;
        case 2:
            //Decoding Base64 From File
            printf("You chose Decoding From File\n");
            myBase32Decoding();
            _exitBase32 = true;
            break;
        case 3:
            //Encoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, inputString);
            myBase32Encoding(inputString);
            _exitBase32 = true;
            break;
        case 4:
            //Decoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, inputString);
            myBase32Decoding(inputString);
            _exitBase32 = true;
            break;
        case 0:
            _exitBase32 = true;
        default:
            printf("The option %d does not exist\n"
                   "Redirecting to main menu\n\n", menuChoice);
            _exitBase32 = true;
            break;
        }

    }
}

void SubMenuBase64(void)
{
    std::string inputString;
    bool _exitBase64 = false;
    while (_exitBase64 == false)
    {
        short unsigned int menuChoice;

        printf("----------------------------\n"
               "      Base64   \n"
               "----------------------------\n"
               "[1] Encoding From File\n"
               "[2] Decoding From File\n"
               "[3] Encoding From String\n"
               "[4] Decoding From String\n"
               "[0] Back To Main Menu\n"
               "----------------------------\n"
               "Enter your choice: ");
        std::cin >> menuChoice;
        std::cout << std::endl;


        switch (menuChoice)
        {
        case 1:
            //Encoding Base64 From File
            printf("You chose Encoding From File\n");
            myBase64Encoding();
            _exitBase64 = true;
            break;
        case 2:
            //Decoding Base64 From File
            printf("You chose Decoding From File\n");
            myBase64Decoding();
            _exitBase64 = true;
            break;
        case 3:
            //Encoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, inputString);
            myBase64Encoding(inputString);
            _exitBase64 = true;
            break;
        case 4:
            //Decoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, inputString);
            myBase64Decoding(inputString);
            _exitBase64 = true;
            break;
        case 0:
            _exitBase64 = true;
        default:
            printf("The option %d does not exist\n"
                   "Redirecting to main menu\n\n", menuChoice);
            _exitBase64 = true;
            break;
        }

    }
}

void SubMenu8bit(void)
{
    std::string inputString;
    bool exitBinaryMenu = false;
    while (exitBinaryMenu == false)
    {
        short unsigned int menuChoice;

        printf("----------------------------\n"
               "      8 bit Binary          \n"
               "----------------------------\n"
               "[1] Encoding From File\n"
               "[2] Decoding From File\n"
               "[3] Encoding From String\n"
               "[0] Back To Main Menu\n"
               "----------------------------\n"
               "Enter your choice: ");
        std::cin >> menuChoice;
        std::cout << std::endl;

        switch (menuChoice)
        {
        case 1:
            //Encoding Binary From File
            std::cout << "You chose Encoding From File" << std::endl;
            //std::cout << "Enter filename: ";
            //std::getline(std::cin >> std::ws, inputString);
            my8BitBinaryEncoding();
            exitBinaryMenu = true;
            break;
        case 2:
            //Decoding Binary From File
            printf("Enter the filename: ");
            std::getline(std::cin >> std::ws, inputString);
            std::cout << std::endl;
            my8BitBinaryDecodingString(inputString);
            exitBinaryMenu = true;
            break;
        case 3:
            //Encoding Binary From String
            std::cout << "Enter the string: ";
            std::getline(std::cin >> std::ws, inputString);
            std::cout << std::endl;
            my8BitBinaryEncoding(inputString);
            exitBinaryMenu = true;
            break;
        case 4:
            //Decoding Binary From String
            //std::cout << "Enter the string: ";
            //std::getline(std::cin >> std::ws, inputString);
            //my8BitBinaryDecoding(inputString);
            //exitBinaryMenu = true;
            break;
        case 0:
            exitBinaryMenu = true;
            break;
        default:
            printf("The option %d does not exist\n"
                   "Redirecting to main menu\n", menuChoice);
            exitBinaryMenu = true;
            break;
        }

    }
}

void MainMenu(void)
{
    std::string inputFile;
    while (1)
    {
        short unsigned int menuChoice;
        printf("----------------------------\n"
               "      Main Menu             \n"
               "----------------------------\n"
               "[1] Base32\n"
               "[2] Base64\n"
               "[3] 8Bit Binary\n"
               "[6] Test Print File\n"
               "[0] Exit\n"
               "----------------------------\n"
               "Enter your choice: ");

        std::cin >> menuChoice;
        std::cout << std::endl;

        switch (menuChoice)
        {
        case 1:
            subMenuBase32();
            break;
        case 2:
            SubMenuBase64();
            break;
        case 3:
            SubMenu8bit();
            break;
        case 6:
            printf("Enter The Filename: ");
            std::getline(std::cin >> std::ws, inputFile);
            Tools::printFile(inputFile);
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }

}

int main(int argc, char** argv)
{
    std::cout << argv[0] << std::endl;
    printf("This is Version %d.%d-dev\n", ArgTools_VERSION_MAJOR, ArgTools_VERSION_MINOR);
    MainMenu();

    return 0;
}
