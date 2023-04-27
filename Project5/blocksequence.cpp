#include "blocksequence.h"

BlockSequence::BlockSequence(){
   BlockSequenceVector.clear();
   available_blocks.clear();
}

int BlockSequence::size()
{
    return BlockSequenceVector.size();
}


void BlockSequence::erase(Block target_block)
{
    available_blocks.push_back(target_block);
}

//Inserts a block and sorts it
void BlockSequence::insert(Block new_block)
{
    BlockSequenceVector.push_back(new_block);
}

void BlockSequence::dumpPhysical()
{
 for (int i = 0; i < BlockSequenceVector.size(); i++) {
        const Block block = BlockSequenceVector[i];
        int rbm = block.block_id;
        int prev = (i > 0) ? BlockSequenceVector[i-1].block_id : 0;
        int next = (i < BlockSequenceVector.size()-1) ? BlockSequenceVector[i+1].block_id : 99999;
        std::cout << "Block " << i << ": ZIP codes " << std::string((BlockSequenceVector[i].getBackRecord()).Code) << "-" << block.block_id;
        std::cout << " (RBM=" << rbm << ", prev=" << prev << ", next=" << next << ")" << "\n";
    }
}

void BlockSequence::dumpLogical()
{
    std::vector<int> order(BlockSequenceVector.size());
    for (int i = 0; i < BlockSequenceVector.size(); i++) {
        order[BlockSequenceVector[i].block_id] = i;
    }
    for (int i = 0; i < BlockSequenceVector.size(); i++) {
        const Block block = BlockSequenceVector[order[i]];
        int rbm = i;
        int prev = (i > 0) ? BlockSequenceVector[i-1].block_id : 0;
        int next = (i < BlockSequenceVector.size()-1) ? BlockSequenceVector[i+1].block_id : 99999;
        std::cout << "Block " << i << ": ZIP codes " << std::string((BlockSequenceVector[i].getBackRecord()).Code) << "-" << block.block_id; 
        std::cout << " (RBM=" << rbm << ", prev=" << prev << ", next=" << next << ")" << "\n";
    }

}