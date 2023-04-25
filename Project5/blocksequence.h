#ifndef BLOCKSEQUENCE_H
#define BLOCKSEQUENCE_H

#include "zipcode.h"

#ifndef FALSE
#define FALSE(0)
#define TRUE(1)
#endif

class BlockSequence
{
    public:

    BlockSequence();

    int size();

    void insert(int index, Zipcode new_records[4]);

    void erase(int index);

    ~BlockSequence();

    private:
        class Block
        {
            public:
            Zipcode records[4];
            Block * next;
            Block * previous;

            Block(Zipcode new_records[4]);

            void insert(int index, Zipcode new_record);

            void erase(int index);

        };

    typedef Block * block_pointer;

    block_pointer first;
    int block_sequence_size;

};

#endif