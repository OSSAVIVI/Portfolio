/***************************************************************************************
** Program Name: Homework 4 Problem 8
** Author: Ryan Wells Farran | File Name: main.cpp
** Class: CS 325 400 S2019 (Analysis of Algorithms) | Date: 10/28/2019 | Saturday, October 28th 2019
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
#include "binpacking.hpp"


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

    Menu menu = Menu("Homework 8 Problem 1b & 1c"); //calls constructor with the name of the game as a parameter
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
                    cout << "Executing Binpacking Approximation Algorithm...(user chose '1')" << endl;
                    cout << aestheticLine << endl;
                    string fileName;
                    fileName = "bin.txt";

                    BinPacking binPack;
                    binPack.multiLineHandler(fileName);
                    
                    menuOptionsChoice = menu.getMenuOptions();
                }
                else if (menuOptionsChoice == 2)
                {
                    cout << "Just taking a break from it all...(user chose '2')" << endl;
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
