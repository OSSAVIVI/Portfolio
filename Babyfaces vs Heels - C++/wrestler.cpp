/***************************************************************************************
** File Name: Wrestler.cpp
** Description: This is the implementation file of the Wrestler class.
***************************************************************************************/

#include "wrestler.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <assert.h>
#include <iterator>
#include <map>

int Wrestler::countNumberOfCharactersInFile(std::string inputFileName)
{
    int count = 0;
    std::string storingArray[1];
    
    std::ifstream inputFile;
    inputFile.open(inputFileName.c_str()); //opens file using name passed as parameter
    if (!inputFile)
    {
        std::cout << "Unable to open " << inputFileName << std::endl; //explains issue if error opening
    }
    else
    {
        while (!inputFile.eof())
        { //reads data from file into array
            inputFile >> storingArray[0];
            if (storingArray[0] == "//") { break; }
            count++;
            //std::cout << "String #" << count << ": " << storingArray[0] << std::endl;
        }
    }
    inputFile.close(); //closes file
    
    return count;
}

int Wrestler::countNumberOfNewLinesInFile(std::string inputFileName)
{
    int count = 1;
    char storingArray[1];
    
    std::ifstream inputFile;
    inputFile.open(inputFileName.c_str()); //opens file using name passed as parameter
    if (!inputFile)
    {
        std::cout << "Unable to open " << inputFileName << std::endl; //explains issue if error opening
    }
    else
    {
        while (!inputFile.eof())
        { //reads data from file into array
            
            inputFile >> storingArray[0];
            if (storingArray[0] == '\n')
            {
                count++;
            }
            //std::cout << "Character " << count << ": " << storingArray[0] << std::endl;
        }
    }
    inputFile.close(); //closes file
    
    return count;
}

void Wrestler::readValuesFromFile(std::string inputFileName, std::string* storingArray, int sizeOfArray)
{
    int arrayIndex = 0; //use index here since we can't use for loop
    std::ifstream inputFile;
    inputFile.open(inputFileName.c_str()); //opens file using name passed as parameter
    if (!inputFile)
    {
        std::cout << "Unable to open " << inputFileName << std::endl; //explains issue if error opening
    }
    else
    {
        std::string tempStringCopy;
        while (!inputFile.eof() && sizeOfArray > 0)
        { //reads data from file into array
            sizeOfArray--;
            std::string tempString;
            inputFile >> tempString;
            tempStringCopy = tempString;
            storingArray[arrayIndex] = tempString;
            arrayIndex++;
        }
    }
    inputFile.close(); //closes file
}

void Wrestler::printArrayToConsole(const std::string* arrayToPrint, int sizeOfArray)
{
    //std::cout << aestheticLine << std::endl;
    //std::cout << "Your array is printed below: " << std::endl;
    for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++)
    { //simply prints each array element followed by space
        std::cout << arrayToPrint[arrayIndex] << " ";
    }
    std::cout << std::endl << std::endl;// << aestheticLine << std::endl;
}

void Wrestler::printDynArrayToConsole(DynArr* arrayToPrint, int sizeOfArray)
{
    //std::cout << aestheticLine << std::endl;
    //std::cout << "Your array is printed below: " << std::endl;
    for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++)
    { //simply prints each array element followed by space
        std::cout << getDynArr(arrayToPrint, arrayIndex) << " ";
    }
    std::cout << std::endl;// << aestheticLine << std::endl;
}

//This code calls the merge functions and is a wrapper function
//with the purpose of handling the multiple lines of the data.txt file
//in addition to the first number of each line equaling that line's
//number of elements to sort.
void Wrestler::multiLineHandler(const std::string* arrayToHandle, int sizeOfArray)
{
    std::cout << aestheticLine << std::endl;
    
    bool isPossible = true;
    while (isPossible)
    {
        //BEGIN GET NUMBER OF WRESTLERS
        int index = 0;
        std::string numberOfWrestlers = arrayToHandle[index];
        const char* numOfWrestlers = numberOfWrestlers.c_str();
        index++;
        
        int numOfWres = 0;
        if (numberOfWrestlers.length() == 2)
        {
            numOfWres = (int)numOfWrestlers[1] - '0' + (10 * ((int)numOfWrestlers[0] - '0'));
            std::cout << "There are " << numOfWres << " wrestlers!" << std::endl;
        }
        else if (numberOfWrestlers.length() == 1)
        {
            numOfWres = (int)numOfWrestlers[0] - '0';
            std::cout << "There are " << numOfWres << " wrestlers!" << std::endl;
        }
        else
        { //can only handle up to 99 wrestlers
            std::cout << "Invalid number of wrestlers" << std::endl;
        }
        //END GET NUMBER OF WRESTLERS
        
        DynArr* babyFaces = newDynArr(numOfWres);
        DynArr* heels = newDynArr(numOfWres);
        
        //BEGIN POPULATE WRESTLER MAP
        std::map<int, std::string> wrestlerMap;
        while (index <= numOfWres)
        {
            wrestlerMap[index] = arrayToHandle[index];
            std::cout << wrestlerMap[index] << std::endl;
            index++;
        }
        //END POPULATE WRESTLER MAP
        
        //BEGIN GET NUMBER OF RIVALRIES
        std::string numberOfRivalries = arrayToHandle[index];
        const char* numOfRivalries = numberOfRivalries.c_str();
        index++;
        
        int numOfRiva = 0;
        if (numberOfRivalries.length() == 2)
        {
            numOfRiva = (int)numOfRivalries[1] - '0' + (10 * ((int)numOfRivalries[0] - '0'));
            std::cout << "There are " << numOfRiva << " rivalries!" << std::endl;
        }
        else if (numberOfRivalries.length() == 1)
        {
            numOfRiva = (int)numOfRivalries[0] - '0';
            std::cout << "There are " << numOfRiva << " rivalries!" << std::endl;
        }
        else
        { //can only handle up to 99 wrestlers
            std::cout << "Invalid number of rivalries" << std::endl;
        }
        //END GET NUMBER OF RIVALRIES
        
        
        //BEGIN POPULATE RIVALRY MAP
        for (int index2 = 1; index2 <= numOfRiva; index2++)
        {
            bool wrestler1IsBabyFace = false;
            bool wrestler2IsBabyFace = false;
            bool wrestler1IsHeel = false;
            bool wrestler2IsHeel = false;
            std::string tempWrestler1 = arrayToHandle[index];
            index++;
            int index3 = 1;
            while (wrestlerMap[index3] != tempWrestler1)
            {
                index3++;
            }
            std::string tempWrestler2 = arrayToHandle[index];
            index++;
            int index4 = 1;
            while (wrestlerMap[index4] != tempWrestler2)
            {
                index4++;
            }
            
            if (isEmptyDynArr(babyFaces) && isEmptyDynArr(heels))
            {
                addDynArr(babyFaces, index3);
                std::cout << "Making " << wrestlerMap[index3] << " a BABYFACE!" << std::endl;
                addDynArr(heels, index4);
                std::cout << "Making " << wrestlerMap[index4] << " a HEEL!" << std::endl;
            }
            else
            {
                //determine if wrestler1 is a baby face
                    //if yes -> determine if wrestler2 is a baby face
                        //if yes -> NOT POSSIBLE
                        //else   -> determine if wrestler2 is a heel
                            //if yes -> move on, this rivalry is OKAY
                            //else   -> MAKE WRESTLER 2 A HEEL
                    //else   -> determine if wrestler1 is a heel
                        //if yes -> determine if wrestler2 is a heel
                            //if yes -> NOT POSSIBLE
                            //else   -> MAKE WRESTLER 2 A BABY FACE
                        //else   -> wresterl1 can be either one, so we must determine if wrestler2 is a baby face
                            //if yes -> MAKE WRESTLER 1 A HEEL
                            //else   -> determine if wrestler2 is a heel
                                //if yes -> MAKE WRESTLER 1 A BABYFACE
                                //else   -> we can make either combination...
                
                for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                {
                    if (getDynArr(babyFaces, index5) == index3) { wrestler1IsBabyFace = true; }
                }
                if (wrestler1IsBabyFace)
                {
                    for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                    {
                        if (getDynArr(babyFaces, index5) == index4) { wrestler2IsBabyFace = true; }
                    }
                    if (wrestler2IsBabyFace)
                    {
                        //NOT POSSIBLE
                        isPossible = false;
                    }
                    else
                    {
                        for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                        {
                            if (getDynArr(heels, index5) == index4) { wrestler2IsHeel = true; }
                        }
                        if (wrestler2IsHeel)
                        {
                            //wrestler1 is babyface and wrestler2 is heel, move on, this rivalry is okay
                        }
                        else
                        {
                            //MAKE WRESTLER 2 A HEEL
                            addDynArr(heels, index4);
                            std::cout << "Making " << wrestlerMap[index4] << " a HEEL!" << std::endl;
                        }
                    }
                }
                else
                {
                    for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                    {
                        if (getDynArr(heels, index5) == index3) { wrestler1IsHeel = true; }
                    }
                    if (wrestler1IsHeel)
                    {
                        for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                        {
                            if (getDynArr(heels, index5) == index4) { wrestler2IsHeel = true; }
                        }
                        if (wrestler2IsHeel)
                        {
                            //NOT POSSIBLE
                            isPossible = false;
                        }
                        else
                        {
                            for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                            {
                                if (getDynArr(babyFaces, index5) == index4) { wrestler2IsBabyFace = true; }
                            }
                            if (wrestler2IsBabyFace)
                            {
                                //wrestler1 is heel and wrestler2 is babyface, move on, this rivalry is okay
                            }
                            else
                            {
                                //MAKE WRESTLER 2 A BABY FACE
                                addDynArr(babyFaces, index4);
                                std::cout << "Making " << wrestlerMap[index4] << " a BABYFACE!" << std::endl;
                            }
                        }
                    }
                    else
                    {
                        for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                        {
                            if (getDynArr(babyFaces, index5) == index4) { wrestler2IsBabyFace = true; }
                        }
                        if (wrestler2IsBabyFace)
                        {
                            //MAKE WRESTLER 1 A HEEL
                            addDynArr(heels, index3);
                            std::cout << "Making " << wrestlerMap[index3] << " a HEEL!" << std::endl;
                        }
                        else
                        {
                            for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                            {
                                if (getDynArr(heels, index5) == index4) { wrestler2IsHeel = true; }
                            }
                            if (wrestler2IsHeel)
                            {
                                //MAKE WRESTLER 1 A BABY FACE
                                addDynArr(babyFaces, index3);
                                std::cout << "Making " << wrestlerMap[index3] << " a BABYFACE!" << std::endl;
                            }
                            else
                            {
                                //I need a way to be able to slit the code and try adding
                                //them in both different configurations for this case
                                //but I don't know how...
                                
                                
                                //MAKE WRESTLER 1 A BABY FACE
                                addDynArr(babyFaces, index3);
                                std::cout << "Making " << wrestlerMap[index3] << " a BABYFACE!" << std::endl;
                                //MAKE WRESTLER 2 A HEEL
                                addDynArr(heels, index4);
                                std::cout << "Making " << wrestlerMap[index4] << " a HEEL!" << std::endl;
                            }
                        }
                    }
                }
            }
            
        }
        if (isPossible)
        {
            std::cout << "\nYes " << std::endl;
            std::cout << "Babyfaces: ";
            for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
            {
                std::cout << wrestlerMap[getDynArr(babyFaces, index5)] << " ";
            }
            std::cout << std::endl;
            std::cout << "Heels: ";
            for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
            {
                std::cout << wrestlerMap[getDynArr(heels, index5)] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            //call function that does the exact same thing, but one thing is switched...
            multiLineHandler2(arrayToHandle, sizeOfArray);
        }
        isPossible = false;
        deleteDynArr(babyFaces);
        deleteDynArr(heels);
    }
}


void Wrestler::multiLineHandler2(const std::string* arrayToHandle, int sizeOfArray)
{
    std::cout << aestheticLine << std::endl;
    
    bool isPossible = true;
    while (isPossible)
    {
        //BEGIN GET NUMBER OF WRESTLERS
        int index = 0;
        std::string numberOfWrestlers = arrayToHandle[index];
        const char* numOfWrestlers = numberOfWrestlers.c_str();
        index++;
        
        int numOfWres = 0;
        if (numberOfWrestlers.length() == 2)
        {
            numOfWres = (int)numOfWrestlers[1] - '0' + (10 * ((int)numOfWrestlers[0] - '0'));
            std::cout << "There are " << numOfWres << " wrestlers!" << std::endl;
        }
        else if (numberOfWrestlers.length() == 1)
        {
            numOfWres = (int)numOfWrestlers[0] - '0';
            std::cout << "There are " << numOfWres << " wrestlers!" << std::endl;
        }
        else
        { //can only handle up to 99 wrestlers
            std::cout << "Invalid number of wrestlers" << std::endl;
        }
        //END GET NUMBER OF WRESTLERS
        
        DynArr* babyFaces = newDynArr(numOfWres);
        DynArr* heels = newDynArr(numOfWres);
        
        //BEGIN POPULATE WRESTLER MAP
        std::map<int, std::string> wrestlerMap;
        while (index <= numOfWres)
        {
            wrestlerMap[index] = arrayToHandle[index];
            std::cout << wrestlerMap[index] << std::endl;
            index++;
        }
        //END POPULATE WRESTLER MAP
        
        //BEGIN GET NUMBER OF RIVALRIES
        std::string numberOfRivalries = arrayToHandle[index];
        const char* numOfRivalries = numberOfRivalries.c_str();
        index++;
        
        int numOfRiva = 0;
        if (numberOfRivalries.length() == 2)
        {
            numOfRiva = (int)numOfRivalries[1] - '0' + (10 * ((int)numOfRivalries[0] - '0'));
            std::cout << "There are " << numOfRiva << " rivalries!" << std::endl;
        }
        else if (numberOfRivalries.length() == 1)
        {
            numOfRiva = (int)numOfRivalries[0] - '0';
            std::cout << "There are " << numOfRiva << " rivalries!" << std::endl;
        }
        else
        { //can only handle up to 99 wrestlers
            std::cout << "Invalid number of rivalries" << std::endl;
        }
        //END GET NUMBER OF RIVALRIES
        
        //BEGIN POPULATE RIVALRY MAP
        for (int index2 = 1; index2 <= numOfRiva; index2++)
        {
            bool wrestler1IsBabyFace = false;
            bool wrestler2IsBabyFace = false;
            bool wrestler1IsHeel = false;
            bool wrestler2IsHeel = false;
            std::string tempWrestler1 = arrayToHandle[index];
            index++;
            int index3 = 1;
            while (wrestlerMap[index3] != tempWrestler1)
            {
                index3++;
            }
            std::string tempWrestler2 = arrayToHandle[index];
            index++;
            int index4 = 1;
            while (wrestlerMap[index4] != tempWrestler2)
            {
                index4++;
            }
            
            if (isEmptyDynArr(babyFaces) && isEmptyDynArr(heels))
            {
                addDynArr(babyFaces, index3);
                std::cout << "Making " << wrestlerMap[index3] << " a BABYFACE!" << std::endl;
                addDynArr(heels, index4);
                std::cout << "Making " << wrestlerMap[index4] << " a HEEL!" << std::endl;
            }
            else
            {
                //determine if wrestler1 is a baby face
                    //if yes -> determine if wrestler2 is a baby face
                        //if yes -> NOT POSSIBLE
                        //else   -> determine if wrestler2 is a heel
                            //if yes -> move on, this rivalry is OKAY
                            //else   -> MAKE WRESTLER 2 A HEEL
                    //else   -> determine if wrestler1 is a heel
                        //if yes -> determine if wrestler2 is a heel
                            //if yes -> NOT POSSIBLE
                            //else   -> MAKE WRESTLER 2 A BABY FACE
                        //else   -> wresterl1 can be either one, so we must determine if wrestler2 is a baby face
                            //if yes -> MAKE WRESTLER 1 A HEEL
                            //else   -> determine if wrestler2 is a heel
                                //if yes -> MAKE WRESTLER 1 A BABYFACE
                                //else   -> we can make either combination...
                
                for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                {
                    if (getDynArr(babyFaces, index5) == index3) { wrestler1IsBabyFace = true; }
                }
                if (wrestler1IsBabyFace)
                {
                    for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                    {
                        if (getDynArr(babyFaces, index5) == index4) { wrestler2IsBabyFace = true; }
                    }
                    if (wrestler2IsBabyFace)
                    {
                        //NOT POSSIBLE
                        isPossible = false;
                    }
                    else
                    {
                        for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                        {
                            if (getDynArr(heels, index5) == index4) { wrestler2IsHeel = true; }
                        }
                        if (wrestler2IsHeel)
                        {
                            //wrestler1 is babyface and wrestler2 is heel, move on, this rivalry is okay
                        }
                        else
                        {
                            //MAKE WRESTLER 2 A HEEL
                            addDynArr(heels, index4);
                            std::cout << "Making " << wrestlerMap[index4] << " a HEEL!" << std::endl;
                        }
                    }
                }
                else
                {
                    for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                    {
                        if (getDynArr(heels, index5) == index3) { wrestler1IsHeel = true; }
                    }
                    if (wrestler1IsHeel)
                    {
                        for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                        {
                            if (getDynArr(heels, index5) == index4) { wrestler2IsHeel = true; }
                        }
                        if (wrestler2IsHeel)
                        {
                            //NOT POSSIBLE
                            isPossible = false;
                        }
                        else
                        {
                            for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                            {
                                if (getDynArr(babyFaces, index5) == index4) { wrestler2IsBabyFace = true; }
                            }
                            if (wrestler2IsBabyFace)
                            {
                                //wrestler1 is heel and wrestler2 is babyface, move on, this rivalry is okay
                            }
                            else
                            {
                                //MAKE WRESTLER 2 A BABY FACE
                                addDynArr(babyFaces, index4);
                                std::cout << "Making " << wrestlerMap[index4] << " a BABYFACE!" << std::endl;
                            }
                        }
                    }
                    else
                    {
                        for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
                        {
                            if (getDynArr(babyFaces, index5) == index4) { wrestler2IsBabyFace = true; }
                        }
                        if (wrestler2IsBabyFace)
                        {
                            //MAKE WRESTLER 1 A HEEL
                            addDynArr(heels, index3);
                            std::cout << "Making " << wrestlerMap[index3] << " a HEEL!" << std::endl;
                        }
                        else
                        {
                            for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
                            {
                                if (getDynArr(heels, index5) == index4) { wrestler2IsHeel = true; }
                            }
                            if (wrestler2IsHeel)
                            {
                                //MAKE WRESTLER 1 A BABY FACE
                                addDynArr(babyFaces, index3);
                                std::cout << "Making " << wrestlerMap[index3] << " a BABYFACE!" << std::endl;
                            }
                            else
                            {
                                //I need a way to be able to slit the code and try adding
                                //them in both different configurations for this case
                                //but I don't know how...
                                
                                
                                //MAKE WRESTLER 1 A BABY FACE
                                addDynArr(babyFaces, index4);
                                std::cout << "Making " << wrestlerMap[index4] << " a BABYFACE!" << std::endl;
                                //MAKE WRESTLER 2 A HEEL
                                addDynArr(heels, index3);
                                std::cout << "Making " << wrestlerMap[index3] << " a HEEL!" << std::endl;
                            }
                        }
                    }
                }
            }
            
        }
        if (isPossible)
        {
            std::cout << "\nYes " << std::endl;
            std::cout << "Babyfaces: ";
            for (int index5 = 0; index5 < sizeDynArr(babyFaces); index5++)
            {
                std::cout << wrestlerMap[getDynArr(babyFaces, index5)] << " ";
            }
            std::cout << std::endl;
            std::cout << "Heels: ";
            for (int index5 = 0; index5 < sizeDynArr(heels); index5++)
            {
                std::cout << wrestlerMap[getDynArr(heels, index5)] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            //call function that does the exact same thing, but one thing is switched...
            std::cout << "\nNo, it is not possible. " << std::endl;
        }
        isPossible = false;
        deleteDynArr(babyFaces);
        deleteDynArr(heels);
    }
}




//THis function writes
void Wrestler::outputValuesToFile(DynArr* sortedArray, int sizeOfArray)
{
    //std::cout << aestheticLine << std::endl;
    std::ofstream outputFile;
    std::string fileName = "merge.txt";
    outputFile.open(fileName.c_str());
    if (!outputFile)
    {
        std::cout << "Unable to open " << fileName << std::endl; //explains issue
    }
    else
    {
        for (int arrayIndex = 0; arrayIndex < sizeOfArray; arrayIndex++)
        {
            if (getDynArr(sortedArray, arrayIndex) != '\n')
            {
                if (getDynArr(sortedArray, arrayIndex) > 57)
                {
                    //numbers greater than 9 are handled below using convertCharToInt...
                    outputFile << convertCharToInt(getDynArr(sortedArray, arrayIndex)) << " ";
                }
                else
                { //numbers 0-9 are dealt using the code below...
                    outputFile << getDynArr(sortedArray, arrayIndex) << " ";
                }
            }
            else
            {
                outputFile << '\n';
            }
        }
    }
    //std::cout << std::endl << aestheticLine << std::endl;
    outputFile.close();
}

//Base case for Wrestler
void Wrestler::baseMerge(int* arrayToSort, int begIndex, int middleIndex, int endIndex)
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
void Wrestler::recursiveMergeSort(int* arrayToSort, int begIndex, int endIndex)
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


int Wrestler::convertCharToInt(char charToConvert)
{
    int value = (int)(charToConvert - 48);
    return value;
}

//converts int array to char array for dynamic array
DynArr* Wrestler::convertIntArrayToDynArr(const int* arrayToAdd, int sizeOfArray)
{
    DynArr* newArray;
    newArray = newDynArr(sizeOfArray);
    
    for (int index = 0; index < sizeOfArray; index++)
    {
        char charToAdd = (char)(arrayToAdd[index] + 48);
        //std::cout << charToAdd << std::endl;
        pushDynArr(newArray, charToAdd);
    }
    return newArray;
}

//This function adds individual lines to the final array for the outpt to file function
void Wrestler::addToFinalArray(DynArr* arrayToAddTo, DynArr* arrayToAdd, int sizeOfArray)
{
    for (int index = 0; index < sizeOfArray; index++)
    {
        TYPE charToAdd = getDynArr(arrayToAdd, index);
        pushDynArr(arrayToAddTo, charToAdd);
    }
    pushDynArr(arrayToAddTo, '\n');
}









//STACK STUFF
struct DynArr
{
    TYPE *data;        /* pointer to the data array */
    int size;        /* Number of elements in the array */
    int capacity;    /* capacity ofthe array */
};


/* ************************************************************************
    Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

    param:     v        pointer to the dynamic array
    param:    cap     capacity of the dynamic array
    pre:    v is not null
    post:    internal data array can hold cap elements
    post:    v->data is not null
*/
void Wrestler::initDynArr(DynArr *v, int capacity)
{
    assert(capacity > 0);
    assert(v!= 0);
    v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
    assert(v->data != 0);
    v->size = 0;
    //printf("Empty array has been initialized with a size of %d\n", v->size);
    v->capacity = capacity;
}

/* Allocate and initialize dynamic array.

    param:    cap     desired capacity for the dyn array
    pre:    none
    post:    none
    ret:    a non-null pointer to a dynArr of cap capacity
            and 0 elements in it.
*/
DynArr* Wrestler::newDynArr(int cap)
{
    assert(cap > 0);
    //printf("Creating a new array with a capacity of %d\n", cap);
    DynArr *r = (DynArr *)malloc(sizeof(DynArr));
    assert(r != 0);
    initDynArr(r, cap);
    return r;
}

/* Deallocate data array in dynamic array.

    param:     v        pointer to the dynamic array
    pre:    none
    post:    d.data points to null
    post:    size and capacity are 0
    post:    the memory used by v->data is freed
*/
void Wrestler::freeDynArr(DynArr *v)
{
    if(v->data != 0)
    {
        free(v->data);     /* free the space on the heap */
        v->data = 0;       /* make it point to null */
        //printf("Successfully deleted...\n");
    }
    else
    {
        printf("Array is NULL, cannot free.\n");
    }
    v->size = 0;
    v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure.

    param:     v        pointer to the dynamic array
    pre:    none
    post:    the memory used by v->data is freed
    post:    the memory used by d is freed
*/
void Wrestler::deleteDynArr(DynArr *v)
{
    //printf("Attempting to delete array...\n");
    freeDynArr(v);
    free(v);
}

/* Resizes the underlying array to be the size cap

    param:     v        pointer to the dynamic array
    param:    cap        the new desired capacity
    pre:    v is not null
    post:    v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{
    /* FIXME: You will write this function */
    TYPE *newArray = (TYPE*)malloc(sizeof(TYPE) * newCap);
    for (int index = 0; index < v->size; index++)
    {
        newArray[index] = v->data[index];
    }
    free(v->data);
    v->data = newArray;
}

/* Get the size of the dynamic array

    param:     v        pointer to the dynamic array
    pre:    v is not null
    post:    none
    ret:    the size of the dynamic array
*/
int Wrestler::sizeDynArr(DynArr *v)
{
    return v->size;
}

/*     Adds an element to the end of the dynamic array

    param:     v        pointer to the dynamic array
    param:    val        the value to add to the end of the dynamic array
    pre:    the dynArry is not null
    post:    size increases by 1
    pre:    if reached capacity, capacity is doubled
    post:    val is in the last utilized position in the array
*/
void Wrestler::addDynArr(DynArr *v, TYPE val)
{
    /* FIXME: You will write this function */
    v->data[v->size] = val;
    v->size++;
}

/*    Get an element from the dynamic array from a specified position
    
    param:     v        pointer to the dynamic array
    param:    pos        integer index to get the element from
    pre:    v is not null
    pre:    v is not empty
    pre:    pos < size of the dyn array and >= 0
    post:    no changes to the dyn Array
    ret:    value stored at index pos
*/
TYPE Wrestler::getDynArr(DynArr *v, int pos)
{
    /* FIXME: You will write this function */
    TYPE returnValue = v->data[pos];
    /* FIXME: you must change this return value */
    return returnValue;
}

/*    Put an item into the dynamic array at the specified location,
    overwriting the element that was there

    param:     v        pointer to the dynamic array
    param:    pos        the index to put the value into
    param:    val        the value to insert
    pre:    v is not null
    pre:    v is not empty
    pre:    pos >= 0 and pos < size of the array
    post:    index pos contains new value, val
*/
void Wrestler::putDynArr(DynArr *v, int pos, TYPE val)
{
    /* FIXME: You will write this function */
    v->data[pos] = val;
}

/*    Swap two specified elements in the dynamic array

    param:     v        pointer to the dynamic array
    param:    i,j        the elements to be swapped
    pre:    v is not null
    pre:    v is not empty
    pre:    i, j >= 0 and i,j < size of the dynamic array
    post:    index i now holds the value at j and index j now holds the value at i
*/
void Wrestler::swapDynArr(DynArr *v, int i, int  j)
{
    /* FIXME: You will write this function */
    TYPE temp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temp;
}

/*    Remove the element at the specified location from the array,
    shifts other elements back one to fill the gap

    param:     v        pointer to the dynamic array
    param:    idx        location of element to remove
    pre:    v is not null
    pre:    v is not empty
    pre:    idx < size and idx >= 0
    post:    the element at idx is removed
    post:    the elements past idx are moved back one
*/
void Wrestler::removeAtDynArr(DynArr *v, int idx)
{
    /* FIXME: You will write this function */
    for (int index = idx; index < v->size; index++)
    {
        v->data[index] = v->data[index + 1]; //shifts each element back one
    }
    v->data[v->size - 1] = 0; //sets the duplicate of the last value to zero
    v->size--; //and then finally adjust the size
}

/* ************************************************************************
    Stack Interface Functions
************************************************************************ */

/*    Returns boolean (encoded in an int) demonstrating whether or not the
    dynamic array stack has an item on it.

    param:    v        pointer to the dynamic array
    pre:    the dynArr is not null
    post:    none
    ret:    1 if empty, otherwise 0
*/
int Wrestler::isEmptyDynArr(DynArr *v)
{
    /* FIXME: You will write this function */
    int booleanValue = 0; //set to false (0) by default
    if (v->size == 0)
    {
        booleanValue = 1; //if size is zero, then array is empty and return value is set to true (1)
    }
    /* FIXME:  You will change this return value*/
    return booleanValue; //returns 1 for TRUE and 0 for FALSE
}

/*     Push an element onto the top of the stack

    param:    v        pointer to the dynamic array
    param:    val        the value to push onto the stack
    pre:    v is not null
    post:    size increases by 1
            if reached capacity, capacity is doubled
            val is on the top of the stack
*/
void Wrestler::pushDynArr(DynArr *v, TYPE val)
{
    /* FIXME: You will write this function */
    if (v->size == v->capacity)
    {
        _dynArrSetCapacity(v, (v->capacity * 2));
    }
    addDynArr(v, val);
}

/*    Returns the element at the top of the stack

    param:    v        pointer to the dynamic array
    pre:    v is not null
    pre:    v is not empty
    post:    no changes to the stack
*/
TYPE Wrestler::topDynArr(DynArr *v)
{
    /* FIXME: You will write this function */
    TYPE returnValue = '|';
    if (isEmptyDynArr(v) == 0)
    {
        returnValue = v->data[v->size - 1];
    }
    else
    {
        printf("ERROR: Array is EMPTY, cannot return top of STACK.\n");
        printf("Returning error code '|''\n");
    }
    
    /* FIXME: You will change this return value*/
    return returnValue;
}

/* Removes the element on top of the stack

    param:    v        pointer to the dynamic array
    pre:    v is not null
    pre:    v is not empty
    post:    size is decremented by 1
            the top has been removed
*/
void Wrestler::popDynArr(DynArr *v)
{
    /* FIXME: You will write this function */
    if (isEmptyDynArr(v) == 0)
    {
        //printf("Popping %d from the top of STACK...", v->data[v->size - 1]);
        removeAtDynArr(v, (v->size - 1));
        //printf("POP!\n");
    }
    else
    {
        printf("ERROR: Array is EMPTY, cannot POP top of STACK.\n");
    }
}

/* ************************************************************************
    Bag Interface Functions
************************************************************************ */

/*    Returns boolean (encoded as an int) demonstrating whether or not
    the specified value is in the collection
    true = 1
    false = 0

    param:    v        pointer to the dynamic array
    param:    val        the value to look for in the bag
    pre:    v is not null
    pre:    v is not empty
    post:    no changes to the bag
*/
int Wrestler::containsDynArr(DynArr *v, TYPE val)
{
    /* FIXME: You will write this function */
    int booleanValue = 0;
    for (int index = 0, count = 1; index < v->size; index++)
    {
        if (v->data[index] == val)
        {
            booleanValue = 1;
            //printf("Found %d!\n", count);
            count++;
        }
    }
    
    /* FIXME:  You will change this return value */
    return booleanValue;
}

/*    Removes the first occurrence of the specified value from the collection
    if it occurs

    param:    v        pointer to the dynamic array
    param:    val        the value to remove from the array
    pre:    v is not null
    pre:    v is not empty
    post:    val has been removed
    post:    size of the bag is reduced by 1
*/
void Wrestler::removeDynArr(DynArr *v, TYPE val)
{
    /* FIXME: You will write this function */
    if (containsDynArr(v, val))
    {
        int indexMarker = 0;
        while (v->data[indexMarker] != val)
        {
            indexMarker++;
        }
        removeAtDynArr(v, indexMarker);
    }
}

