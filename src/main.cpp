#include "main.h"

void sub_menu_base32(void)
{
    std::string input_string;
    bool exit_flag_base32_bool = false;
    while (exit_flag_base32_bool == false)
    {
        short unsigned int menu_choice;

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
        std::cin >> menu_choice;
        std::cout << std::endl;

        switch (menu_choice)
        {
        case 1:
            // Encoding Base64 From File
            printf("You chose Encoding From File\n");
            chipher::base32::myBase32Encoding();
            exit_flag_base32_bool = true;
            break;
        case 2:
            // Decoding Base64 From File
            printf("You chose Decoding From File\n");
            chipher::base32::myBase32Decoding();
            exit_flag_base32_bool = true;
            break;
        case 3:
            // Encoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, input_string);
            chipher::base32::myBase32Encoding(input_string);
            exit_flag_base32_bool = true;
            break;
        case 4:
            // Decoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, input_string);
            chipher::base32::myBase32Decoding(input_string);
            exit_flag_base32_bool = true;
            break;
        case 0:
            exit_flag_base32_bool = true;
        default:
            printf("The option %d does not exist\n"
                   "Redirecting to main menu\n\n",
                   menu_choice);
            exit_flag_base32_bool = true;
            break;
        }
    }
}

void sub_menu_base64(void)
{
    std::string input_string;
    bool exit_flag_base64_bool = false;
    while (exit_flag_base64_bool == false)
    {
        short unsigned int sub_menu_base64_choice;

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
        std::cin >> sub_menu_base64_choice;
        std::cout << std::endl;

        switch (sub_menu_base64_choice)
        {
        case 1:
            // Encoding Base64 From File
            printf("You chose Encoding From File\n");
            chipher::base64::encoding();
            exit_flag_base64_bool = true;
            break;
        case 2:
            // Decoding Base64 From File
            printf("You chose Decoding From File\n");
            chipher::base64::decoding();
            exit_flag_base64_bool = true;
            break;
        case 3:
            // Encoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, input_string);
            chipher::base64::encoding(input_string);
            exit_flag_base64_bool = true;
            break;
        case 4:
            // Decoding Base64 From String
            printf("You chose Decoding from string\n");
            printf("Enter the string: ");
            std::getline(std::cin >> std::ws, input_string);
            chipher::base64::decoding(input_string);
            exit_flag_base64_bool = true;
            break;
        case 0:
            exit_flag_base64_bool = true;
        default:
            printf("The option %d does not exist\n"
                   "Redirecting to main menu\n\n",
                   sub_menu_base64_choice);
            exit_flag_base64_bool = true;
            break;
        }
    }
}

void sub_menu_8bit(void)
{
    std::string input_string;
    bool exit_flag_8bit_bool = false;
    while (exit_flag_8bit_bool == false)
    {
        short unsigned int sub_menu_8bit_choice;

        printf("----------------------------\n"
               "      8 bit Binary          \n"
               "----------------------------\n"
               "[1] Encoding From File\n"
               "[2] Decoding From File\n"
               "[3] Encoding From String\n"
               "[0] Back To Main Menu\n"
               "----------------------------\n"
               "Enter your choice: ");
        std::cin >> sub_menu_8bit_choice;
        std::cout << std::endl;

        switch (sub_menu_8bit_choice)
        {
        case 1:
            // Encoding Binary From File
            printf("You chose Encoding From File\n");
            // std::cout << "Enter filename: ";
            // std::getline(std::cin >> std::ws, inputString);
            my8BitBinaryEncoding();
            exit_flag_8bit_bool = true;
            break;
        case 2:
            // Decoding Binary From File
            printf("Enter the filename: ");
            std::getline(std::cin >> std::ws, input_string);
            std::cout << std::endl;
            my8BitBinaryDecodingString(input_string);
            exit_flag_8bit_bool = true;
            break;
        case 3:
            // Encoding Binary From String
            std::cout << "Enter the string: ";
            std::getline(std::cin >> std::ws, input_string);
            std::cout << std::endl;
            my8BitBinaryEncoding(input_string);
            exit_flag_8bit_bool = true;
            break;
        case 0:
            exit_flag_8bit_bool = true;
            break;
        default:
            printf("The option %d does not exist\n"
                   "Redirecting to main menu\n",
                   sub_menu_8bit_choice);
            exit_flag_8bit_bool = true;
            break;
        }
    }
}

void sub_menu_ceasar_chipher()
{
    std::string input_string;
    short unsigned int shift_key_short_uint;
    bool exit_flag_ceasar_chipher_bool = false;
    while (exit_flag_ceasar_chipher_bool == false)
    {
        short unsigned int sub_menu_ceasar_chipher_choice;

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
        std::cin >> sub_menu_ceasar_chipher_choice;
        std::cout << std::endl;

        switch (sub_menu_ceasar_chipher_choice)
        {
        case 1:
            printf("Enter the filename: ");
            std::getline(std::cin >> std::ws, input_string);
            printf("\nEnter the numeric shifting chipher wissed to use: ");
            std::cin >> shift_key_short_uint;
            chipher::ceasar::encoding(shift_key_short_uint, Tanja84dk::tools::read_file(input_string));
            break;
        case 2:
            break;
        case 3:
            printf("Enter the string to encode: ");
            std::getline(std::cin >> std::ws, input_string);
            printf("\nEnter the numeric shifting chipher wissed to use: ");
            std::cin >> shift_key_short_uint;
            chipher::ceasar::encoding(shift_key_short_uint, input_string);
            exit_flag_ceasar_chipher_bool = true;
            break;
        case 4:
            printf("Enter the string to decode: ");
            std::getline(std::cin >> std::ws, input_string);
            printf("\nEnter the numeric shifting chipher key: ");
            std::cin >> shift_key_short_uint;
            chipher::ceasar::decoding(shift_key_short_uint, input_string);
            exit_flag_ceasar_chipher_bool = true;
            break;
        case 9:
            printf("Enter the string to bruteforce: ");
            std::getline(std::cin >> std::ws, input_string);
            chipher::ceasar::decoding_brute_force(input_string);
            break;
        case 0:
            exit_flag_ceasar_chipher_bool = true;
            break;
        default:
            exit_flag_ceasar_chipher_bool = true;
            break;
        }
    }
}

void main_menu(void)
{
    std::string input_file_string;
    while (1)
    {
        short unsigned int main_menu_choice;
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
               "This is Version %d.%d.%d-dev\n"
               "----------------------------\n"
               "Enter your choice: ",
               ArgTools_VERSION_MAJOR, ArgTools_VERSION_MINOR, ArgTools_VERSION_PATCH);

        std::cin >> main_menu_choice;
        std::cout << std::endl;

        switch (main_menu_choice)
        {
        case 1:
            sub_menu_base32();
            break;
        case 2:
            sub_menu_base64();
            break;
        case 3:
            sub_menu_8bit();
            break;
        case 4:
            sub_menu_ceasar_chipher();
            break;
        case 6:
            printf("Enter The Filename: ");
            std::getline(std::cin >> std::ws, input_file_string);
            Tanja84dk::tools::print_file(input_file_string);
            break;
        case 9:
            chipher::ceasar::decoding(4, "Xlmw aew e xvmyqtl!");
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
}

int main(int argc, char **argv)
{
    printf("This is Version %d.%d.%d-dev\n", ArgTools_VERSION_MAJOR, ArgTools_VERSION_MINOR, ArgTools_VERSION_PATCH);
    main_menu();

    return 0;
}
