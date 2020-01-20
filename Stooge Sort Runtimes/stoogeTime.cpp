//
//  stoogeTime.cpp
//  CS325HWProblem3
//
//  Created by Ryan Farran on 10/7/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#include "stoogeTime.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>
#include <time.h>

using std::cout;
using std::endl;

void StoogeTime::printArray(int* arrayToPrint, int sizeOfArray)
{
    for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++)
    { //simply prints each array element followed by space
        std::cout << arrayToPrint[arrayIndex] << " ";
    }
    std::cout << std::endl << std::endl;
}

//Recursive case
void StoogeTime::recursiveStoogeSort(int* arrayToSort, int begIndex, int endIndex)
{
    if (begIndex >= endIndex)
    {
        return; //recursion "bottoms out"
    }
    if (arrayToSort[begIndex] > arrayToSort[endIndex])
    { //Swap arrayToSort[begIndex] & arrayToSort[endIndex] if lower index > higher index
        int temp = arrayToSort[begIndex];
        arrayToSort[begIndex] = arrayToSort[endIndex];
        arrayToSort[endIndex] = temp;
    }
    if ((endIndex - begIndex + 1 ) > 2)
    {
        int thirdIndex = (endIndex - begIndex + 1) / 3;
        recursiveStoogeSort(arrayToSort, begIndex, (endIndex - thirdIndex)); //Recursively sort first 2/3rds
        recursiveStoogeSort(arrayToSort, (begIndex + thirdIndex), endIndex); //Recursively sort last 2/3rds
        recursiveStoogeSort(arrayToSort, begIndex, (endIndex - thirdIndex)); //Recursively sort first 2/3rds
    }
}
