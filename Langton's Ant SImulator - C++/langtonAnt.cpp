/***************************************************************************************
 ** Program name: langtonAnt.cpp implementation file for [Week 1, Project 1] CS_162_400_S2019
 ** Author: Ryan Wells Farran
 ** Date: 04/14/2019 | Sunday, April 14th 2019
 ** Description: Implementation file for the langtonAnt.hpp header file. Defines the function prototypes.
 ** The ant can move around the boarda nd changes the color of the square before it moves on to the next one.
 ** If the ant lands on a white square it turns right before moving forward, and alternatively if it
 ** lands on a black square it turns left first beofre moving. These simple rules provide for some
 ** interesting examples under the proper circumstances, especially when the size of the board
 ** and numbers of iterations are increased.
 ***************************************************************************************/
#include "langtonAnt.hpp"

//Ant(LangtonBoard* board, int antRow, int antCol);
LangtonAnt::LangtonAnt(LangtonBoard* board, int antRow, int antCol)
{
    row = antRow; //ant coordinates
    column = antCol; //ant coordinates
    antFacing = UP; //I coudln't figure out how to make it random but I tried it using this: (rand() % 4) + 1
    this->board = board; //used to point to dynamically allocated board
    boardSpace = board->getSpace(row, column); //gets info about current space and stores it
    board->setSpace(row, column, getAnt()); //sets asterisk to indicate ant
}

//void moveAnt();
void LangtonAnt::moveAnt()
{
    int initialRow = row;
    int initialColumn = column;
    
    if (boardSpace == ' ') //If board space is white. Could have declared a constant variable named WHITE
    {
        turnAntRight();
        board->setSpace(initialRow, initialColumn, '#'); //Changes space to black. Could have declared a constant variable named BLACK
        moveAntForward();
    }
    else if (boardSpace == '#') //else if board space is black. Could have declared a constant variable named BLACK
    {
        turnAntLeft();
        board->setSpace(initialRow, initialColumn, ' ');//Changes space to white. Could have declared a constant variable named WHITE
        moveAntForward();
    }
    else
    { //ideally this code should never be called
        std::cout << "You should never see this code!" << std::endl;
        std::cout << "If you do then please restart the program." << std::endl;
    }
}

//void turnAntLeft();
void LangtonAnt::turnAntLeft()
{ //this code runs through the four potential scenarios,
    if (antFacing == UP)  //which in this case are the four
    {                       //potential directions the Langton
        antFacing = LEFT;   //Ant can be facing
    }
    else if (antFacing == LEFT)
    {
        antFacing = DOWN;
    }
    else if (antFacing == DOWN)
    {
        antFacing = RIGHT;
    }
    else if (antFacing == RIGHT)
    {
        antFacing = UP;
    }
    else
    {
        std::cout << "You should never see this code!" << std::endl;
        std::cout << "If you do then please restart the program." << std::endl;
    }
}
//void turnAntRight();
void LangtonAnt::turnAntRight()
{ //This code is the same concept as turnAntLeft(), only this turns to the right,
    if (antFacing == UP) //which can be thought of as clockwise, where as
    {                       //turnAntLeft() turns the Langton Ant counter clockwise
        antFacing = RIGHT;
    }
    else if (antFacing == RIGHT)
    {
        antFacing = DOWN;
    }
    else if (antFacing == DOWN)
    {
        antFacing = LEFT;
    }
    else if (antFacing == LEFT)
    {
        antFacing = UP;
    }
    else
    { //again, this code should ideally never be called. If it is called it means somehow
        std::cout << "You should never see this code!" << std::endl; //junk data was passed into antFacing
        std::cout << "If you do then please restart the program." << std::endl;
    }
}

//void moveAntForward();
void LangtonAnt::moveAntForward()
{
    if (antFacing == UP)
    {
        row--; //moves Ant up by decrementing the index for row
        if (row < 0)
        {
            row = board->getRows() - 1; //this code is used to wrap the ant around the board if it walks past the top edge
        }
    }
    else if (antFacing == LEFT)
    {
        column--; //moves Ant left by decrementing the index for column
        if (column < 0)
        {
            column = board->getCols() - 1; //this code is used to wrap the ant around the board if it walks past the left edge
        }
    }
    else if (antFacing == DOWN)
    {
        row++; //moves Ant down by incrementing the index for row
        if (row == board->getRows()) //tests whether or not ant is at the number of rows, which is one past the index so not available
        {
            row = 0; //this code is used to wrap the ant around the board if it walks past the bottom edge
                    //0 (zero) is merely the top row of the Board
        }
    }
    else if (antFacing == RIGHT)
    {
        column++; //moves Ant right by incrementing the index for column
        if (column == board->getCols()) //tests whether or not ant is at the number of rows, which is one past the index so not available
        {
            column = 0; //this code is used to wrap the ant around the board if it walks past the right edge
            //0 (zero) is merely the left column of the Board
        }
    }
    boardSpace = board->getSpace(row, column);
    board->setSpace(row, column, getAnt());
}

//char getAnt();
char LangtonAnt::getAnt()
{ //simply returns an asterisk ('*') to represent the Langton ant on the board
    return '*';
}
 
