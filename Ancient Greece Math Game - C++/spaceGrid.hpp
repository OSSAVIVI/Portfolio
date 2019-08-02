/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: spaceGrid.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the SpaceGrid Class.
 ***************************************************************************************/

#ifndef SPACEGRID_HPP
#define SPACEGRID_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include "space.hpp"
#include "movementSpace.hpp"
#include "riddleSpace.hpp"
#include "goldenLyreSpace.hpp"

class SpaceGrid
{
public: //This was protected up until the last bit of programming, I had to make this public to get it to work...
    std::string aestheticLine = "---------------------------------------------------------------";
    MovementSpace** board;
    int boardRows;
    int boardColumns;
    
    int playerRow; //keep track of player y position
    int playerColumn; //keep track of player x position
    MovementSpace* playerSpace; //This pointer will keep track of where the player is
    
    Space* startingSpace; //character will start in the bottom left corner of the 10x10 grid of Space objects
    int playerHealth;
    
public:
    SpaceGrid();  //Default Constructor
    ~SpaceGrid(); //Destructor prototype
    
    Space* getSpacePtr(int row, int col);
    
    void setRiddlers();
    void setLyres();
    void placeCharacter();
    
    void connectPointers();
    
    bool playerStuck();
    
    void moveUp();
    void moveRight();
    void moveLeft();
    void moveDown();
    
    bool riddlerIsAbovePlayer();
    bool socratesAbove();
    bool euclidAbove();
    bool odysseusAbove();
    bool lyreIsAbovePlayer();
    
    int getPlayerRow();
    int getPlayerColumn();
    
    int getPlayerHealth();
    void setPlayerHealthToZero();
    void decrementPlayerHealth();
    
    void printGrid();
    
};

#endif
