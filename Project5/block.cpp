#include "block.h"

void Block::clear()
{
    record_count = 0;
}

Block::Block()
{
    clear();
}

// pre: record count less than 5
void Block::insertRecord(Zipcode new_record)
{
    //std::cout << " insert";
    int i = record_count - 1;
    while (i >= 0 && std::stoi(records[i].Code) > std::stoi(new_record.Code))
    {
        records[i + 1] = records[i];
        i--;
    }
    records[i + 1] = new_record;
    record_count++;
}

// pre: record count less than 5
void Block::display()
{
    std::cout << "Block ID " << block_id << ": "<< std::endl;
    for (int i = 0; i < record_count; i++)
    {
        std::cout << records[i].Code << "\n";
    }
}

void Block::eraseRecord(Zipcode recordToDelete)
{
    int indexToDelete = -1;

    // Find the index of the record to delete
    for (int i = 0; i < record_count; i++)
    {
        if (records[i] == recordToDelete)
        {
            indexToDelete = i;
            break;
        }
    }

    // If the record to delete was found, remove it from the array
    if (indexToDelete != -1)
    {
        for (int i = indexToDelete; i < record_count - 1; i++)
        {
            records[i] = records[i + 1];
        }
        record_count--;
    }
}

Block *Block::splitBlock(Zipcode newRecord)
{
    Block *newblock = new Block();
    Zipcode lastRecord = records[4];
    Zipcode secondLastRecord = records[3];
    Zipcode thirdLastRecord = records[2];
    newblock->insertRecord(lastRecord);
    newblock->insertRecord(secondLastRecord);
    eraseRecord(lastRecord);
    eraseRecord(secondLastRecord);
    newblock->insertRecord(newRecord);
    std::cout << "Split block event \n";
    return newblock;
}

void Block::mergeBlock(Block otherBlock)
{
    for (int i = 0; i < record_count; i++)
    {
        otherBlock.insertRecord(records[i]);
    }
    clear();
}

Block *redistribute(Block otherBlock)
{
}

int Block::getRecordCount()
{
    return record_count;
}

void Block::setRecordCount(int new_count)
{
    record_count = new_count;
}

//if underflow then merge
bool Block::isUnderflow()
{
    return (record_count < 3);
}

//if overflow then split
bool Block::isOverflow()
{
    return (record_count == 5);
}

bool Block::isEmpty()
{
    return (record_count == 0);
}

Zipcode Block::getFrontRecord() const{
    return records[0];
}

Zipcode Block::getBackRecord () const {
    return records[record_count-1];
}

int Block::Pack(DelimTextBuffer& Buffer)const{
    int result;
    Buffer.Clear();
    result = Buffer.Pack((std::to_string(block_id)).c_str());
    for(int i = 0; i < record_count; i++){
        result = Buffer.Pack(records[i].Code);
    }

    return result;
}

int Block::Unpack(DelimTextBuffer & Buffer){
    int result;
    result = Buffer.Unpack(block_id);
    int i = 0;
    result = result && Buffer.Unpack(records[0].Code);
    result = result && Buffer.Unpack(records[1].Code);
    result = result && Buffer.Unpack(records[2].Code);
    result = result && Buffer.Unpack(records[3].Code);
    result = result && Buffer.Unpack(records[4].Code);

}