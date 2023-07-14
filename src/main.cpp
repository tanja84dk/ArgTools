#include "main.h"

#include <ArgToolsConfig.h>
#include <Tanja84dk/crypt/base32/base32.h>
#include <Tanja84dk/crypt/base64/base64.h>
#include <Tanja84dk/crypt/binary/binary.h>
#include <Tanja84dk/crypt/ceasar/ceasar.h>
#include <Tanja84dk/tools/tools.h>

#include <list>
#include <string>
#include <utility>

#include "licenses.h"

class AargToolsData {
   public:
    const void clear() noexcept {
        this->input_filename_string.clear();
        this->output_filename_string.clear();
        this->input_data_string.clear();
        this->output_data_string.clear();
    };

   public:
    std::string input_filename_string = {};
    std::string output_filename_string = {};
    std::string input_data_string = {};
    std::string output_data_string = {};
};

void sub_menu_base32(void) {
    AargToolsData Base32DataStore;
    bool exit_flag_base32_bool = false;
    while (exit_flag_base32_bool == false) {
        short unsigned int menu_choice;

        std::cout << "----------------------------\n"
                  << "      Base32\n"
                  << "----------------------------\n"
                  << "[1] Encoding From File\n"
                  << "[2] Decoding From File\n"
                  << "[3] Encoding From String\n"
                  << "[4] Decoding From String\n"
                  << "[0] Back To Main Menu\n"
                  << "----------------------------\n"
                  << "Enter your choice: ";
        std::cin >> menu_choice;
        std::cout << std::endl;

        switch (menu_choice) {
            case 1:
                Base32DataStore.clear();
                std::cout << "You chose Encoding From File\nEnter filename: ";
                std::getline(std::cin >> std::ws, Base32DataStore.input_filename_string);
                if (Tanja84dk::tools::file_exist(Base32DataStore.input_filename_string)) {
                    Base32DataStore.input_data_string =
                        Tanja84dk::tools::read_file(Base32DataStore.input_filename_string);
                    Base32DataStore.output_data_string =
                        Tanja84dk::crypt::base32::encode(Base32DataStore.input_data_string);
                    std::cout << Base32DataStore.output_data_string << "\n\n";
                }

                exit_flag_base32_bool = true;
                break;
            case 2:
                // Decoding Base64 From File
                Base32DataStore.clear();
                std::cout << "You chose Decoding From File\nEnter filename: ";
                std::getline(std::cin >> std::ws, Base32DataStore.input_filename_string);
                if (Tanja84dk::tools::file_exist(Base32DataStore.input_filename_string)) {
                    Base32DataStore.input_data_string =
                        Tanja84dk::tools::read_file(Base32DataStore.input_filename_string);
                    Base32DataStore.output_data_string =
                        Tanja84dk::crypt::base32::decode(Base32DataStore.input_data_string);
                    std::cout << Base32DataStore.output_data_string << "\n\n";
                }

                exit_flag_base32_bool = true;
                break;
            case 3:
                // Encoding Base64 From String
                Base32DataStore.clear();
                std::cout << "You chose Encoding From string\nEnter the string: ";
                std::getline(std::cin >> std::ws, Base32DataStore.input_data_string);
                Base32DataStore.output_data_string =
                    Tanja84dk::crypt::base32::encode(Base32DataStore.input_data_string);
                std::cout << Base32DataStore.output_data_string << "\n\n";

                exit_flag_base32_bool = true;
                break;
            case 4:
                // Decoding Base64 From String
                Base32DataStore.clear();
                std::cout << "You chose Decoding From string\nEnter the string: ";
                std::getline(std::cin >> std::ws, Base32DataStore.input_data_string);
                Base32DataStore.output_data_string =
                    Tanja84dk::crypt::base32::decode(Base32DataStore.input_data_string);
                std::cout << Base32DataStore.output_data_string << "\n\n";

                exit_flag_base32_bool = true;
                break;
            case 0:
                exit_flag_base32_bool = true;
            default:
                std::cout << "The option " << menu_choice << " does not exist\nRedirecting to main menu\n\n";
                exit_flag_base32_bool = true;
                break;
        }
    }
}

void sub_menu_base64(void) {
    AargToolsData Base64DataStore;
    bool exit_flag_base64_bool = false;
    while (exit_flag_base64_bool == false) {
        short unsigned int sub_menu_base64_choice;

        std::cout << "----------------------------\n"
                  << "      Base64   \n"
                  << "----------------------------\n"
                  << "[1] Encoding From File\n"
                  << "[2] Decoding From File\n"
                  << "[3] Encoding From String\n"
                  << "[4] Decoding From String\n"
                  << "[0] Back To Main Menu\n"
                  << "----------------------------\n"
                  << "Enter your choice: ";
        std::cin >> sub_menu_base64_choice;
        std::cout << std::endl;

        switch (sub_menu_base64_choice) {
            case 1:
                // Encoding Base64 From File
                Base64DataStore.clear();
                std::cout << "You chose Encoding From File\nEnter filename: ";
                std::getline(std::cin >> std::ws, Base64DataStore.input_filename_string);
                if (Tanja84dk::tools::file_exist(Base64DataStore.input_filename_string)) {
                    Base64DataStore.input_data_string =
                        Tanja84dk::tools::read_file(Base64DataStore.input_filename_string);
                    Base64DataStore.output_data_string =
                        Tanja84dk::crypt::base64::encode(Base64DataStore.input_data_string);
                    std::cout << Base64DataStore.output_data_string << "\n\n";
                }

                exit_flag_base64_bool = true;
                break;
            case 2:
                // Decoding Base64 From File
                Base64DataStore.clear();
                std::cout << "You chose Decoding From File\nEnter filename: ";
                std::getline(std::cin >> std::ws, Base64DataStore.input_filename_string);
                if (Tanja84dk::tools::file_exist(Base64DataStore.input_filename_string)) {
                    Base64DataStore.input_data_string =
                        Tanja84dk::tools::read_file(Base64DataStore.input_filename_string);
                    Base64DataStore.output_data_string =
                        Tanja84dk::crypt::base64::decode(Base64DataStore.input_data_string);
                    std::cout << Base64DataStore.output_data_string << "\n\n";
                }

                exit_flag_base64_bool = true;
                break;
            case 3:
                // Encoding Base64 From String
                Base64DataStore.clear();
                std::cout << "You chose Encoding from string\nEnter the string: ";
                std::getline(std::cin >> std::ws, Base64DataStore.input_data_string);
                Base64DataStore.output_data_string =
                    Tanja84dk::crypt::base64::encode(Base64DataStore.input_data_string);
                std::cout << Base64DataStore.output_data_string << "\n\n";

                exit_flag_base64_bool = true;
                break;
            case 4:
                // Decoding Base64 From String
                Base64DataStore.clear();
                std::cout << "You chose Decoding from string\nEnter the string: ";
                std::getline(std::cin >> std::ws, Base64DataStore.input_data_string);
                Base64DataStore.output_data_string =
                    Tanja84dk::crypt::base64::decode(Base64DataStore.input_data_string);
                std::cout << Base64DataStore.output_data_string << "\n\n";
                exit_flag_base64_bool = true;
                break;
            case 0:
                exit_flag_base64_bool = true;
            default:
                std::cout << "The option " << sub_menu_base64_choice << " does not exist\nRedirecting to main menu\n\n";
                exit_flag_base64_bool = true;
                break;
        }
    }
}

void sub_menu_8bit(void) {
    std::string input_string;
    std::string output_string;
    std::vector<std::bitset<8>> input_vector;
    std::vector<std::bitset<8>> output_vector;
    std::string input_filename_string;
    std::string output_filename_string;
    bool exit_flag_8bit_bool = false;
    while (exit_flag_8bit_bool == false) {
        short unsigned int sub_menu_8bit_choice;

        std::cout << "----------------------------\n"
                  << "      8 bit Binary          \n"
                  << "----------------------------\n"
                  << "[1] Encoding From File\n"
                  << "[2] Decoding From File\n"
                  << "[3] Encoding From String\n"
                  << "[0] Back To Main Menu\n"
                  << "----------------------------\n"
                  << "Enter your choice: ";
        std::cin >> sub_menu_8bit_choice;
        std::cout << std::endl;

        switch (sub_menu_8bit_choice) {
            case 1:
                // Encoding Binary From File
                input_filename_string.clear();
                std::cout << "You chose Encoding From File\nEnter the filename: ";
                std::getline(std::cin >> std::ws, input_filename_string);
                if (Tanja84dk::tools::file_exist(input_filename_string)) {
                    output_filename_string = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" +
                                             Tanja84dk::tools::remove_extention(input_filename_string) +
                                             "-Binary-Encoded.txt";
                    output_vector.clear();
                    output_vector =
                        Tanja84dk::crypt::binary::encode(Tanja84dk::tools::read_file(input_filename_string));
                    if (Tanja84dk::tools::file_exist(output_filename_string) == false) {
                        Tanja84dk::tools::write_file(output_vector, output_filename_string);
                    }
                }
                input_filename_string.clear();
                output_filename_string.clear();
                exit_flag_8bit_bool = true;
                break;
            case 2:
                // Decoding Binary From File
                std::cout << "Enter the filename: ";
                std::getline(std::cin >> std::ws, input_filename_string);
                if (Tanja84dk::tools::file_exist(input_filename_string)) {
                    output_filename_string = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" +
                                             Tanja84dk::tools::remove_extention(input_filename_string) +
                                             "-Binary-Decoded.txt";
                    std::string output_data_string = {};
                    output_data_string =
                        Tanja84dk::crypt::binary::decode(Tanja84dk::tools::read_file(input_filename_string));
                    if (Tanja84dk::tools::file_exist(output_filename_string) == false) {
                        Tanja84dk::tools::write_file(output_data_string, output_filename_string);
                    }
                }
                exit_flag_8bit_bool = true;
                break;
            case 3:
                // Encoding Binary From String
                std::cout << "Enter the string: ";
                std::getline(std::cin >> std::ws, input_string);
                std::cout << std::endl;

                output_filename_string =
                    Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Binary-Eecoded.txt";
                output_vector.clear();
                output_vector = Tanja84dk::crypt::binary::encode(input_string);
                if (Tanja84dk::tools::file_exist(output_filename_string) == false) {
                    Tanja84dk::tools::write_file(output_vector, output_filename_string);
                }

                exit_flag_8bit_bool = true;
                break;
            case 0:
                exit_flag_8bit_bool = true;
                break;
            default:
                std::cout << "The option " << sub_menu_8bit_choice << " does not exist\nRedirecting to main menu\n";
                exit_flag_8bit_bool = true;
                break;
        }
    }
}

void sub_menu_ceasar_chipher() {
    AargToolsData CeasarDataStore;
    int shift_key_int;
    bool exit_flag_ceasar_chipher_bool = false;
    while (exit_flag_ceasar_chipher_bool == false) {
        short unsigned int sub_menu_ceasar_chipher_choice;

        std::cout << "----------------------------\n"
                  << "      Ceasar\n"
                  << "----------------------------\n"
                  << "[1] Encoding From File\n"
                  << "[2] Decoding From File\n"
                  << "[3] Encoding From String\n"
                  << "[4] Decoding From String\n"
                  << "[9] Bruteforce The Key(Working on)\n"
                  << "[0] Back To Main Menu\n"
                  << "----------------------------\n"
                  << "Enter your choice: ";
        std::cin >> sub_menu_ceasar_chipher_choice;
        std::cout << std::endl;

        switch (sub_menu_ceasar_chipher_choice) {
            case 1:
                CeasarDataStore.clear();
                std::cout << "Enter the filename: ";
                std::getline(std::cin >> std::ws, CeasarDataStore.input_filename_string);
                std::cout << "\nEnter the numeric shifting chipher wissed to use: ";
                std::cin >> shift_key_int;
                if (Tanja84dk::tools::file_exist(CeasarDataStore.input_filename_string)) {
                    CeasarDataStore.output_filename_string =
                        Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" +
                        Tanja84dk::tools::remove_extention(CeasarDataStore.input_filename_string) +
                        "-Encoded-CeasarChipher.txt";
                    CeasarDataStore.input_data_string =
                        Tanja84dk::tools::read_file(CeasarDataStore.input_filename_string);
                    CeasarDataStore.output_data_string =
                        Tanja84dk::crypt::ceasar::encode(shift_key_int, CeasarDataStore.input_data_string);

                    if (Tanja84dk::tools::file_exist(CeasarDataStore.output_filename_string) == false) {
                        Tanja84dk::tools::write_file(CeasarDataStore.output_data_string,
                                                     CeasarDataStore.output_filename_string);
                        std::cout << "The output is also written to a file called "
                                  << CeasarDataStore.output_filename_string << " in the folder you ran it from\n";
                    }
                }
                exit_flag_ceasar_chipher_bool = true;
                break;
            case 2:
                CeasarDataStore.clear();
                std::cout << "Enter the filename: ";
                std::getline(std::cin >> std::ws, CeasarDataStore.input_filename_string);
                std::cout << "\nEnter the numeric shifting chipher wissed to use: ";
                std::cin >> shift_key_int;
                if (Tanja84dk::tools::file_exist(CeasarDataStore.input_filename_string)) {
                    CeasarDataStore.output_filename_string =
                        Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" +
                        Tanja84dk::tools::remove_extention(CeasarDataStore.input_filename_string) +
                        "-Decoded-CeasarChipher.txt";
                    CeasarDataStore.input_data_string =
                        Tanja84dk::tools::read_file(CeasarDataStore.input_filename_string);
                    CeasarDataStore.output_data_string =
                        Tanja84dk::crypt::ceasar::decode(shift_key_int, CeasarDataStore.input_data_string);

                    if (Tanja84dk::tools::file_exist(CeasarDataStore.output_filename_string) == false) {
                        Tanja84dk::tools::write_file(CeasarDataStore.output_data_string,
                                                     CeasarDataStore.output_filename_string);
                        std::cout << "The output is also written to a file called "
                                  << CeasarDataStore.output_filename_string << " in the folder you ran it from\n";
                    }
                }
                exit_flag_ceasar_chipher_bool = true;
                break;
            case 3:
                CeasarDataStore.clear();
                std::cout << "Enter the plain data: ";
                std::getline(std::cin >> std::ws, CeasarDataStore.input_data_string);
                std::cout << "\nEnter the numeric shifting chipher wissed to use: ";
                std::cin >> shift_key_int;

                CeasarDataStore.output_filename_string =
                    Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Encoded-CeasarChipher.txt";
                CeasarDataStore.output_data_string =
                    Tanja84dk::crypt::ceasar::encode(shift_key_int, CeasarDataStore.input_data_string);

                if (Tanja84dk::tools::file_exist(CeasarDataStore.output_filename_string) == false) {
                    Tanja84dk::tools::write_file(CeasarDataStore.output_data_string,
                                                 CeasarDataStore.output_filename_string);
                    std::cout << "The output is also written to a file called "
                              << CeasarDataStore.output_filename_string << " in the folder you ran it from\n";
                }

                exit_flag_ceasar_chipher_bool = true;
                break;
            case 4:
                CeasarDataStore.clear();
                std::cout << "Enter the encoded data: ";
                std::getline(std::cin >> std::ws, CeasarDataStore.input_data_string);
                std::cout << "\nEnter the numeric shifting chipher wissed to use: ";
                std::cin >> shift_key_int;

                CeasarDataStore.output_filename_string =
                    Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Decoded-CeasarChipher.txt";
                CeasarDataStore.output_data_string =
                    Tanja84dk::crypt::ceasar::decode(shift_key_int, CeasarDataStore.input_data_string);

                if (Tanja84dk::tools::file_exist(CeasarDataStore.output_filename_string) == false) {
                    Tanja84dk::tools::write_file(CeasarDataStore.output_data_string,
                                                 CeasarDataStore.output_filename_string);
                    std::cout << "The output is also written to a file called "
                              << CeasarDataStore.output_filename_string << " in the folder you ran it from\n";
                }

                exit_flag_ceasar_chipher_bool = true;
                break;
            case 9:
                CeasarDataStore.clear();
                std::cout << "Enter the encoded data: ";
                std::getline(std::cin >> std::ws, CeasarDataStore.input_data_string);
                Tanja84dk::crypt::ceasar::decode_brute_force(CeasarDataStore.input_data_string);
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

void sub_menu_about() noexcept {
    bool exit_flag_about_bool = false;
    while (exit_flag_about_bool == false) {
        short unsigned int sub_menu_about_choice;

        std::cout << "----------------------------\n"
                  << "      About\n"
                  << "----------------------------\n"
                  << "[ ] About Project\n"
                  << "[2] All Licenses\n"
                  << "[0] Back To Main Menu\n"
                  << "----------------------------\n"
                  << "Enter your choice: ";
        std::cin >> sub_menu_about_choice;
        std::cout << std::endl;

        switch (sub_menu_about_choice) {
            case 1:
                exit_flag_about_bool = true;
                break;
            case 2:
                Tanja84dk::argtools::license::print_all_licenses();
                exit_flag_about_bool = true;
                break;
            case 0:
                exit_flag_about_bool = true;
                break;
            default:
                exit_flag_about_bool = true;
                break;
        }
    }
}

void main_menu(void) {
    std::string input_file_string;
    while (1) {
        short unsigned int main_menu_choice;
        std::cout << "----------------------------\n"
                  << "      Main Menu\n"
                  << "----------------------------\n"
                  << "[1] Base32\n"
                  << "[2] Base64\n"
                  << "[3] 8Bit Binary\n"
                  << "[4] Ceasar Chipher\n"
                  << "[6] Test Print File\n"
                  << "[9] About\n"
                  << "[0] Exit\n"
                  << "----------------------------\n"
                  << "This is Version " << ArgTools_VERSION_MAJOR << "." << ArgTools_VERSION_MINOR << "."
                  << ArgTools_VERSION_PATCH << "-dev\n"
                  << "----------------------------\n"
                  << "Enter your choice: ";

        std::cin >> main_menu_choice;
        std::cout << std::endl;

        switch (main_menu_choice) {
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
                std::cout << "Enter The Filename: ";
                std::getline(std::cin >> std::ws, input_file_string);
                Tanja84dk::tools::print_file(input_file_string);
                break;
            case 9:
                sub_menu_about();
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    }
}

int main(int argc, char **argv) {
    main_menu();

    return 0;
}
