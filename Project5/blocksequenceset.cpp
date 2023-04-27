#include "blocksequenceset.h"

BlockSequenceSet::BlockSequenceSet(){
    first = NULL;
    active_block_count = 0;
    available_block_count = 0;
}

void BlockSequenceSet::insertBlock(int index){
    //define insertBlock
    Block * new_block_pointer;
    new_block_pointer = new(std::nothrow) Block();
    if(index < 0 || index > this.getTotalBlockCount()){
        std::cout << index << "is an invalid index!" << std::endl;
    }
    else{
        if(index == 0){
            new_block_pointer->next = first;
            first->previous = new_block_pointer;
            first = new_block_pointer;
        }
        else{
            Block * interating_block_pointer = first;
            for(int i = 1; i < index - 1; i++){
                iterating_block_pointer = iterating_block_pointer->next;
            }
            new_block_pointer->next = iterating_block_pointer->next;
            new_block_pointer->previous = iterating_block_pointer;
            iterating_block_pointer->next = new_block_pointer;
            iterating_block_pointer = iterating_block_pointer->next;
            iterating_block_pointer->previous = new_block_pointer;
        }
    }
    available_blocks.insert(available_blocks.begin()+index,*new_block_pointer);
    available_block_count++;
}

void BlockSequenceSet::eraseBlock(int index){
    //define eraseBlock
}

void BlockSequenceSet::splitBlock(int index){
    //define splitBlock
}

void BlockSequenceSet::mergeBlock(int index_one, int index_two){
    //define mergeBlock
}

void BlockSequenceSet::redistributeBlocks(){
    //define redistributeBlock
}

int BlockSequenceSet::getActiveBlockCount(){
    //define getActiveblockCount
    return active_block_count;
}

void BlockSequenceSet::setActiveBlockCount(int new_count){
    //define setActiveBlockCount
    active_block_count = new_count;
}

int BlockSequenceSet::getAvailableBlockCount(){
    //define getAvailableBlockCount
    return available_block_count;
}

void BlockSequenceSet::setAvailableBlockCount(int new_count){
    //define setAvailableBlockCount
    available_block_count = new_count;
}

int BlockSequenceSet::getTotalBlockCount(){
    return active_block_count + available_block_count;
}

//BLOCK CLASS

BlockSequenceSet::Block::Block(){
    record_count = 0;
    next = NULL;
    previous = NULL;
}

void BlockSequenceSet::Block::insertRecord(Zipcode new_record){
    //define insertRecord
    for(int i = 0; i < active_blocks.size(); i++){
        if(active_blocks[i]<new_record.zipcode){found = true;}
    }
    
}

void BlockSequenceSet::Block::eraseRecord(Zipcode new_record){
    //define eraseRecord
}

int BlockSequenceSet::Block::getRecordCount(){
    //define getRecordCount
    return record_count;
}

void BlockSequenceSet::Block::setRecordCount(int new_count){
    //define setRecordCount
    record_count = new_count;
}