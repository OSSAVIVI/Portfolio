/***************************************************************************************
 ** Program name: langtonBoard.cpp implementation file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
 ** Description: This is the implementation code for the langtonBoard.hpp file.
 ** The most challengin part of the code was allocating and deallocating the memory.
 ** I think I fixed it by not calling my destructor, but perhaps there is still a memory leak,
 ** although I did run the program at high output multiple times in a row and never got an error message.
 ** THe code is explained in greater detail in the program.
 ***************************************************************************************/
#include <iostream>
#include "langtonBoard.hpp"

//Definition for LangtonBoard() default constructor prototype;
LangtonBoard::LangtonBoard() //This default constructor is never used so we won't comment on it...
{
    boardRows = 10;
    boardCols = 10;
    
    board = new char*[boardRows];
    for (int index = 0; index < boardRows; ++index)
    {
        board[index] = new char[boardCols];
    }
    makeAllSpacesWhite();
}

//LangtonBoard(int rows, int cols);
LangtonBoard::LangtonBoard(int rows, int cols)
{ //This overloaded constructor takes in user input to set the number of rows and columns
    boardRows = rows;
    boardCols = cols;
    
    //code below allocates memory for 2D array
    board = new char*[boardRows]; //we only need to know how many rows there are due to how sequential memory works
    for (int index = 0; index < boardRows; ++index)
    { //now that we know how many rows we have we can stamp out a series of arrays to allocate our 2D array in memory using boardCols
        board[index] = new char[boardCols];
    }
    makeAllSpacesWhite(); //fills grid with empty white spaces
} //is deallocated in destructor ~LangtonBoard()

//void makeAllSpacesWhite();
void LangtonBoard::makeAllSpacesWhite()
{ //function name is self explanatory, this function makes all the spaces white using a nested for loop and a reference to two indeces
    for (int indexRow = 0; indexRow < boardRows; ++indexRow)
    {
        for (int indexCol = 0; indexCol < boardCols; ++indexCol)
        {
            board[indexRow][indexCol] = ' '; //' ' is equivelant to "white" ('#' is black)
        }
    }
}

//void setSpace(int row, int col, char color);
void LangtonBoard::setSpace(int row, int col, char color)
{ //sets current space ant is at to whatever color is passed into third parameter of function
    if (isValidPosition(row, col))
    {
        board[row][col] = color;
    }
    
    else
    { //this code should ideally never be called, it is just used for formality and debugging purposes
        std::cout << "You should never see this code!" << std::endl;
        std::cout << "If you do then please restart the program." << std::endl;
    }
}

//char getSpace(int row, int col);
char LangtonBoard::getSpace(int row, int col)
{ //returns color (stored char value) of board[][] 2D array
    return board[row][col];
}

//int getRows();
int LangtonBoard::getRows()
{ //simply returns number of rows, used in arithmetic/logic
    return boardRows;
}

//int getCols();
int LangtonBoard::getCols()
{//simply returns number of columns, used in arithmetic/logic
    return boardCols;
}

//bool isValidPosition(int row, int col);
bool LangtonBoard::isValidPosition(int row, int col)
{//This program merely ensures that the position passed as a parameter is not outside the boards dimensions
    bool status = true; //bool variable for functions return to avoid multiple return statments in a single function
    
    if (0 <= row && row < boardRows && 0 <= col && col < boardCols) //testing if in bounds of dimensions set by suer earlier in program
    {
        status = true;
    }
    else
    {
        status = false;
    }
    
    return status;
}
//void printBoard();
void LangtonBoard::printBoard()
{//code used to display current status of board, only complicated thing besides the nested for loops are the '-' and '|' used to draw
    for (int indexCol = 0; indexCol < (boardCols + 2); ++indexCol) //the edges of the board
    {                               //uses '+ 2' to account for the two '|' characters on either side
        std::cout << "-"; //prints top edge of board
    }
    std::cout << std::endl;
    
    for (int indexRow = 0; indexRow < boardRows; ++indexRow)
    {
        std::cout << "|"; //prints left edge of board for each row
        for (int indexCol = 0; indexCol < boardCols; ++indexCol)
        {
            std::cout << board[indexRow][indexCol]; //prints out each element of the board
        }
        std::cout << "|" << std::endl; //prints right edge of board for each row
    }
    
    for (int indexCol = 0; indexCol < (boardCols + 2); ++indexCol)
    {                               //uses '+ 2' to account for the two '|' characters on either side
        std::cout << "-"; //prints bottoom edge of board
    }
    std::cout << std::endl;
}

//~LangtonBoard() destructor to free dynamically allocated memory
LangtonBoard::~LangtonBoard()
{
    for (int indexRows = 0; indexRows < boardRows; ++indexRows)
    {   //same concept as code used from lab1, deallocates the memory from the 'new' memory allocated earlier
        delete [] board[indexRows];
    }
    delete [] board;
}

