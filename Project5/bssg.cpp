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

//Data about file specifications
std::string file_name;
std::string index_file_name;
int record_count;
int block_count;
int field_count;
int primary_key_field;
int block_size = 512;
double min_block_capacity = 0.5;

void menu()
{

    // Prompt user for file name
    std::cout << "Enter the name of the blocked sequence set data file: ";
    std::cin >> file_name;

    // Prompt user for index file name
    std::cout << "Enter the name of the index file: ";
    std::cin >> index_file_name;

    // Prompt user for record count
    std::cout << "Enter the number of records in the data file: ";
    std::cin >> record_count;

    // Prompt user for block count
    block_count = record_count / (block_size * min_block_capacity);
    if (record_count % static_cast<int>(block_size * min_block_capacity) != 0)
    {
        block_count++;
    }
    std::cout << "Number of blocks in the data file: " << block_count << std::endl;

    // Prompt user for field count
    std::cout << "Enter the number of fields per record: ";
    std::cin >> field_count;

    // Prompt user for primary key field
    std::cout << "Enter the ordinal number of the field that serves as the primary key: ";
    std::cin >> primary_key_field;
}

int main()
{
    menu();
    return 0;
}
