/***************************************************************************************
 ** Program name: langtonAnt.hpp header file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
 ** Description: This is the header fie with all of the prototypes and variables defined and
 ** implemented in the langtonAnt.cpp file. For more of an understandnig of how the code works
 ** read the comments there, but you can get an idea of the program by looking at its interface here.
 ***************************************************************************************/
#ifndef LANGTONANT_HPP //Guards
#define LANGTONANT_HPP //Guards

#include <iostream>
#include "langtonBoard.hpp"

class LangtonAnt
{
    private:
        enum Facing {UP = 1, DOWN, LEFT, RIGHT}; //used to determine what direction the ant is facing
        Facing antFacing; //declare a variable of this type to be used in functions
    
        int row; //Ant's location (Y coord)
        int column; //Ant's location (X coord)
        char boardSpace; //Used to set the color/symbol used on the board
        LangtonBoard* board; //points to an object of type LangtonBoard
    
    public: //Ant class function prototypes to be defined in langtonAnt.cpp
        LangtonAnt(LangtonBoard* board, int antRow, int antCol);
        void moveAnt(); //calls the move forward and turning functions
        void turnAntLeft();
        void turnAntRight();
        void moveAntForward();
        char getAnt(); //simply returns an asterisk ('*')
};

#endif
