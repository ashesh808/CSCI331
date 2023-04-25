#include "blocksequence.h"

BlockSequence::BlockSequence(){
    first = NULL;
    block_sequence_size = 0;
}

int BlockSequence::size(){
    return block_sequence_size;
}

BlockSequence::Block::Block(Zipcode new_records[4]){
    for(int i = 0; i < 4; i++){
        if(new_records[i] != NULL){records[i] == new_records[i]};
    }
    
    next = NULL;
}

void BlockSequence::insert(int index, Zipcode new_records[4]){
    block_pointer nPtr;
    nPtr = new(nothrow) Block(new_records[4]);
    if(index < 0 || index > block_sequence_size){std::cout<< index " is an invalid index!" << std::endl}
    else{
        if(index == 0){
            nPtr->next = first;
            first->previous = nPtr;
            first = nPtr;
        }
        else{
            block_pointer predPtr = first;
            for(int i = 1; i < index - 1; i++){
                predPtr = predPtr->next;
            }
            
            nPtr->next = predPtr->next;
            predPtr->next = nPtr;
            nPtr->previous = predPtr;
            predPtr = nPtr->next;
            predPtr->previous = nPtr;
        }
        block_sequence_size++;
    }
}
