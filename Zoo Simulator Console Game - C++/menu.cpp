/***************************************************************************************
 ** Program Name: Project 2 | File Name: menu.cpp file
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Description: This is the modular menu.cpp implementation file for the menu.hpp header
 ** file and is pretty straightforward. It includes a default constructor incase no program name is
 ** known so it can still output a greeting. It could be modified further so it could ask the user
 ** for their name and class name, but in this case it is not necessary.
 ***************************************************************************************/
#include <iostream>
#include "menu.hpp"
#include "inputVal.hpp"

Menu::Menu()
{
    programName = "my Computer Science Program";
    className   = "CS 162 400 S2019 (Intro to CS II)";
    authorName  = "Ryan Wells Farran";
    intUserInput = 0;
}

Menu::Menu(std::string custProgramName)
{
    programName = custProgramName;
    className   = "CS 162 400 S2019 (Intro to CS II)";
    authorName  = "Ryan Wells Farran";
    intUserInput = 0;
}

int Menu::startMenu()
{   //Introductory greeting
    std::cout << "*************************************************" << std::endl;
    std::cout << "Welcome to " << programName << std::endl;
    std::cout << "for " << className << std::endl;
    std::cout << "by " << authorName << "." << std::endl;
    std::cout << "*************************************************" << std::endl;
    
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "Please enter 1 to PLAY GAME or 2 to EXIT GAME." << std::endl;;
    inputVal dummyInputVal; //used to call getInt()
    return dummyInputVal.getOneOrTwo();
}

int Menu::endMenu()
{   //Farewell message
    std::cout << "Thanks, have a wonderful day! :-)" << std::endl;
    std::cout << "*************************************************" << std::endl;
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "Please enter 1 to PLAY AGAIN or 2 to EXIT GAME." << std::endl;;
    inputVal dummyInputVal; //used to call getInt()
    return dummyInputVal.getOneOrTwo();
}
