//
//  insertTime.cpp
//  CS325HWProblem3
//
//  Created by Ryan Farran on 10/7/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#include "insertTime.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>
#include <time.h>

using std::cout;
using std::endl;

void InsertTime::printArray(int* arrayToPrint, int sizeOfArray)
{
    for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++)
    { //simply prints each array element followed by space
        std::cout << arrayToPrint[arrayIndex] << " ";
    }
    std::cout << std::endl << std::endl;
}

void InsertTime::insertionSorter(int* arrayToSort, int sizeOfArray)
{
    int leadingIndex, key, trailingIndex;
    for(leadingIndex = 1; leadingIndex < sizeOfArray; leadingIndex++)
    {
        key = arrayToSort[leadingIndex];
        trailingIndex = leadingIndex - 1;
        
        while (trailingIndex >= 0 && arrayToSort[trailingIndex] > key)
        {
            arrayToSort[trailingIndex + 1] = arrayToSort[trailingIndex];
            trailingIndex -= 1;
        }
        arrayToSort[trailingIndex + 1] = key;
    }
}
