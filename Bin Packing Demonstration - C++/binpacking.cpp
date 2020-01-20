//
//  binpacking.cpp
//  CS325HW8
//
//  Created by Ryan Farran on 12/4/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#include "binpacking.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void BinPacking::multiLineHandler(std::string inputFileName)
{
    //Create arrays for storing information.
    MergeSort merge; //used to call stack and merge functions
    
    int numOfNumbers = merge.countNumberOfCharactersInFile(inputFileName);
    
    std::ifstream inputFile;
    inputFile.open(inputFileName.c_str()); //opens file using name passed as parameter
    if (!inputFile)
    {
        cout << "Unable to open " << inputFileName << endl; //explains issue if error opening
    }
    else
    {
        DynArr* storingArray;
        storingArray = merge.newDynArr(numOfNumbers);
        //Outer whiel loop until EOF
        while (!inputFile.eof())
        { //reads data from file into array
            int temp;
            inputFile >> temp;
            merge.addDynArr(storingArray, temp);
        }
        int numOfTestCases = merge.getDynArr(storingArray, 0);
        
        int caseNumber = 1;
        int index = 1;
        while (index < numOfNumbers-1)
        {
            int currentCapacity = merge.getDynArr(storingArray, index);
            index++;
            int currentNumOfItems = merge.getDynArr(storingArray, index);
            index++;
            DynArr* itemArray;
            itemArray = merge.newDynArr(currentNumOfItems + 5);
            int copy = currentNumOfItems;
            while (copy != 0)
            {
                copy--;
                merge.addDynArr(itemArray, merge.getDynArr(storingArray, index));
                index++;
            }
            cout << "Test Case " << caseNumber++;
            //merge.printDynArrayToConsole(itemArray, currentNumOfItems);
            
            //Need to call Bin Functions here...
            clock_t t;
            t = clock();
            int currentNumberOfBinsFirstFit = firstFit(itemArray, currentNumOfItems, currentCapacity);
            t = clock() - t;
            double timeElapsed = ((double)t) / CLOCKS_PER_SEC;
            cout << " First Fit: " << currentNumberOfBinsFirstFit << ", " << timeElapsed << " seconds. ";
            
            t = clock();
            int currentNumberOfBinsFirstFitDec = firstFitDec(itemArray, currentNumOfItems, currentCapacity);
            t = clock() - t;
            timeElapsed = ((double)t) / CLOCKS_PER_SEC;
            cout << " First Fit Decreasing: " << currentNumberOfBinsFirstFitDec << ", " << timeElapsed << " seconds. ";
            
            t = clock();
            int currentNumberOfBinsBestFit = bestFit(itemArray, currentNumOfItems, currentCapacity);
            t = clock() - t;
            timeElapsed = ((double)t) / CLOCKS_PER_SEC;
            cout << " Best Fit: " << currentNumberOfBinsBestFit << ", " << timeElapsed << " seconds. " << endl;
            
            
            merge.deleteDynArr(itemArray);
        }
        
    }
    inputFile.close(); //closes file
}


int BinPacking::firstFit(DynArr* itemArray, int numberOfItems, int capacity)
{
    MergeSort merge;
    int numberOfBins = 0;
    int spaceLeftInBin[numberOfItems];

    for (int index1 = 0; index1 < numberOfItems; index1++)
    {
        int index2;
        for (index2 = 0; index2 < numberOfBins; index2++)
        {
            if (spaceLeftInBin[index2] >= merge.getDynArr(itemArray, index1))
            {
                spaceLeftInBin[index2] = spaceLeftInBin[index2] - merge.getDynArr(itemArray, index1);
                break;
            }
        }
        if (index2 == numberOfBins)
        {
            spaceLeftInBin[numberOfBins] = capacity - merge.getDynArr(itemArray, index1);
            numberOfBins++;
        }
    }
    return numberOfBins;
}

int BinPacking::firstFitDec(DynArr* itemArray, int numberOfItems, int capacity)
{
    MergeSort merge;
    cout << endl;
    //merge.printDynArrayToConsole(itemArray, numberOfItems);
    int arraytoSort[numberOfItems];
    for (int index = 0; index < numberOfItems; index++)
    {
        arraytoSort[index] = merge.getDynArr(itemArray, index);
    }
    merge.recursiveMergeSort(arraytoSort, 0, numberOfItems - 1);
    //merge.printArrayToConsole(arraytoSort, numberOfItems);
    int reversedArray[numberOfItems];
    int otherIndex = 0;
    for (int index = numberOfItems - 1; index >= 0; index--)
    {
        reversedArray[index] = arraytoSort[otherIndex];
        otherIndex++;
    }
    //merge.printArrayToConsole(reversedArray, numberOfItems);
    for (int index = 0; index < numberOfItems; index++)
    {
        merge.putDynArr(itemArray, index, reversedArray[index]);
    }
    return firstFit(itemArray, numberOfItems, capacity);
}

int BinPacking::bestFit(DynArr* itemArray, int numberOfItems, int capacity)
{
    MergeSort merge;
    int numberOfBins = 0;
    int spaceLeftInBin[numberOfItems];
    for (int index1 = 0; index1 < numberOfItems; index1++)
    {
        int index2;
        int min = capacity + 1, bi = 0;
        for (index2 = 0; index2 < numberOfBins; index2++)
        {
            if (spaceLeftInBin[index2] >= merge.getDynArr(itemArray, index1) && spaceLeftInBin[index2] - merge.getDynArr(itemArray, index1) < min)
            {
                bi = index2;
                min = spaceLeftInBin[index2] - merge.getDynArr(itemArray, index1);
            }
        }
        if (min == capacity + 1)
        {
            spaceLeftInBin[numberOfBins] = capacity - merge.getDynArr(itemArray, index1);
            numberOfBins++;
        }
        else
        {
            spaceLeftInBin[bi] -= merge.getDynArr(itemArray, index1);
        }
    }
    return numberOfBins;
}


