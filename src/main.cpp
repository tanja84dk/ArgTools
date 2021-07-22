#include "main.h"


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

void subMenuBase64(void)
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

void subMenu8bit(void)
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
            printf("You chose Encoding From File\n");
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

void subMenuCeasar()
{
    std::string inputData;
    short unsigned int shiftKeyValue;
    bool exitCeasarMenu = false;
    while ( exitCeasarMenu == false )
    {
        short unsigned int menuChoice;

        printf("----------------------------\n"
               "      Ceasar\n"
               "----------------------------\n"
               "[1] Encoding From File\n"
               "[ ] Decoding From File\n"
               "[3] Encoding From String\n"
               "[4] Decoding From String\n"
               "[9] Bruteforce The Key\n"
               "[0] Back To Main Menu\n"
               "----------------------------\n"
               "Enter your choice: ");
        std::cin >> menuChoice;
        std::cout << std::endl;

        switch (menuChoice)
        {
        case 1:
            printf("Enter the filename: ");
            std::getline(std::cin >> std::ws, inputData);
            printf("\nEnter the numeric shifting chipher wissed to use: ");
            std::cin >> shiftKeyValue;
            caesarEncoding(shiftKeyValue, Tools::readFile(inputData));
            break;
        case 2:
            break;
        case 3:
            printf("Enter the string to encode: ");
            std::getline(std::cin >> std::ws, inputData);
            printf("\nEnter the numeric shifting chipher wissed to use: ");
            std::cin >> shiftKeyValue;
            caesarEncoding(shiftKeyValue, inputData);
            exitCeasarMenu = true;
            break;
        case 4:
            printf("Enter the string to decode: ");
            std::getline(std::cin >> std::ws, inputData);
            printf("\nEnter the numeric shifting chipher key: ");
            std::cin >> shiftKeyValue;
            ceasarDecoding(shiftKeyValue, inputData);
            exitCeasarMenu= true;
            break;
        case 9:
            printf("Enter the string to bruteforce: ");
            std::getline(std::cin >> std::ws, inputData);
            ceasarDecodingBruteforce(inputData);
            break;
        case 0:
        exitCeasarMenu = true;
            break;
        default:
            exitCeasarMenu = true;
            break;
        }
    }
}

void mainMenu(void)
{
    std::string inputFile;
    while (1)
    {
        short unsigned int menuChoice;
        printf("----------------------------\n"
               "      Main Menu\n"
               "----------------------------\n"
               "[1] Base32\n"
               "[2] Base64\n"
               "[3] 8Bit Binary\n"
               "[4] Ceasar Chipher\n"
               "[6] Test Print File\n"
               "[0] Exit\n"
               "----------------------------\n"
               "This is Version %d.%d-dev\n"
               "----------------------------\n"
               "Enter your choice: ",
               ArgTools_VERSION_MAJOR, ArgTools_VERSION_MINOR);

        std::cin >> menuChoice;
        std::cout << std::endl;

        switch (menuChoice)
        {
        case 1:
            subMenuBase32();
            break;
        case 2:
            subMenuBase64();
            break;
        case 3:
            subMenu8bit();
            break;
        case  4:
            subMenuCeasar();
            break;
        case 6:
            printf("Enter The Filename: ");
            std::getline(std::cin >> std::ws, inputFile);
            Tools::printFile(inputFile);
            break;
        case 9:
            ceasarDecoding(4, "Xlmw aew e xvmyqtl!");
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
    printf("This is Version %d.%d-dev\n", ArgTools_VERSION_MAJOR, ArgTools_VERSION_MINOR);
    mainMenu();

    return 0;
}
