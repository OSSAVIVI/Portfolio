/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: menu.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the Menu Class.
 ***************************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <stdio.h>
#include <string>

class Menu
{
private:
    std::string aestheticLine = "---------------------------------------------------------------"; //Used to visually seperate console output
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
};

#endif
