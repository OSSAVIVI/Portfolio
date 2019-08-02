/***************************************************************************************
 ** Program Name: Project 2 | File Name: menu.hpp file
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Description: header fiel for simple menu function that asks the user if they want to
 ** start or exit the program. upon exiting the program it asks if it should restart or conotinue exiting.
 ***************************************************************************************/
#ifndef MENU_HPP //Guards
#define MENU_HPP //Guards

#include <iostream> //Needed for console input/output
#include <string>   //Needed for strings

class Menu //Menu interface
{
private:
    std::string programName; //Customizeable strings can be
    std::string className;   //changed for what program,
    std::string authorName;  //class, and author is relevant
    int intUserInput;
    
public: //Function prototypes defined in menu.cpp file
    Menu(); //Constructor
    Menu(std::string custProgramName);//Overloaded constructor alters program name via parameter
    int startMenu(); //Starting prompts (Either START or QUIT)
    int endMenu();   //Ending prompts (Either RESTART or QUIT)
};


#endif //End Guards
