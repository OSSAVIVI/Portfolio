/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: character.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the Character parent class.
 ***************************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <stdio.h>
#include <iostream>
#include <string>

class Character
{
protected:
    std::string name;
    int numOfAttackDice;
    int numOfAttackDiceSides;
    int numOfDefenseDice;
    int numOfDefenseDiceSides;
    int armor;
    int strength;
    bool isAliveFlag;
    bool isDeadFlag;
    
public:
    Character();
    Character(std::string nameIn, int numOfAD, int numOfADS, int numOfDD, int numOfDDS, int armorIn, int strengthIn);
    virtual int attack() = 0;
    virtual void defend(int attack) = 0;
    virtual bool isDead() = 0;
    virtual int attackRollDice() = 0;
    virtual int defendRollDice() = 0;
    virtual std::string getName() = 0;
    virtual int getArmor() = 0;
    virtual int getStrength() = 0;
    virtual void recovery() = 0;
    virtual ~Character() {}
};

#endif
