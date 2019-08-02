/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: barbarian.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the Barbarian child class.
 ** Characterstics: Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.
 ** Special Abilities: none
 ***************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <stdio.h>
#include <string>
#include "character.hpp"

class Barbarian : public Character
{
public:
    Barbarian();
    int attack();
    void defend(int attack);
    bool isDead();
    int attackRollDice();
    int defendRollDice();
    std::string getName();
    int getArmor();
    int getStrength();
    void recovery();
    ~Barbarian() {}
};



#endif
