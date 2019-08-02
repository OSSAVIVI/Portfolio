/***************************************************************************************
 ** Program name: menu.hpp file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
 ** Description: Modular menu class, work in progress. Currently just takes a parameter,
 ** which is the name of the program to be ran so the intro output can be customizeable.
 ** More detail canbe found in the menu.cpp implementation file.
 ***************************************************************************************/
#ifndef MENU_HPP //Guards
#define MENU_HPP //Guards

#include <iostream> //Needed for console input/output
#include <string>   //Needed for strings?

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
