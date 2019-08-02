/***************************************************************************************
 ** Program name: langtonBoard.hpp header file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
 ** Description: THis si the header file for the langtonBoard.cpp implementation file.
 ** This interface basically shows you that there are constructors and destructors for
 ** allocating and deallocating the boards memory. I made a default constructor for good practice,
 ** even though it is never used.
 ***************************************************************************************/
#ifndef LANGTONBOARD_HPP
#define LANGTONBOARD_HPP

#include <iostream>

class LangtonBoard //LangtonBoard class interface
{ //Variables needed to construct board are given by user in mainProject1.cpp file
    private:
        char** board; //double pointer of type char used to create 2D array
        int boardRows; //number of rows set by user
        int boardCols; //number of columns set by user
    
    public: //Prototypes will be defined in LangtonBoard.cpp
        LangtonBoard(); //default constructor prototype
        LangtonBoard(int rows, int cols); //overloaded constructor prototype uses user in put as parameters to set board dimensions
        void makeAllSpacesWhite(); //fills grid with blank white spaces
        void setSpace(int row, int col, char color); //sets color of current space
        char getSpace(int row, int col); //gets color of current space
        int getRows(); //gets number of rows, used in arithmetic
        int getCols(); //gets number of columns, used in arithmetic
        bool isValidPosition(int row, int col); //ensures a position is an actual spot on the board (not outside bounds)
        void printBoard(); //displays the board to the console (is epic to watch lol)
        ~LangtonBoard(); //Destructor for LangtonBoard will be called with delete to free memory
};

#endif
