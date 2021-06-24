#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#include <streambuf>
#include <Base64/Base64.hpp>
#include <Tools/Tools.h>

char timeBuffer[80];

std::string inputFile;

std::string __timestampNow()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(timeBuffer, sizeof(timeBuffer), "%Y%m%d_%H%M%S", timeinfo);
    std::string timeNow(timeBuffer);
    return timeNow;
}

int filename(std::string filename) {
    int statusCode;
    std::ifstream _file;
    _file.open(filename, std::ifstream::in);
    if (_file.is_open()) {
        //cout << "It Exist" << endl;
        statusCode = 200;
    }
    else {
        //cout << "Does Not Exist" << endl;
        statusCode = 404;
    }
    return statusCode;
}

void myBase64DecodingString()
{
    std::cout << "Enter the string" << std::endl;
    std::string __inputTemp;
    std::cin >> __inputTemp;
    int __myBase64DecodingStringStatusCode;
    std::string __myBase64DecodingStringTemp;
    std::string __myBase64DecodingStringOutput;
    std::string __myBase64DecodingStringOutputFilename;

    __myBase64DecodingStringOutput = Base64::Decode((__inputTemp));

    __myBase64DecodingStringOutputFilename = __timestampNow() + "-" + "From_String" + "-Decoded-Base64.txt";
    __myBase64DecodingStringStatusCode = filename(__myBase64DecodingStringOutputFilename);
        if (__myBase64DecodingStringStatusCode == 404) {
            std::ofstream __myBase64DecodingStringOutputFile;
            __myBase64DecodingStringOutputFile.open(__myBase64DecodingStringOutputFilename);
            __myBase64DecodingStringOutputFile << __myBase64DecodingStringOutput;
            __myBase64DecodingStringOutputFile.close();
            std::cout << "The output is also written to a file called " << __myBase64DecodingStringOutputFilename << " in the folder you have the program in" << std::endl;
    }
}
void myBase64Encoding(void)
{
    int __myBase64EncodingStatusCode;
    std::string __myBase64Encoding;
    std::cout << "Enter Filename "; std::cin >> __myBase64Encoding;
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

    __myBase64EncodedOutputFilename = __timestampNow() + "-" + __myBase64Encoding + "-Encoded-Base64.txt";
    __myBase64EncodingStatusCode = filename(__myBase64EncodedOutputFilename);
    if (__myBase64EncodingStatusCode == 404) {
        std::ofstream __myBase64EncodedOutputFile;
        __myBase64EncodedOutputFile.open(__myBase64EncodedOutputFilename);
        __myBase64EncodedOutputFile << __myBase64EncodedOutput;
        __myBase64EncodedOutputFile.close();
        std::cout << "The output is also written to a file called " << __myBase64EncodedOutputFilename << " in the folder you have the program in" << std::endl;
    }
}

//string __stringToBits(s='')
//{
//    return [bin(ord(x))[2:].zfill(8) for x in s];
//}

//string __bitsToString(b = None)
//{
//    return ''.join([chr(int(x, 2)) for x in b]);
//}

std::string printFile(std::string inputfile)
{
    int printFileStatusCode;
    printFileStatusCode = filename(inputFile);
    if (printFileStatusCode == 200)
    {
        //cout << "Status Code: " << printFileStatusCode << ". The File Exist." << endl << "The Encoding String Goes Here" << endl;
        std::cout << std::endl << std::endl;
        std::ifstream __readFile(inputFile, std::ifstream::in);
        if (__readFile.is_open())
        {
            std::cout << __readFile.rdbuf();
        };
        return inputFile;
    }
    else if (printFileStatusCode == 404)
    {
        std::cout << "Status Code: " << printFileStatusCode << ". The File Does Not Exist" << std::endl;
        exit(404);
    }
    else
    {
        std::cout << "Status Code: " << printFileStatusCode << ". Some Internal Error Has happend" << std::endl << "Exitting The Program" << std::endl;
        exit(100);
    }
}

void SubMenuBase64()
{
    bool _exitBase64 = false;
    while (_exitBase64 == false)
    {
        int opt;

        std::cout << "----------------------------" << std::endl;
        std::cout << "      Base64   " << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "[1] Encoding From File" << std::endl;
        std::cout << "[2] Decoding From File" << std::endl;
        std::cout << "[3] Encoding From String" << std::endl;
        std::cout << "[4] Decoding From String" << std::endl;
        std::cout << "[0] Back To Main Menu" << std::endl;
        std::cin >> opt;


        switch (opt)
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
            _exitBase64 = true;
            break;
        case 3:
            //Encoding Base64 From String
            //Code
            std::cout << "You chose Encoding from string" << std::endl;
            _exitBase64 = true;
            break;
        case 4:
            //Decoding Base64 From String
            //Code
            std::cout << "You chose Decoding from string" << std::endl;
            myBase64DecodingString();
            _exitBase64 = true;
            break;
        case 0:
            _exitBase64 = true;
        default:
            std::cout << "The option " << opt << " does not exist" << std::endl;
            std::cout << "Redirecting to main menu" << std::endl;
            _exitBase64 = true;
            break;
        }

    }
}

void SubMenu8bit()
{
    bool _exit8Bit = false;
    while (_exit8Bit == false)
    {
        int opt;

        std::cout << "----------------------------" << std::endl;
        std::cout << "      8 bit Binary   " << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "[1] Encoding From File" << std::endl;
        std::cout << "[2] Decoding From File" << std::endl;
        std::cout << "[0] Back To Main Menu" << std::endl;
        std::cin >> opt;


        switch (opt)
        {
        case 1:
            //Code
            std::cout << "You chose Encoding From File" << std::endl;
            _exit8Bit = true;
            break;
        case 2:
            //Code
            std::cout << "You chose Decoding From File" << std::endl;
            _exit8Bit = true;
            break;
        case 0:
            _exit8Bit = true;
        default:
            std::cout << "The option " << opt << " does not exist" << std::endl;
            std::cout << "Redirecting to main menu" << std::endl;
            _exit8Bit = true;
            break;
        }

    }
}

void MainMenu() {
    while (1)
    {
        int opt;
        std::cout << "----------------------------" << std::endl;
        std::cout << "      Main Menu   " << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "[1] Base64" << std::endl;
        std::cout << "[2] 8Bit Binary" << std::endl;
        std::cout << "[3] Test Print A File" << std::endl;
        std::cout << "[4] Test Encode String" << std::endl;
        std::cout << "[0] Exit" << std::endl;

        std::cin >> opt;
        std::cout << "\n" << std::endl;

        switch (opt)
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
        case 0:
            exit(0);
        default:
            break;
        }
    }

}

int main(int argc, char** argv)
{
    std::string timeTest;
    //timeTest = Tools::CreateTimeStamp();
    //cout << "Testing Class Function: " << timeTest << endl;
    std::string timest = __timestampNow();
    std::string ts1 = __timestampNow();
    std::cout << "Stamp (ts1) 1: " << ts1 << std::endl;
    std::cout << argv[0] << std::endl;
    MainMenu();
    std::string inputFile;
    std::cout << "Hello CMake." << std::endl;
    std::cout << "Enter The Input filename: ";
    std::cin >> inputFile;
    int _status = filename(inputFile);
    if (_status == 200) {
        std::ifstream _inputFile(inputFile);
        std::cout << _inputFile.rdbuf();
        _inputFile.close();
    }
    else {
        std::cout << "File Does Not Exist" << std::endl;
    };
    //ifstream file(inputFile);
    //if (file.is_open());
    //cout << file.rdbuf();
    //MainMenu();
    ts1 = __timestampNow();
    std::cout << "Stamp (ts1 reuse) 2: " << __timestampNow() << std::endl;
    return 0;
}
