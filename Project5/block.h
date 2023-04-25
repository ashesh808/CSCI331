#ifndef BLOCK_H
#define BLOCK_H

#include "zipcode.h"
#include <iostream>
#include <string>
#include <vector>

class Block{
    public:
        Zipcode records[5];
        void clear();
        Block();
        void insertRecord(Zipcode new_record);
        void eraseRecord(Zipcode new_record);
        Block* splitBlock(Zipcode new_record);
        Block* mergeBlock(Block otherBlock);
        Block* redistribute(Block otherBlock);
        int getRecordCount();
        void setRecordCount(int new_count);
        void display();

    private:
        int record_count;
};

#include "block.cpp"
#endif