#ifndef BLOCK_H
#define BLOCK_H

#include "zipcode.h"
#include <iostream>
#include <string>
#include <vector>

class Block
{
public:
    Zipcode records[5];
    int block_id;
    void clear();
    Block();
    void insertRecord(Zipcode new_record);
    void eraseRecord(Zipcode new_record);
    Block *splitBlock(Zipcode new_record);
    void mergeBlock(Block otherBlock);
    Block *redistribute(Block otherBlock);
    int getRecordCount();
    void setRecordCount(int new_count);
    bool isUnderflow();
    bool isOverflow();
    bool isEmpty();
    void display();
    Zipcode getFrontRecord() const;
    Zipcode getBackRecord() const;
    int Unpack(DelimTextBuffer &);
    int Pack(DelimTextBuffer &) const;

    // Less-than comparison operator
    bool operator<(const Block &other) const
    {
        // If record counts are equal, compare the first record
        if (std::stoi(records[0].Code) < std::stoi(other.records[0].Code))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Assignment operator
    Block &operator=(const Block &other)
    {
        // Check for self-assignment
        if (this == &other)
        {
            return *this;
        }

        // Copy the records
        for (int i = 0; i < 5; i++)
        {
            records[i] = other.records[i];
        }

        // Copy the block ID and record count
        block_id = other.block_id;
        record_count = other.record_count;

        return *this;
    }

private:
    int record_count;
};

#include "block.cpp"
#endif