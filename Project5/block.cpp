#include "block.h"


void Block::clear()
{
    record_count = 0;
}

Block::Block(){
    clear();
}

//pre: record count less than 5 
void Block::insertRecord(Zipcode new_record){
    int i = record_count - 1;
    while(i >= 0 && std::stoi(records[i].Code) > std::stoi(new_record.Code)){
        records[i+1] = records[i];
        i--;
    }
    records[i+1] = new_record;
    record_count++;
}

//pre: record count less than 5 
void Block::display(){
    for(int i = 0; i < 5; i++)
    {
        std::cout << records[i].Code << "\n";
    }
}

void Block::eraseRecord(Zipcode del_record)
{
    std::vector<Zipcode> newrecords;
    for (int i = 0; i < record_count; i++)
    {
        if (del_record != records[i])
        {
            newrecords.push_back(records[i]);
        }
    }
    clear();
    for (int j = 0; j < newrecords.size(); j++)
    {
       insertRecord(newrecords[j]);
    }
}

Block* Block::splitBlock(Zipcode newRecord)
{
    Block* newblock = new Block();
    newblock->insertRecord(records[4]);
    newblock->insertRecord(records[3]);
    Zipcode lastRecord = records[4];
    Zipcode secondlastRecord = records[3];

    eraseRecord(lastRecord);
    eraseRecord(secondlastRecord);
    insertRecord(newRecord);
    return newblock;
}

Block* mergeBlock(Block otherBlock)
{

}

Block* redistribute(Block otherBlock)
{

}

int Block::getRecordCount(){
 return record_count;
}

void Block::setRecordCount(int new_count){
    record_count = new_count;
}