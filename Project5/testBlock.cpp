#include <iostream>
#include <fstream>
#include "block.h"

int main()
{
    Zipcode one;
    Zipcode two;
    Zipcode three;
    Zipcode four;
    Zipcode five;
    Zipcode split;

    char test1[10] = "1000";
    char test2[10] = "2000";
    char test3[10] = "3000";
    char test4[10] = "4000";
    char test5[10] = "5000";
    char testsplit[10] = "2224";


    strcpy(one.Code, test1);
    strcpy(two.Code, test2);
    strcpy(three.Code, test3);
    strcpy(four.Code, test4);
    strcpy(five.Code, test5);
    strcpy(split.Code, testsplit);


    Block testBlock;
    Block* newBlock;

    testBlock.insertRecord(three);
    testBlock.insertRecord(one);
    testBlock.insertRecord(four);
    testBlock.insertRecord(two);
    testBlock.insertRecord(five);
    testBlock.display();

    newBlock = testBlock.splitBlock(split);

    std::cout << "Old block looks like this \n";
    testBlock.display();

    std::cout << "new block looks like this \n";
    newBlock->display();

    return 0;
}