/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: spaceGrid.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Implementation file for the SpaceGrid Class.
 ***************************************************************************************/

#include "spaceGrid.hpp"
#include "inventory.hpp"

SpaceGrid::SpaceGrid()  //Default Constructor
{
    boardRows = 10;
    boardColumns = 10;
    playerRow = 1;
    playerColumn = 1;
    playerSpace = nullptr;
    startingSpace = nullptr;
    playerHealth = 30;
    
    board = new MovementSpace*[boardRows];
    for (int index = 0; index < boardRows; ++index)
    {
        board[index] = new MovementSpace[boardColumns];
    }
    
    //setRiddlers();
}

SpaceGrid::~SpaceGrid()
{
    for (int indexRows = 0; indexRows < boardRows; ++indexRows)
    {   //same concept as code used from lab1, deallocates the memory from the 'new' memory allocated earlier
        delete [] board[indexRows];
    }
    delete [] board;
}


void SpaceGrid::setRiddlers()
{
    RiddleSpace* Socrates = new RiddleSpace('S', "Socrates", nullptr, nullptr, nullptr, nullptr);
    board[7][1].setRiddler(Socrates);
    board[7][1].setMarker(Socrates->getMarker());
    board[7][1].setCanMoveHere(false);
    
    RiddleSpace* Euclid = new RiddleSpace('E', "Euclid", nullptr, nullptr, nullptr, nullptr);
    board[5][7].setRiddler(Euclid);
    board[5][7].setMarker(Euclid->getMarker());
    board[5][7].setCanMoveHere(false);
    
    RiddleSpace* Odysseus = new RiddleSpace('O', "Odysseus", nullptr, nullptr, nullptr, nullptr);
    board[2][3].setRiddler(Odysseus);
    board[2][3].setMarker(Odysseus->getMarker());
    board[2][3].setCanMoveHere(false);
}

void SpaceGrid::setLyres()
{
    GoldenLyreSpace* Lyre = new GoldenLyreSpace(nullptr, nullptr, nullptr, nullptr);
    board[0][5].setLyre(Lyre);
    board[0][5].setMarker(Lyre->getMarker());
    board[0][5].setCanMoveHere(false);
}

void SpaceGrid::placeCharacter()
{
    playerSpace = &board[9][0];
    playerRow = 9;
    playerColumn = 0;
    board[9][0].setMarker('#');
}


void SpaceGrid::connectPointers()
{
    for (int rowIndex = 0; rowIndex < 9; rowIndex++)
    {
        for (int colIndex = 0; colIndex < 9; colIndex++)
        {
            if (rowIndex == 0) //handles the top border
            {
                if (colIndex != 0)//not at left border
                {
                    board[rowIndex][colIndex].left = &board[rowIndex][colIndex-1];
                }
                if (colIndex != 9)//not at right border
                {
                    board[rowIndex][colIndex].right = &board[rowIndex][colIndex+1];
                }
                if (rowIndex != 0) //not at the top border
                {
                    board[rowIndex][colIndex].top = &board[rowIndex-1][colIndex];
                }
                if (rowIndex != 9) //not at the bottom border
                {
                    board[rowIndex][colIndex].bottom = &board[rowIndex+1][colIndex];
                }
            }
        }
    }
}

bool SpaceGrid::playerStuck()
{
    bool status = false;
    
    if (board[playerRow-1][playerColumn].playerCanMoveHere() == false &&
        board[playerRow+1][playerColumn].playerCanMoveHere() == false &&
        board[playerRow][playerColumn-1].playerCanMoveHere() == false &&
        board[playerRow][playerColumn+1].playerCanMoveHere() == false)
    {
        status = true;
        std::cout << "Player stuck! You Lose!" << std::endl;
        playerHealth = 0;
    }
    return status;
}

void SpaceGrid::moveUp()
{
    if (!playerStuck())
    {
        if (playerRow != 0)
        {
            playerSpace->setCanMoveHere(false);
            if (board[playerRow-1][playerColumn].playerCanMoveHere())
            {
                playerSpace->setMarker('*');
                playerRow--;
                playerSpace = &board[playerRow][playerColumn];
                board[playerRow][playerColumn].setMarker('#');
                decrementPlayerHealth();
            }
            else
            {
                std::cout << "Someone/Something is in the way..." << std::endl;
            }
        }
        else
        {
            std::cout << "Top border reached! Can't move upwards!" << std::endl;
        }
    }
    
}

void SpaceGrid::moveRight()
{
    if (!playerStuck())
    {
        if (playerColumn != 9)
        {
            playerSpace->setCanMoveHere(false);
            if (board[playerRow][playerColumn+1].playerCanMoveHere())
            {
                playerSpace->setMarker('*');
                playerColumn++;
                playerSpace = &board[playerRow][playerColumn];
                board[playerRow][playerColumn].setMarker('#');
                decrementPlayerHealth();
            }
            else
            {
                std::cout << "Someone/Something is in the way..." << std::endl;
            }
        }
        else
        {
            std::cout << "Right border reached! Can't move rightwards!" << std::endl;
        }
    }
}

void SpaceGrid::moveLeft()
{
    if (!playerStuck())
    {
        if (playerColumn != 0)
        {
            playerSpace->setCanMoveHere(false);
            if (board[playerRow][playerColumn-1].playerCanMoveHere())
            {
                playerSpace->setMarker('*');
                playerColumn--;
                playerSpace = &board[playerRow][playerColumn];
                board[playerRow][playerColumn].setMarker('#');
                decrementPlayerHealth();
            }
            else
            {
                std::cout << "Someone/Something is in the way..." << std::endl;
            }
        }
        else
        {
            std::cout << "Left border reached! Can't move leftwards!" << std::endl;
        }
    }
}

void SpaceGrid::moveDown()
{
    if (!playerStuck())
    {
        if (playerRow != 9)
        {
            playerSpace->setCanMoveHere(false);
            if (board[playerRow+1][playerColumn].playerCanMoveHere())
            {
                playerSpace->setMarker('*');
                playerRow++;
                playerSpace = &board[playerRow][playerColumn];
                board[playerRow][playerColumn].setMarker('#');
                decrementPlayerHealth();
            }
            else
            {
                std::cout << "Someone/Something is in the way..." << std::endl;
            }
        }
        else
        {
            std::cout << "Bottom border reached! Can't move downwards!" << std::endl;
        }
    }
}

bool SpaceGrid::riddlerIsAbovePlayer()
{
    bool wellIsIt = false;
    if (board[playerRow-1][playerColumn].getMarker() == 'S' ||
        board[playerRow-1][playerColumn].getMarker() == 'E' ||
        board[playerRow-1][playerColumn].getMarker() == 'O')
    {
        wellIsIt = true;
    }
    return wellIsIt;
}

bool SpaceGrid::socratesAbove()
{
    bool wellIsIt = false;
    if (board[playerRow-1][playerColumn].getMarker() == 'S')
    {
        wellIsIt = true;
    }
    return wellIsIt;
}

bool SpaceGrid::euclidAbove()
{
    bool wellIsIt = false;
    if (board[playerRow-1][playerColumn].getMarker() == 'E')
    {
        wellIsIt = true;
    }
    return wellIsIt;
}

bool SpaceGrid::odysseusAbove()
{
    bool wellIsIt = false;
    if (board[playerRow-1][playerColumn].getMarker() == 'O')
    {
        wellIsIt = true;
    }
    return wellIsIt;
}

bool SpaceGrid::lyreIsAbovePlayer()
{
    bool wellIsIt = false;
    if (board[playerRow-1][playerColumn].getMarker() == 'U')
    {
        wellIsIt = true;
    }
    return wellIsIt;
}

int SpaceGrid::getPlayerRow()
{
    return playerRow;
}

int SpaceGrid::getPlayerColumn()
{
    return playerColumn;
}

int SpaceGrid::getPlayerHealth()
{
    if (playerHealth <= 0)
    {
        std::cout << "YOU DIED!!!" << std::endl;
    }
    return playerHealth;
}
void SpaceGrid::setPlayerHealthToZero()
{
    playerHealth = -1000;
}

void SpaceGrid::decrementPlayerHealth()
{
    playerHealth--;
}


Space* SpaceGrid::getSpacePtr(int row, int col)
{
    return &(board[row][col]);
}
                    
void SpaceGrid::printGrid()
{
    std::cout << aestheticLine << std::endl;
    std::cout << "GAME MAP:" << std::endl;
    for (int indexCol = 0; indexCol < (boardColumns + 2); ++indexCol) //the edges of the board
    {                               //uses '+ 2' to account for the two '|' characters on either side
        std::cout << "-"; //prints top edge of board
    }
    std::cout << std::endl;
    
    for (int indexRow = 0; indexRow < boardRows; ++indexRow)
    {
        std::cout << "|"; //prints left edge of board for each row
        for (int indexCol = 0; indexCol < boardColumns; ++indexCol)
        {
            std::cout << board[indexRow][indexCol].getMarker(); //prints out each element of the board
        }
        std::cout << "|" << std::endl; //prints right edge of board for each row
    }
    
    for (int indexCol = 0; indexCol < (boardColumns + 2); ++indexCol)
    {                               //uses '+ 2' to account for the two '|' characters on either side
        std::cout << "-"; //prints bottoom edge of board
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "# = Player, * = Already Been," << std::endl;
    std::cout << "U = Pythagoras' Golden Lyre!," << std::endl;
    std::cout << "S = Socrates, E = Euclid, O = Odysseus" << std::endl;
    std::cout << aestheticLine << std::endl;
    std::cout << "♥♥♥ Steps remaining: " << getPlayerHealth() << " (GAME OVER at ZERO!) ♥♥♥" << std::endl;
    std::cout << aestheticLine << std::endl;
}
