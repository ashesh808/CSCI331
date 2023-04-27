#ifndef BLOCKSEQUENCE_H
#define BLOCKSEQUENCE_H

#include "zipcode.h"
#include "block.h"
#include <algorithm>

class BlockSequence
{
public:
    BlockSequence();
    int size();
    void insert(Block target_block);
    void erase(Block new_block);
    void dumpPhysical();
    void dumpLogical();
private:
    std::vector<Block> BlockSequenceVector;
    std::vector<Block> available_blocks;
};

#include "blocksequence.cpp"
#endif