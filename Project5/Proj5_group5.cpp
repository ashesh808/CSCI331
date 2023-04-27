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
#include <vector>
#include <algorithm>
#include "block.h"
#include "blocksequence.h"


static const int HEADER_FIELDS = 17;


int readFileWithHeaderLength(Zipcode zArray[], DelimTextBuffer InBuff, std::string InFileName)
{
    std::ifstream InFile(InFileName, std::ios::in);
    if (InFile.fail())
    {
        std::cout << "error opening csv" << std::endl;
        return 0;
    }
    Zipcode::InitBuffer(InBuff);
    int index = 0;
    int pos = 0;
    char temp[100];

    pos = InBuff.ReadHeader(InFile);
    for (int i = 0; i < HEADER_FIELDS; i++)
    {
        InBuff.UnpackHeader(temp);
        // headerArray[i] = temp;
    }

    InFile.seekg(pos);
    while (InFile.peek() != EOF)
    {
        InBuff.Read(InFile);
        zArray[index].Unpack(InBuff);
        index++;
    }
    InFile.close();

    return index;
}

void generateSimpleIndex(const std::vector<Block> &active_blocks)
{
    std::string indexFileName = "simpleindex.txt";
    std::ofstream output_file(indexFileName);
    for (int i = 0; i < active_blocks.size(); i++)
    {
        output_file << active_blocks[i].block_id << " " << std::string((active_blocks[i].getBackRecord()).Code) << "\n";
    }
    output_file.close();
}

void generateBlockFile(std::string input_file)
{
    // START GENERATE BLOCK SEQUENCE

    std::vector<Block> active_blocks;
    std::vector<Block> available_blocks;
    BlockSequence blocksequenceset;
    DelimTextBuffer InBuff;
    Zipcode zArray[45000];
    std::string InFileName = input_file;
    int zIndex = readFileWithHeaderLength(zArray, InBuff, InFileName);
    std::sort(zArray, zArray + zIndex);
    Block inital;
    inital.block_id = 1;
    active_blocks.push_back(inital);

    for (int i = 0; i < zIndex; i++)
    {
        //Split if there is an overflow condition
        if (active_blocks[active_blocks.size() - 1].isOverflow())
        {
            Block *newBlockPtr = active_blocks[active_blocks.size() - 1].splitBlock(zArray[i]);
            Block newBlock = *newBlockPtr;
            newBlock.block_id = active_blocks.size() + 1;
            active_blocks.push_back(newBlock);
        }
        else
        {
            active_blocks[active_blocks.size() - 1].insertRecord(zArray[i]);
        }
    }
    // END GENERATE BLOCK SEQUENCE

    // START DISPLAY BLOCK SEQUENCE
    for (int i = 0; i < active_blocks.size(); i++)
    {
        blocksequenceset.insert(active_blocks[i]);

    }
    // END DISPLAY BLOCK SEQUENCE

    // START OUTPUT BLOCK SEQUENCE
    std::string OutFileName = "test.csv";
    DelimTextBuffer OutBuff;
    std::ofstream OutFile(OutFileName, std::ios::out);
    for (int i = 0; i < active_blocks.size(); i++)
    {
        OutBuff.Clear();
        active_blocks[i].Pack(OutBuff);
        OutBuff.Write(OutFile);
    }
    // END OUTPUT BLOCK SEQUENCE
    generateSimpleIndex(active_blocks);

    std::cout << "Doing a logical dump";
    blocksequenceset.dumpLogical();
    std::cout << "Doing a physical dump";
    blocksequenceset.dumpPhysical();
}


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
    generateBlockFile(data_file);
    return 0;
}

/**
 * This program expects three command line options:
   --data_file: the name of the blocked sequence set data file (a string)
   --block_size: the size of each block (an integer)
   --header_info: any other information necessary for the header file (a string)
   **/