#include "caesarChipher.h"

void chipher::ceasar::encoding(const int chipher_shift_key, const std::string &input_data) {
    std::string output_data_string;
    std::string output_filename_string;

    char buffer_char;
    for (int i = 0; i != input_data.length(); i++) {
        buffer_char = input_data[i];
        if (buffer_char >= 'a' && buffer_char <= 'z') {
            buffer_char = buffer_char + chipher_shift_key;
            if (buffer_char > 'z') {
                buffer_char = buffer_char - 'z' + 'a' - 1;
            }
            output_data_string += buffer_char;
        } else if (buffer_char >= 'A' && buffer_char <= 'Z') {
            buffer_char = buffer_char + chipher_shift_key;
            if (buffer_char > 'Z') {
                buffer_char = buffer_char - 'Z' + 'a' - 1;
            }
            output_data_string += buffer_char;
        } else {
            output_data_string += buffer_char;
        }
    }

    std::cout << output_data_string << std::endl;

    output_filename_string =
        Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-CeasarChipher.txt";

    if (Tanja84dk::tools::file_exist(output_filename_string) == false) {
        Tanja84dk::tools::write_file(output_data_string, output_filename_string);
        printf("The output is also written to a file called %s in the folder you have the program in\n",
               output_filename_string.c_str());
    }
};

void chipher::ceasar::decoding(const int chipher_shift_key, const std::string &input_data) {
    std::string output_data_string;
    std::string output_filename_string;

    char buffer_char;
    for (int i = 0; i != input_data.length(); i++) {
        buffer_char = input_data[i];
        if (buffer_char >= 'a' && buffer_char <= 'z') {
            buffer_char = buffer_char - chipher_shift_key;
            if (buffer_char < 'a') {
                buffer_char = buffer_char + 'z' - 'a' + 1;
            }
            output_data_string += buffer_char;
        } else if (buffer_char >= 'A' && buffer_char <= 'Z') {
            buffer_char = buffer_char - chipher_shift_key;
            if (buffer_char < 'A') {
                buffer_char = buffer_char + 'Z' - 'A' + 1;
            }
            output_data_string += buffer_char;
        } else {
            output_data_string += buffer_char;
        }
    }

    std::cout << output_data_string << std::endl;

    output_filename_string =
        Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-CeasarChipher.txt";

    if (Tanja84dk::tools::file_exist(output_filename_string) == false) {
        Tanja84dk::tools::write_file(output_data_string, output_filename_string);
        printf("The output is also written to a file called %s in the folder you have the program in\n",
               output_filename_string.c_str());
    }
};

void chipher::ceasar::decoding_brute_force(const std::string &input_data) {
    for (int chipher_shift_key_int = 1; chipher_shift_key_int < 27; chipher_shift_key_int++) {
        short unsigned int count_of_spaces_uint = 0;
        std::string output_data_string;
        char buffer_char;
        for (int i = 0; i != input_data.length() && count_of_spaces_uint != 3; i++) {
            buffer_char = input_data[i];
            if (buffer_char >= 'a' && buffer_char <= 'z') {
                buffer_char = buffer_char - chipher_shift_key_int;
                if (buffer_char < 'a') {
                    buffer_char = buffer_char + 'z' - 'a' + 1;
                }
                output_data_string += buffer_char;
            } else if (buffer_char >= 'A' && buffer_char <= 'Z') {
                buffer_char = buffer_char - chipher_shift_key_int;
                if (buffer_char < 'A') {
                    buffer_char = buffer_char + 'Z' - 'A' + 1;
                }
                output_data_string += buffer_char;
            } else {
                if (buffer_char == ' ') {
                    count_of_spaces_uint++;
                    if (count_of_spaces_uint == 3) {
                        std::cout << "Key Value " << chipher_shift_key_int << " and the data is: " << output_data_string
                                  << std::endl;
                    }
                }
                output_data_string += buffer_char;
            }
        }
    }
}
