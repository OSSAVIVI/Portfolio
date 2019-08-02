/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: menu.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Implementation file for the Menu Class.
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
    std::cout << "THEME: Ancient Greece!" << std::endl;
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
    std::cout << "[menu]     - Select 1 or 2 from the choices below." << std::endl;
    std::cout << "[menu]     - 1. START A NEW GAME!" << std::endl;
    std::cout << "[menu]     - 2. QUIT (back to START/EXIT)" << std::endl;
    std::cout << aestheticLine << std::endl;
    InputVal dummyInputVal; //used to call getInt()
    int userChoice = dummyInputVal.getPosInt();
    std::cout << aestheticLine << std::endl;
    return userChoice;
}
