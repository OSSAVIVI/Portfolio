/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: menu.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description: This is the implementation file for the Menu class.
 ***************************************************************************************/
#include <iostream>
#include "menu.hpp"
#include "inputVal.hpp"
#include "character.hpp"

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
    className   = "CS 162 400 S2019 (Intro to CS II)";
    authorName  = "Ryan Wells Farran";
    intUserInput = 0;
}

int Menu::startMenu()
{   //Introductory greeting
    std::cout << aestheticLine << std::endl;
    std::cout << "Welcome to " << programName << std::endl;
    std::cout << "for " << className << std::endl;
    std::cout << "by " << authorName << "." << std::endl;
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
    std::cout << "Thanks, have a wonderful day! :-)" << std::endl;
    std::cout << aestheticLine << std::endl;
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "[menu]     - Enter '1' to RESTART or '2' to EXIT." << std::endl;;
    InputVal dummyInputVal; //used to call getOneOrTwo()
    int userChoice = dummyInputVal.getOneOrTwo();
    std::cout << aestheticLine << std::endl;
    return userChoice;
}

int Menu::getMenuOptions()
{
    std::cout << aestheticLine << std::endl;
    std::cout << "[menu]     - Enter an integer from 1 to 6 to" << std::endl;
    std::cout << "[menu]     - select from the choices below." << std::endl;
    std::cout << "[menu]     - 1. Vampire" << std::endl;
    std::cout << "[menu]     - 2. Barbarian" << std::endl;
    std::cout << "[menu]     - 3. Blue Men" << std::endl;
    std::cout << "[menu]     - 4. Medusa" << std::endl;
    std::cout << "[menu]     - 5. Harry Potter" << std::endl;
    std::cout << "[menu]     - 6. QUIT (back to START/EXIT)" << std::endl;

    std::cout << aestheticLine << std::endl;
    InputVal dummyInputVal; //used to call getInt()
    int userChoice = dummyInputVal.getPosInt();
    std::cout << aestheticLine << std::endl;
    return userChoice;
}

int Menu::getMenuOptionsPlayerOne()
{
    std::cout << aestheticLine << std::endl;
    std::cout << "[menu]     - TEAM ONE, CHOOSE A CHARACTER!" << std::endl;
    std::cout << aestheticLine << std::endl;
    int playerOneChoice = getMenuOptions();
    return playerOneChoice;
}

int Menu::getMenuOptionsPlayerTwo()
{
    std::cout << aestheticLine << std::endl;
    std::cout << "[menu]     - TEAM TWO, CHOOSE A CHARACTER!" << std::endl;
    std::cout << aestheticLine << std::endl;
    int playerTwoChoice = getMenuOptions();
    return playerTwoChoice;
}
