#include "blocksequence.h"

BlockSequence::BlockSequence(){
   
}

int BlockSequence::size()
{
    return BlockSequenceVector.size();
}


void BlockSequence::erase(Block target_block)
{

}

//Inserts a block and sorts it
void BlockSequence::insert(Block new_block)
{
    BlockSequenceVector.push_back(new_block);
    std::sort(BlockSequenceVector.begin(), BlockSequenceVector.end());

}
