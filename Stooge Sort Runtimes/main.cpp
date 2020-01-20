/***************************************************************************************
** Program Name: Homework 2 Problem 4
** Author: Ryan Wells Farran | File Name: main.cpp
** Class: CS 325 400 S2019 (Analysis of Algorithms) | Date: 10/05/2019 | Saturday, October 5th 2019
** Description: Implement the stooge sort algorithm from Problem 3 to sort an array/vector of integers.
Implement the algorithm in the same language you used for the sorting algorithms in HW 1.
Your program should be able to read inputs from a file called “data.txt” where the first value of
each line is the number of integers that need to be sorted, followed by the integers (like in HW
1). The output will be written to a file called “stooge.txt”.
*

** Example values for data.txt:
   4 19 2 5 11
   8 1 2 3 4 5 6 1 2

The output will be written to files called “merge.txt” and “insert.txt”.
For the above example the output would be:
   2 5 11 19
   1 1 2 2 3 4 5 6
*
*
***************************************************************************************/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
#include "menu.hpp"
#include "inputVal.hpp"
#include "stoogesort.hpp"
#include "stoogeTime.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::fstream;

int main()
{
    string aestheticLine = "---------------------------------------------------------------"; //used to visually break up console output
    
    //InputVal dummyInputVal; //Used to call functions in InputVal to validate user input
    
    //Code used with the Menu class object below
    int userChoice; //Stores whatever option user chooses from Menu class
    bool restart1 = true; //Used for first menu PLAY/EXIT prompt
    bool restart2 = true; //Used for second program PLAY AGAIN/EXIT prompt
    bool restart3 = true; //Used to continuously display menu options until exit is selected

    Menu menu = Menu("Homework 2 Problem 4"); //calls constructor with the name of the game as a parameter
    while (restart1 == true) //Initially set to true, so will always run on the first loop
    {
        userChoice = menu.startMenu(); //Begins Start/Quit prompt
        if (userChoice == 1)
        {
            //run program...(user chose '1')
            cout << "Starting Program...(user chose '1')" << endl;
            
            int menuOptionsChoice;
            menuOptionsChoice = menu.getMenuOptions();
            
            while (menuOptionsChoice != 1 && menuOptionsChoice != 2 &&
                   menuOptionsChoice != 3)
            {
                cout << "Invlaid option...try again...(user chose invalid option)" << endl;
                menuOptionsChoice = menu.getMenuOptions();
            }
            while (restart3 == true)
            {
                if (menuOptionsChoice == 1)
                {
                    cout << "Executing Stooge Sort...(user chose '1')" << endl;
                    cout << aestheticLine << endl;
                    std::cout << "1. First, we'll count how many numbers" <<std::endl;
                    std::cout << "there are in the data.txt file..." << std::endl << std::endl;
                    
                    StoogeSort dummyMergeSort;
                    int countCharacters = dummyMergeSort.countNumberOfCharactersInFile("data.txt");
                    std::cout << "File countains: " << countCharacters << " numbers." << std::endl;
                    std::cout << "(First number of each line equals the # of elements following)" << std::endl;
                    cout << aestheticLine << endl;
                    
                    std::cout << "2. Second, we'll STOOGE SORT each line of characters" <<std::endl;
                    std::cout << "from data.txt into their own array..." << std::endl << std::endl;
                    int arrayOfCharacters[countCharacters];
                    dummyMergeSort.readValuesFromFile("data.txt", arrayOfCharacters);
                    //dummyMergeSort.printArrayToConsole(arrayOfCharacters, countCharacters);
                    dummyMergeSort.multiLineHandler(arrayOfCharacters, countCharacters);

                    menuOptionsChoice = menu.getMenuOptions();
                }
                else if (menuOptionsChoice == 2)
                {
                    cout << "Executing Runtime Demonstrations...(user chose '2')" << endl;
                    cout << aestheticLine << endl;
                    
                    StoogeTime dummyStoogeTime;
                    int numOfArraysToMake = 10;
                    int arraySize = 500;
                    srand(time(NULL)); //"seeds" rand function
                    
                    cout << "Demonstrating STOOGE SORT runtimes." << endl;
                    for (int index = 0; index < numOfArraysToMake; index++)
                    {
                        cout << aestheticLine << endl;
                        cout << "*****" << endl;
                        int arrayToSort[arraySize];
                        cout << "Generating unsorted array " << (index + 1) << "..." << endl;
                        for (int index2 = 0; index2 < arraySize; index2++)
                        {
                            arrayToSort[index2] = (rand() % 10000) + 1;
                            //cout << arrayToSort[index2] << endl;
                        }
                        cout << "Finished generating unsorted array " << (index + 1) << "..." << endl;
                        //dummyMergeTime.printArray(arrayToSort, arraySize);
                        cout << "Initiating STOOGE SORT to demonstrate runtime of n = " << arraySize << "..." << endl;
                        clock_t t;
                        t = clock();
                        dummyStoogeTime.recursiveStoogeSort(arrayToSort, 0, (arraySize-1));
                        t = clock() - t;
                        printf ("STOOGE SORT took %d clicks (%f seconds).\n", t,((float)t)/CLOCKS_PER_SEC);
                        //dummyMergeTime.printArray(arrayToSort, arraySize);
                        
                        arraySize += 500;
                        cout << "*****" << endl;
                        cout << aestheticLine << endl << endl;;
                    }
                    menuOptionsChoice = menu.getMenuOptions();
                }
                else if (menuOptionsChoice == 3)
                {
                    cout << "Quitting program...(user chose '3')" << endl;
                    cout << aestheticLine << endl;
                    restart3 = false; // Breaks out of menuOptions = getMenuOptions() loop
                }
                else
                { //This code should never execute because of validation in while loop above and because inputVal class functions
                    cout << "Invlaid option...try again...(user inputted invalid data)" << endl;
                }
            }
            //end program...
            
            //Ask user if they would like to RESTART the program or QUIT
            while (restart2 == true) //Initially set to true, so will always run on the first run through
            {
                userChoice = menu.endMenu();
                if (userChoice == 1)
                {
                    restart1 = true;  //Will remain in outer loop upon exit of nested loop...
                    restart2 = false; //Set this to flase to exit nested loop, but remain in outer...
                }                      //Doing this will call menu.startMenu() again.
                else if (userChoice == 2)
                {
                    restart1 = false; //Sets both restart flags
                    restart2 = false; //to false to exit program
                }
                else //Will restart this loop and call menu.endMenu() if neither 1 nor 2 are selected
                {
                    cout << "You didn't select 1 or 2. Try again..." << endl;
                }
            }
            restart2 = true; //Sets back to true so the program may be restarted a second time
            restart3 = true; //Sets back to true so the program may loop on second run again
        }
        
        else if (userChoice == 2)
        {
            //end program...(user chose '2')
            cout << "Ending program...(user chose '2')" << endl;
            restart1 = false;
        }
        else //Will restart this loop and call menu.startMenu() if neither 1 nor 2 are selected
        { //This code should never execute because getOneOrTwo() should prevent any option other than 1 or 2 being entered
            cout << "You didn't select 1 or 2. Try again..." << endl;
        }
    }
    
    cout << "Terminating program...goodbye! :)" << endl;
    return 0; //exits program by returning 0 to main function

}
