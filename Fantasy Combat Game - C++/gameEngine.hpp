/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: gameEngine.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the GameEngine class.
 ***************************************************************************************/

#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <stdio.h>
#include "character.hpp"
#include <string>

class GameEngine
{
private:
    std::string aestheticLine = "---------------------------------------------------------------";
    int round;
    bool playerOneAttacksFirst;

public:
    void setWhoAttacksFirstRand();
    void startRounds(Character* playerOne, Character* playerTwo);
    
};

#endif
