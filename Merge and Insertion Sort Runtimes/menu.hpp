/***************************************************************************************
 ** File Name: menu.hpp
 ** Description: This is the header file of the Menu class.
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
