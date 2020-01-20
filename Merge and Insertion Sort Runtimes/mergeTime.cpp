//
//  mergeTime.cpp
//  CS325HWProblem3
//
//  Created by Ryan Farran on 10/7/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#include "mergeTime.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>
#include <time.h>

using std::cout;
using std::endl;

void MergeTime::printArray(int* arrayToPrint, int sizeOfArray)
{
    for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++)
    { //simply prints each array element followed by space
        std::cout << arrayToPrint[arrayIndex] << " ";
    }
    std::cout << std::endl << std::endl;
}

void MergeTime::baseMerge(int* arrayToSort, int begIndex, int middleIndex, int endIndex)
{
    int leftArraySize = middleIndex - begIndex + 1;
    int rightArraySize = endIndex - middleIndex;
    int leftArray[leftArraySize], rightArray[rightArraySize];
    for (int leftArrayIndex = 0; leftArrayIndex < leftArraySize; leftArrayIndex++)
    {
        leftArray[leftArrayIndex] = arrayToSort[begIndex + leftArrayIndex];
    }
    for (int rightArrayIndex = 0; rightArrayIndex < rightArraySize; rightArrayIndex++)
    {
        rightArray[rightArrayIndex] = arrayToSort[middleIndex + 1 + rightArrayIndex];
    }
    int leftIndex = 0;
    int rightIndex = 0;
    int originalIndex = begIndex;
    while (leftIndex < leftArraySize && rightIndex < rightArraySize)
    {
        if(leftArray[leftIndex] <= rightArray[rightIndex])
        {
            arrayToSort[originalIndex] = leftArray[leftIndex];
            leftIndex++;
        }
        else
        {
            arrayToSort[originalIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        originalIndex++;
    }
     while (leftIndex < leftArraySize)
     {
         arrayToSort[originalIndex] = leftArray[leftIndex];
         leftIndex++;
         originalIndex++;
     }
    
     while (rightIndex < rightArraySize)
     {
         arrayToSort[originalIndex] = rightArray[rightIndex];
         rightIndex++;
         originalIndex++;
     }
}

//Recursive case with base case Merge subroutine
void MergeTime::recursiveMergeSort(int* arrayToSort, int begIndex, int endIndex)
{
    if (begIndex < endIndex)
    {
        //Calculation for middle index avoids overflow for large inputs
        //SOURCE: https://www.geeksforgeeks.org/merge-sort/
        int middleIndex = begIndex + (endIndex - begIndex) / 2;
        recursiveMergeSort(arrayToSort, begIndex, middleIndex);
        recursiveMergeSort(arrayToSort, middleIndex + 1, endIndex);
        baseMerge(arrayToSort, begIndex, middleIndex, endIndex);
    }
}
