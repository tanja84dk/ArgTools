#include "main.h"
#include "pxx.h"
#include <ArgToolsConfig.h>

char timeBuffer[80];

std::string inputFile;
std::string myBase64Decoded;
#ifdef comment
std::string myBase64Decoding(const std::string &data)
{
    std::string outputData;
    myBase64Decoded = Base64::Decode(data);

    return myBase64Decoded;
}
#endif

void myBase64Decoding(void)
{
    std::string inFile;
    std::string inData;
    std::string dataTemp;
    std::string outFile;
    std::string outData;
    bool inFileCheck;
    bool outFileCheck;

    std::cout << "Enter the filename: ";
    std::getline(std::cin >> std::ws, inFile);
    inFileCheck = Tools::doesFileExist(inFile);
    if ( inFileCheck == true )
    {
    std::ifstream inFileHandler(inFile, std::ifstream::in);
    inFileHandler.seekg(0, std::ios::end);
    inData.reserve(inFileHandler.tellg());
    inFileHandler.seekg(0, std::ios::beg);
    inData.assign((std::istreambuf_iterator<char>(inFileHandler)),
                                   std::istreambuf_iterator<char>());
    };
    outData = Base64::Decode((inData));
    std::cout << std::endl << std::endl << outData << std::endl;
    outFile = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + inFile + "-Decoded-Base64.txt";
    outFileCheck = Tools::doesFileExist(outFile);
    if ( outFileCheck == false )
    {
        std::ofstream outFileHandler;
        outFileHandler.open(outFile);
        outFileHandler << outData;
        outFileHandler.close();
    }
}

void myBase64Decoding(const std::string &inputData)
{
    bool myBase64DecodingStatuscode;
    std::string myBase64DecodedOutput;
    std::string myBase64DecodedOutputFilename;
    myBase64DecodedOutput = Base64::Decode(inputData);

    myBase64DecodedOutputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-Base64.txt";
    myBase64DecodingStatuscode = Tools::doesFileExist(myBase64DecodedOutputFilename);
    if ( myBase64DecodingStatuscode == false )
    {
        std::ofstream myBase64DecodedOutputFile;
        myBase64DecodedOutputFile.open(myBase64DecodedOutputFilename);
        myBase64DecodedOutputFile << myBase64DecodedOutput;
        myBase64DecodedOutputFile.close();
        std::cout << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "The output is written to a file called "
                  << myBase64DecodedOutputFilename << " in the folder you have the program in"
                  << std::endl;
    }
}

void myBase64DecodingString(void)
{
    std::cout << "Enter the string" << std::endl;
    std::string __inputTemp;
    std::getline(std::cin >> std::ws, __inputTemp);
    int __myBase64DecodingStringStatusCode;
    std::string __myBase64DecodingStringTemp;
    std::string __myBase64DecodingStringOutput;
    std::string __myBase64DecodingStringOutputFilename;

    __myBase64DecodingStringOutput = Base64::Decode((__inputTemp));

    __myBase64DecodingStringOutputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-From_String-Decoded-Base64.txt";
    __myBase64DecodingStringStatusCode = Tools::doesFileExist(__myBase64DecodingStringOutputFilename);
        if (__myBase64DecodingStringStatusCode == 404) {
            std::ofstream __myBase64DecodingStringOutputFile;
            __myBase64DecodingStringOutputFile.open(__myBase64DecodingStringOutputFilename);
            __myBase64DecodingStringOutputFile << __myBase64DecodingStringOutput;
            __myBase64DecodingStringOutputFile.close();
            std::cout << "The output is also written to a file called " << __myBase64DecodingStringOutputFilename << " in the folder you have the program in" << std::endl;
    };
};

void myBase64Encoding(void)
{
    bool __myBase64EncodingStatus;
    std::string __myBase64Encoding;
    std::cout << "Enter Filename: "; std::getline(std::cin >> std::ws, __myBase64Encoding);
    std::string __myBase64EncodingTemp;
    std::string __myBase64EncodedOutput;
    std::string __myBase64EncodedOutputFilename;
    std::ifstream __myBase64EncodingFile(__myBase64Encoding, std::ifstream::in);
    __myBase64EncodingFile.seekg(0, std::ios::end);
    __myBase64EncodingTemp.reserve(__myBase64EncodingFile.tellg());
    __myBase64EncodingFile.seekg(0, std::ios::beg);
    __myBase64EncodingTemp.assign((std::istreambuf_iterator<char>(__myBase64EncodingFile)),
                                   std::istreambuf_iterator<char>());

    __myBase64EncodedOutput = Base64::Encode((__myBase64EncodingTemp));

    std::cout << std::endl << std::endl;

    std::cout << __myBase64EncodedOutput << std::endl << std::endl;

    __myBase64EncodedOutputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-" + __myBase64Encoding + "-Encoded-Base64.txt";
    __myBase64EncodingStatus = Tools::doesFileExist(__myBase64EncodedOutputFilename);
    if (__myBase64EncodingStatus == false) {
        std::ofstream __myBase64EncodedOutputFile;
        __myBase64EncodedOutputFile.open(__myBase64EncodedOutputFilename);
        __myBase64EncodedOutputFile << __myBase64EncodedOutput;
        __myBase64EncodedOutputFile.close();
        std::cout << "The output is also written to a file called " << __myBase64EncodedOutputFilename << " in the folder you have the program in" << std::endl;
    }
};

void myBase64Encoding(const std::string &data)
{
    bool __myBase64EncodingStatusCode;
    std::string __myBase64EncodedOutput;
    std::string __myBase64EncodedOutputFilename;

    __myBase64EncodedOutput = Base64::Encode((data));

    std::cout << __myBase64EncodedOutput << std::endl;

    __myBase64EncodedOutputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "Manual-Input-Encoded-Base64.txt";
    __myBase64EncodingStatusCode = Tools::doesFileExist(__myBase64EncodedOutputFilename);
    if (__myBase64EncodingStatusCode == false) {
        std::ofstream __myBase64EncodedOutputFile;
        __myBase64EncodedOutputFile.open(__myBase64EncodedOutputFilename);
        __myBase64EncodedOutputFile << __myBase64EncodedOutput;
        __myBase64EncodedOutputFile.close();
        std::cout << "The output is also written to a file called "
                  << __myBase64EncodedOutputFilename << " in the folder you have the program in"
                  << std::endl;
    }
}

void my8BitBinaryEncoding(void)
{

    bool inputFileStatusCode;
    bool outputFileStatusCode;

    std::string inputFilename;
    std::string outputFilename;
    std::string inputDataBuffer;
    std::string outputData;

    std::cout << "Enter Filename: "; std::getline(std::cin >> std::ws, inputFilename);

    inputFileStatusCode = Tools::doesFileExist(inputFilename);

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + inputFilename + "-Binary-Decoded.txt";
    outputFileStatusCode = Tools::doesFileExist(outputFilename);

    if ( inputFileStatusCode == true  && outputFileStatusCode == false )
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

        std::cout << std::endl << std::endl << outputData << std::endl;
    }

}

void my8BitBinaryEncoding(const std::string &data)
{
    bool outputFileStatusCode;
    std::vector<std::bitset<8>> binaryOutputVector;
    std::string outputFilename;

    for (std::size_t i = 0; i < int(data.size()); i++ )
    {
        binaryOutputVector.push_back(std::bitset<8>(data.c_str()[i]));
    }

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-8Bit-Binary.txt";
    outputFileStatusCode = Tools::doesFileExist(outputFilename);
    if ( outputFileStatusCode == false )
    {
        std::ofstream outputFileHandler;
        outputFileHandler.open(outputFilename);
        for ( int i = 0; i < binaryOutputVector.size(); i++ )
        {
            outputFileHandler << binaryOutputVector[i] << ' ';
        }
        outputFileHandler.close();

        std::cout << "The output is also written to a file called "
                  << outputFilename << " in the folder you have the program in"
                  << std::endl;
    }
    
}

void my8BitBinaryDecoding(const std::string &inputFilename)
{

    bool inputFileStatusCode;
    bool outputFileStatusCode;

    std::string outputFilename;
    std::string inputDataBuffer;
    std::string outputData;

    inputFileStatusCode = Tools::doesFileExist(inputFilename);

    outputFilename = Tools::createTimestamp("%Y%m%d_%H%M%S") + inputFilename + "-Binary-Decoded.txt";
    outputFileStatusCode = Tools::doesFileExist(outputFilename);

    if ( inputFileStatusCode == true  && outputFileStatusCode == false )
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

        std::ofstream outputFileHandler;
        outputFileHandler.open(outputFilename);
        outputFileHandler << outputData;
        outputFileHandler.close();

        std::cout << std::endl << outputData << std::endl << std::endl;

        std::cout << "The output is also written to a file called "
                  << outputFilename << " in the folder you have the program in"
                  << std::endl;
    }

}

void printFile(const std::string &inputfile)
{
    bool printFileStatusCode;
    printFileStatusCode = Tools::doesFileExist(inputFile);
    if (printFileStatusCode == true)
    {
        //cout << "Status Code: " << printFileStatusCode << ". The File Exist." << endl << "The Encoding String Goes Here" << endl;
        std::cout << std::endl << std::endl;
        std::ifstream fileHandler(inputFile, std::ifstream::in);
        if (fileHandler.is_open())
        {
            std::cout << fileHandler.rdbuf();
        };
        fileHandler.close();
    }
    else
    {
        std::cout << "Status Code: " << printFileStatusCode << ". The File Does Not Exist" << std::endl;
    }
};

void SubMenuBase64(void)
{
    std::string inputString;
    bool _exitBase64 = false;
    while (_exitBase64 == false)
    {
        short unsigned int menuChoice;

        std::cout << "----------------------------" << std::endl;
        std::cout << "      Base64   "              << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "[1] Encoding From File"       << std::endl;
        std::cout << "[2] Decoding From File"       << std::endl;
        std::cout << "[3] Encoding From String"     << std::endl;
        std::cout << "[4] Decoding From String"     << std::endl;
        std::cout << "[0] Back To Main Menu"        << std::endl;
        std::cin >> menuChoice;


        switch (menuChoice)
        {
        case 1:
            //Encoding Base64 From File
            //Code
            std::cout << "You chose Encoding From File" << std::endl;
            myBase64Encoding();
            _exitBase64 = true;
            break;
        case 2:
            //Decoding Base64 From File
            //Code
            std::cout << "You chose Decoding From File" << std::endl;
            myBase64Decoding();
            _exitBase64 = true;
            break;
        case 3:
            //Encoding Base64 From String
            //Code
            std::cout << "You chose Encoding from string" << std::endl;
            std::cout << "Enter the string: ";
            std::getline(std::cin >> std::ws, inputString);
            myBase64Encoding(inputString);
            _exitBase64 = true;
            break;
        case 4:
            //Decoding Base64 From String
            //Code
            std::cout << "You chose Decoding from string" << std::endl;
            std::cout << "Enter the string: ";
            std::getline(std::cin >> std::ws, inputString);
            myBase64Decoding(inputString);
            _exitBase64 = true;
            break;
        case 0:
            _exitBase64 = true;
        default:
            std::cout << "The option " << menuChoice << " does not exist" << std::endl;
            std::cout << "Redirecting to main menu" << std::endl;
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

        std::cout << "----------------------------" << std::endl;
        std::cout << "      8 bit Binary          " << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "[1] Encoding From File"       << std::endl;
        std::cout << "[ ] Decoding From File"       << std::endl;
        std::cout << "[ ] Encoding From String"     << std::endl;
        std::cout << "[4] Decoding From String"     << std::endl;
        std::cout << "[0] Back To Main Menu"        << std::endl;
        std::cin >> menuChoice;


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
            std::cout << "You chose Decoding From File" << std::endl;
            exitBinaryMenu = true;
            break;
        case 3:
            //Encoding Binary From String
            std::cout << "Enter the string: ";
            std::getline(std::cin >> std::ws, inputString);
            my8BitBinaryEncoding(inputString);
            exitBinaryMenu = true;
            break;
        case 4:
            //Decoding Binary From String
            std::cout << "Enter the string: ";
            std::getline(std::cin >> std::ws, inputString);
            my8BitBinaryDecoding(inputString);
            exitBinaryMenu = true;
            break;
        case 0:
            exitBinaryMenu = true;
            break;
        default:
            std::cout << "The option " << menuChoice << " does not exist" << std::endl;
            std::cout << "Redirecting to main menu" << std::endl;
            exitBinaryMenu = true;
            break;
        }

    }
}

void MainMenu(void)
{
    while (1)
    {
        short unsigned int menuChoice;
        std::cout << "----------------------------" << std::endl;
        std::cout << "      Main Menu             " << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "[1] Base64"                   << std::endl;
        std::cout << "[2] 8Bit Binary"              << std::endl;
        std::cout << "[3] Test Print A File"        << std::endl;
        std::cout << "[4] Test Encode String"       << std::endl;
        std::cout << "[5] Test Print File"          << std::endl;
        std::cout << "[0] Exit"                     << std::endl;

        std::cin >> menuChoice;
        std::cout << "\n" << std::endl;

        switch (menuChoice)
        {
        case 1:
            SubMenuBase64();
            break;
        case 2:
            SubMenu8bit();
            break;
        case 3:
            std::cout << "Enter A Filename: ";
            std::cin >> inputFile;
            printFile(inputFile);
            break;
        case 4:
            myBase64Encoding();
            break;
        case 5:
            std::cout << "Enter The Filename: ";
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
    std::cout << "This is Version " << ArgTools_VERSION_MAJOR << "."
                                    << ArgTools_VERSION_MINOR << "-dev"
                                    << std::endl;
    MainMenu();

    return 0;
}
