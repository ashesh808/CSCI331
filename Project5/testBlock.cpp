#include <iostream>
#include <fstream>
#include "block.h"
#include <vector>
#include <algorithm>

static const int HEADER_FIELDS = 17;

/** readFileWithHeaderLength
 @param Zipcode array zArray
 @param DelimTextBuffer InBuff
 @param string InFileName
 @pre a DelimTextBuffer object must exist
 @post the given file InFileName is opened and the header is unpacked into headerArray then
        the rest of the file is read into the InBuff buffer. The contents of the buffer are
        then unpacked into zArray*/
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

    /*
    if(headerArray[FILE_STRUCTURE_TYPE]!="FileType=CSV"||headerArray[VERSION]!="Version=1.0"){
        std::cout <<"INCOMPATIBLE FILE!" << std::endl;
        return 0;
    }*/

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

int main()
{
    // START GENERATE BLOCK SEQUENCE
    std::vector<Block> active_blocks;
    std::vector<Block> available_blocks;
    DelimTextBuffer InBuff;
    Zipcode zArray[45000];
    std::string InFileName = "us_postal_codes_ROWS_RANDOMIZED.csv";
    int zIndex = readFileWithHeaderLength(zArray, InBuff, InFileName);
    std::sort(zArray, zArray + zIndex);
    Block inital;
    inital.block_id = 1;
    active_blocks.push_back(inital);

    for (int i = 0; i < zIndex; i++)
    {
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
        active_blocks[i].display();
    }
    // END DISPLAY BLOCK SEQUENCE

    // START OUTPUT BLOCK SEQUENCE
    std::string OutFileName = "blocksequencesetfile.csv";
    DelimTextBuffer OutBuff;
    std::ofstream OutFile(OutFileName, std::ios::out);
    for (int i = 0; i < active_blocks.size(); i++)
    {
        OutBuff.Clear();
        active_blocks[i].Pack(OutBuff);
        OutBuff.Write(OutFile);
    }
    // END OUTPUT BLOCK SEQUENCE

    active_blocks.clear();

    // START READ BLOCK SEQUENCE FILE
    DelimTextBuffer TestBuff;
    TestBuff.Init(',');
    std::ifstream InFile("test.csv", std::ios::in);
    if (InFile.fail())
    {
        std::cout << "error opening csv" << std::endl;
        return 1;
    }
    while (InFile.peek() != EOF)
    {
        std::cout << "Looping" << std::endl;
        TestBuff.Read(InFile);
        Block newTestBlock;
        newTestBlock.Unpack(TestBuff);
        active_blocks.push_back(newTestBlock);
    }
    // END READ BLOCK SEQUENCE FILE

    // START DISPLAY BLOCK SEQUENCE
    for (int i = 0; i < active_blocks.size(); i++)
    {
        active_blocks[i].display();
    }

    /*
    Zipcode one;
    Zipcode two;
    Zipcode three;
    Zipcode four;
    Zipcode five;
    Zipcode split;
    char test1[10] = "1000";
    char test2[10] = "2000";
    char test3[10] = "3000";
    char test4[10] = "4000";
    char test5[10] = "5000";
    char testsplit[10] = "2224";
    strcpy(one.Code, test1);
    strcpy(two.Code, test2);
    strcpy(three.Code, test3);
    strcpy(four.Code, test4);
    strcpy(five.Code, test5);
    strcpy(split.Code, testsplit);
    Block testBlock;
    Block* newBlock;
    testBlock.insertRecord(three);
    testBlock.insertRecord(one);
    testBlock.insertRecord(four);
    testBlock.insertRecord(two);
    testBlock.insertRecord(five);
    testBlock.display();
    newBlock = testBlock.splitBlock(split);
    std::cout << "Old block looks like this \n";
    testBlock.display();
    std::cout << "new block looks like this \n";
    newBlock->display();
    */

    return 0;
}