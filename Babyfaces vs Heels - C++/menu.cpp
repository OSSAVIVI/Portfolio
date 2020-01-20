/***************************************************************************************
 ** File Name: menu.cpp
 ** Description: This is the implementation file of the Menu class.
 ***************************************************************************************/
#include <iostream>
#include "menu.hpp"
#include "inputVal.hpp"

Menu::Menu()
{
    programName = "my Computer Science Program"; //Default program name is "Computer Science Program"
    className   = "CS 162 400 S2019 (Intro to CS II)";
    authorName  = "Ryan Wells Farran";
    intUserInput = 0;
}

Menu::Menu(std::string custProgramName)
{
    programName = custProgramName;
    className   = "CS 325 400 F2019 (Analysis of Algorithms)";
    authorName  = "Ryan Wells Farran";
    intUserInput = 0;
}

int Menu::startMenu()
{   //Introductory greeting
    std::cout << aestheticLine << std::endl;
    std::cout << "Welcome to " << programName << std::endl;
    std::cout << "For " << className << std::endl;
    std::cout << "Written by " << authorName << " using C++." << std::endl;
    std::cout << "(---See README file for help/instructions---)" << std::endl;
    std::cout << aestheticLine << std::endl;
    
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "[menu]     - Enter '1' to START or '2' to EXIT." << std::endl;;
    InputVal dummyInputVal; //used to call getOneOrTwo()
    int userChoice = dummyInputVal.getOneOrTwo();
    std::cout << aestheticLine << std::endl;
    return userChoice;
}

int Menu::endMenu()
{   //Farewell message
    //std::cout << "Thanks, have a wonderful day! :-)" << std::endl;
    //std::cout << aestheticLine << std::endl;
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "[menu]     - Enter '1' to RESTART or '2' to EXIT." << std::endl;;
    InputVal dummyInputVal; //used to call getOneOrTwo()
    int userChoice = dummyInputVal.getOneOrTwo();
    //std::cout << aestheticLine << std::endl;
    return userChoice;
}

int Menu::getMenuOptions()
{
    std::cout << aestheticLine << std::endl;
    std::cout << "[menu]     - Enter an integer from 1 to 3 to" << std::endl;
    std::cout << "[menu]     - select from the choices below." << std::endl;
    std::cout << "[menu]     - 1. Babyfaces vs Heels! (wrestling program)" << std::endl;
    std::cout << "[menu]     - 2. Just take a break from it all..." << std::endl;
    std::cout << "[menu]     - 3. QUIT (back to START/EXIT)." << std::endl;
    //std::cout << aestheticLine << std::endl;
    InputVal dummyInputVal; //used to call getInt()
    int userChoice = dummyInputVal.getPosInt();
    std::cout << aestheticLine << std::endl;
    return userChoice;
}
