/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: character.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the Character parent class.
 ***************************************************************************************/

#include "character.hpp"

Character::Character()
{
    //this code should never run
    name = "Empty Object";
    numOfAttackDice = 1;
    numOfAttackDiceSides = 6;
    numOfDefenseDice = 1;
    numOfDefenseDiceSides = 6;
    armor = 1;
    strength = 1;
    isAliveFlag = true;
    isDeadFlag = false;
}

Character::Character(std::string nameIn, int numOfAD, int numOfADS, int numOfDD, int numOfDDS, int armorIn, int strengthIn)
{
    //set all of the variables
    name = nameIn;
    numOfAttackDice = numOfAD;
    numOfAttackDiceSides = numOfADS;
    numOfDefenseDice = numOfDD;
    numOfDefenseDiceSides = numOfDDS;
    armor = armorIn;
    strength = strengthIn;
    isAliveFlag = true;
    isDeadFlag = false;
}
