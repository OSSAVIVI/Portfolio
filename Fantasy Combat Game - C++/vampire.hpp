/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: vampire.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the Vampire child class.
 ** Characterstics: Suave, debonair, but vicious and surprisingly resilient.
 ** Special Abilities: Charm: Vampires can charm an opponent into not attacking.
 ** For a given attack there is a 50% chance that their opponent does not actually attack them.
 ***************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <stdio.h>
#include <string>
#include "character.hpp"

class Vampire : public Character
{
protected:
    bool charm; //is set to false at first, but true 50% of defend times
    
public:
    Vampire();
    int attack();
    void defend(int attack);
    bool isDead();
    int attackRollDice();
    int defendRollDice();
    std::string getName();
    int getArmor();
    int getStrength();
    void recovery();
    ~Vampire() {}
};



#endif
