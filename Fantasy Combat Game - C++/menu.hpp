/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: menu.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the Menu class.
 ***************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <stdio.h>
#include <string>

class Menu
{
private:
    std::string aestheticLine = "---------------------------------------------------------------";
    std::string programName; //Customizeable strings can be
    std::string className;   //changed for what program,
    std::string authorName;  //class, and author is relevant
    int intUserInput;
    
public: //Function prototypes defined in menu.cpp file
    Menu(); //Constructor
    Menu(std::string custProgramName);//Overloaded constructor alters program name via parameter
    int startMenu(); //Starting prompts (Either START or QUIT)
    int endMenu();   //Ending prompts (Either RESTART or QUIT)
    int getMenuOptions(); //Displays menu options for user to select from
    int getMenuOptionsPlayerOne();
    int getMenuOptionsPlayerTwo();
};

#endif
