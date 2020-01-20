//
//  shopping.hpp
//  CS325HW3P4
//
//  Created by Ryan Farran on 10/21/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#ifndef shopping_hpp
#define shopping_hpp

#ifndef __TYPE
#define __TYPE
# define TYPE      char
# define TYPE_SIZE sizeof(int)
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

#include <stdio.h>
#include <string>

class Shopping
{
public:
    std::string aestheticLine = "---------------------------------------------------------------"; //Used to visually seperate console output
    std::string aestheticLine2 = "***************************************************************";
    typedef struct DynArr DynArr;
public:
    int countNumberOfCharactersInFile(std::string inputFileName);
    int countNumberOfNewLinesInFile(std::string inputFileName);
    void readValuesFromFile(std::string inputFileName, int* storingArray);
    void printArrayToConsole(const int* arrayToPrint, int sizeOfArray);
    void printDynArrayToConsole(DynArr* arrayToPrint, int sizeOfArray);
    void multiLineHandler(const int* arrayToHandle, int sizeOfArray);
    void outputValuesToFile(DynArr* sortedArray, int sizeOfArray);

    
    int knapSack(int maxWeight, DynArr*, DynArr*, int sizeOfArray, DynArr* itemList);
    
    int convertCharToInt(char charToConvert);
    DynArr* convertIntArrayToDynArr(const int* arrayToAdd, int sizeOfArray);
    void addToFinalArray(DynArr* arrayToAddTo, DynArr* arrayToAdd, int sizeOfArray);
    
    
    //STACK CODE BELOW
    /* Dynamic Array Functions */
    void initDynArr(DynArr *v, int capacity);
    DynArr *newDynArr(int cap);

    void freeDynArr(DynArr *v);
    void deleteDynArr(DynArr *v);

    int sizeDynArr(DynArr *v);

    void addDynArr(DynArr *v, TYPE val);
    TYPE getDynArr(DynArr *v, int pos);
    void putDynArr(DynArr *v, int pos, TYPE val);
    void swapDynArr(DynArr *v, int i, int  j);
    void removeAtDynArr(DynArr *v, int idx);

    /* Stack interface. */
    int isEmptyDynArr(DynArr *v);
    void pushDynArr(DynArr *v, TYPE val);
    TYPE topDynArr(DynArr *v);
    void popDynArr(DynArr *v);

    /* Bag Interface */
    /* Note addDynArr is already declared above*/
    int containsDynArr(DynArr *v, TYPE val);
    void removeDynArr(DynArr *v, TYPE val);
};

#endif /* shopping_hpp */
