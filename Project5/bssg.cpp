/**
 * @file bssg.cpp (Blocked Sequence Set Generator)
 * @brief This program takes the data files from project 4 as an input and generates a blocked sequence set file
 * @version 0.1
 * @date 2023-04-26
 * \author Steven Kraus
 * \author Emily Yang
 * \author Tyler Knudtson
 * \author Ashesh Nepal
 */

#include <iostream>
#include <fstream>
#include "blocksequence.h"

int main(int argc, char *argv[])
{
    std::string data_file;
    int block_size;
    std::string header_info;

    // Parse command line arguments
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg == "--data_file" && i + 1 < argc)
        {
            data_file = argv[i + 1];
        }
        else if (arg == "--block_size" && i + 1 < argc)
        {
            block_size = std::stoi(argv[i + 1]);
        }
        else if (arg == "--header_info" && i + 1 < argc)
        {
            header_info = argv[i + 1];
        }
    }

    // Do something with the command line options
    std::cout << "Data file: " << data_file << std::endl;
    std::cout << "Block size: " << block_size << std::endl;
    std::cout << "Header info: " << header_info << std::endl;

    return 0;
}

/**
 * This program expects three command line options:
   --data_file: the name of the blocked sequence set data file (a string)
   --block_size: the size of each block (an integer)
   --header_info: any other information necessary for the header file (a string)
   **/