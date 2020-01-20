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
#include "shopping.hpp"

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

    Menu menu = Menu("Homework 3 Problem 4"); //calls constructor with the name of the game as a parameter
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
                    string aestheticLine = "---------------------------------------------------------------";
                    string aestheticLine2 = "***************************************************************";
                    cout << "Executing Shopping Program...(user chose '1')" << endl;
                    cout << aestheticLine << endl;
                    std::cout << "1. First, we'll count how many numbers" <<std::endl;
                    std::cout << "There are in the 'shopping.txt file...'" <<std::endl;
                    
                    Shopping shop;
                    int numOfCharsInFile = shop.countNumberOfCharactersInFile("shopping.txt");
                    std::cout << "File countains: " << numOfCharsInFile << " numbers." << std::endl;
                    cout << aestheticLine << endl;
                    cout << aestheticLine2 << endl;
                    std::cout << "T (1 <= T <= 100) is given on the first" << std::endl;
                    std::cout << "line of the input file." << std::endl;
                    cout << aestheticLine2 << endl;
                    std::cout << "Each test case begins with a line containing " << std::endl;
                    std::cout << "a single integer number N that indicates the number" << std::endl;
                    std::cout << "of items (1 <= N <= 100) in that test case" << std::endl;
                    cout << aestheticLine2 << endl;
                    std::cout << "Followed by N lines, each containing"  << std::endl;
                    std::cout << "two integers: P and W. " << std::endl;
                    std::cout << "The first integer (1 <= P <= 5000)" << std::endl;
                    std::cout << "corresponds to the price of object" << std::endl;
                    std::cout << "and the second integer (1 ≤ W ≤ 100)" << std::endl;
                    std::cout << "corresponds to the weight of object." << std::endl;
                    cout << aestheticLine2 << endl;
                    std::cout << "The next line contains one integer (1 <= F <= 30)" << std::endl;
                    std::cout << "which is the number of people in that family." << std::endl;
                    cout << aestheticLine2 << endl;
                    std::cout << "The next F lines contains the maximum" << std::endl;
                    std::cout << "weight (1 <= M <= 200) that can be carried" << std::endl;
                    std::cout << "by the ith person in the family (1 <= i <= F)." << std::endl;
                    cout << aestheticLine2 << endl;
                    cout << aestheticLine << endl;
                    std::cout << "2. Second, we'll read the values from the file" <<std::endl;
                    std::cout << "into an array of size " << numOfCharsInFile << "." <<std::endl;
                    int arrayOfNumbers[numOfCharsInFile];
                    shop.readValuesFromFile("shopping.txt", arrayOfNumbers);
                    cout << aestheticLine << endl;
                    
                    /*std::cout << "!!!TEST PRINT!!!" <<std::endl;
                    shop.printArrayToConsole(arrayOfNumbers, numOfCharsInFile);*/
                    
                    cout << "3. Third, we will call our array handler..." << endl;
                    shop.multiLineHandler(arrayOfNumbers, numOfCharsInFile);
                    
                    

                    menuOptionsChoice = menu.getMenuOptions();
                }
                else if (menuOptionsChoice == 2)
                {
                    cout << "Executing Runtime Demonstrations...(user chose '2')" << endl;
                    cout << aestheticLine << endl;
                    std::cout << "Ahhh... Wonderful choice..." <<std::endl;
                    
                    std::cout << "      |\\      _,,,---,,_" <<std::endl;
                    std::cout << "ZZZzz /,`.-'`'    -.  ;-;;,_" <<std::endl;
                    std::cout << "     |,4-  ) )-,_. ,\\ (  `'-'" <<std::endl;
                    std::cout << "    '---''(_/--'  `-'\\_) " <<std::endl;
                    cout << aestheticLine << endl;

                    

                    
                    
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
