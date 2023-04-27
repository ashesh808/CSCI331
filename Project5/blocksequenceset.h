#ifndef BLOCKSEQUENCE_H
#define BLOCKSEQUENCE_H

#include "zipcode.h"
#include <vector>

#ifndef FALSE
#define FALSE(0)
#define TRUE(1)
#endif

class BlockSequenceSet
{
    public:
        BlockSequenceSet();
        void insertBlock(int index);
        void eraseBlock(int index);
        void splitBlock(int index);
        void mergeBlock(int index_one, int index_two);
        //void redistributeBlocks();
        int getActiveBlockCount();
        void setActiveBlockCount(int new_count);
        int getAvailableBlockCount();
        void setAvailableBlockCount(int new_count);
        int getTotalBlockCount();
    private:
        int active_block_count;
        int available_block_count;

        class Block{
            public:
                Zipcode records[4];
                Block();
                void insertRecord(Zipcode new_record);
                void eraseRecord(Zipcode new_record);
                int getRecordCount();
                void setRecordCount(int new_count);
            private:
                int record_count;
                Block * next;
                Block * previous;
        };

        Block * first;
        std::vector<Block> active_blocks;
        std::vector<Block> available_blocks;

};

#include "blocksequenceset.cpp"
#endif