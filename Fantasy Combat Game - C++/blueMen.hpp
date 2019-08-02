/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: blueMen.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the BlueMen child class.
 ** Characterstics: They are small, 6 inch tall, but fast and tough. They are hard to
 ** hit so they can take some damage. They can also do a LOT of damage when they crawl
 ** inside enemies’ armor or clothing.
 ** Special Abilities: Mob: Blue Men are actually a swarm of small individuals. For
 ** every 4 points of damage, they lose one defense die. For example, if they have a
 ** strength of 8, they would have 2d6 for defense.
 ***************************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <stdio.h>
#include <string>
#include "character.hpp"

class BlueMen : public Character
{    
public:
    BlueMen();
    int attack();
    void defend(int attack);
    bool isDead();
    int attackRollDice();
    int defendRollDice();
    std::string getName();
    int getArmor();
    int getStrength();
    void recovery();
    ~BlueMen() {}
};



#endif
