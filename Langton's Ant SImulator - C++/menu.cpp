/***************************************************************************************
 ** Program name: menu.cpp file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
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
    className   = "CS_162_400_S2019 (Intro to CS II)";
    authorName  = "Ryan Wells Farran"; //I put my middle name sometimes cause I am a dork
    intUserInput = 0;
}

Menu::Menu(std::string custProgramName)
{
    programName = custProgramName;
    className   = "CS_162_400_S2019 (Intro to CS II)";
    authorName  = "Ryan Wells Farran"; //I put my middle name sometimes cause I am a dork
    intUserInput = 0;
}

int Menu::startMenu()
{   //Introductory greeting
    std::cout << "Welcome to " << programName << std::endl;
    std::cout << "for " << className << std::endl;
    std::cout << "written by " << authorName << "." << std::endl;
    
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "Please enter 1 to START or 2 to QUIT." << std::endl;;
    inputVal dummyInputVal; //used to call getInt()
    return dummyInputVal.getInt();
}

int Menu::endMenu()
{   //Farewell message
    std::cout << "Thanks for your time..." << std::endl;
    //Gets integer, validates data using inputVal.getInt(), and returns value
    std::cout << "Please enter 1 to RESTART or 2 to QUIT." << std::endl;;
    inputVal dummyInputVal;
    return dummyInputVal.getInt();
}
