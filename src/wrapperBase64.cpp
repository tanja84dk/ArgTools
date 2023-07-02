#include "wrapperBase64.h"

void myBase64Decoding(void)
{
    std::string inputFilename;
    std::string outputFilename;
    std::string outputData;

    printf("Enter the filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::cout << std::endl;

    if (Tanja84dk::tools::file_exists(inputFilename))
    {
        outputData = Base64::Decode(Tanja84dk::tools::read_file(inputFilename));

        // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
        // Falling back to cout until issue is located
        std::cout << outputData << std::endl;

        outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Decoded-Base64.txt";
        if (!Tanja84dk::tools::file_exists(outputFilename))
        {
            Tanja84dk::tools::write_file(outputData, outputFilename);
            printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
        }
    };
}

void myBase64Decoding(const std::string &inputData)
{
    std::string outputData;
    std::string outputFilename;
    outputData = Base64::Decode(inputData);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}

void myBase64DecodingString(void)
{
    printf("Enter the string");
    std::string inputData;
    std::getline(std::cin >> std::ws, inputData);
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Decode(inputData);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-From_String-Decoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    };
};

void myBase64Encoding(void)
{
    std::string inputFilename;
    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Encode(Tanja84dk::tools::read_file(inputFilename));

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Encoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
};

void myBase64Encoding(const std::string &data)
{
    bool statusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = Base64::Encode(data);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}
