/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: medusa.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the Medusa child class.
 ** Characterstics: Scrawny lady with snakes for hair which helps her during combat.
 ** Just don’t look at her!
 ** Special Abilities: Glare: If a Medusa rolls a 12 when attacking then the target
 ** instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter
 ** on his first life, then Harry Potter comes back to life.
 ***************************************************************************************/

#ifndef medusa_hpp
#define medusa_hpp

#include <stdio.h>
#include <string>
#include "character.hpp"

class Medusa : public Character
{
public:
    Medusa();
    int attack();
    void defend(int attack);
    bool isDead();
    int attackRollDice();
    int defendRollDice();
    std::string getName();
    int getArmor();
    int getStrength();
    void recovery();
    ~Medusa() {}
};



#endif
