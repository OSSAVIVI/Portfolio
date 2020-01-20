/***************************************************************************************
** File Name: mergeSort.hpp
** Description: This is the header file of the MergeSort class.
***************************************************************************************/

#ifndef insertsort_hpp
#define insertsort_hpp

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

class InsertionSort
{
public:
    std::string aestheticLine = "---------------------------------------------------------------"; //Used to visually seperate console output
    typedef struct DynArr DynArr;
public:
    int countNumberOfCharactersInFile(std::string inputFileName);
    int countNumberOfNewLinesInFile(std::string inputFileName);
    void readValuesFromFile(std::string inputFileName, int* storingArray);
    void printArrayToConsole(const int* arrayToPrint, int sizeOfArray);
    void printDynArrayToConsole(DynArr* arrayToPrint, int sizeOfArray);
    void multiLineHandler(const int* arrayToHandle, int sizeOfArray);
    void outputValuesToFile(DynArr* sortedArray, int sizeOfArray);
    
    //insertion...
    
    void insertionSorter(int* arrayToSort, int sizeOfArray);
    
    //insertion...
    
    
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
    
    void _dynArrSetCapacity(DynArr *v, int newCap);
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

#endif /* insertionSort_hpp */
