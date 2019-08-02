/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: harryPotter.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the HarryPotter child class.
 ** Characterstics: Harry Potter is a wizard.
 ** Special Abilities: Hogwarts: If Harry Potter's strength reaches 0 or below, he
 ** immediately recovers and his total strength becomes 20. If he were to die again,
 ** then he’s dead.
 ***************************************************************************************/

#ifndef harryPotter_hpp
#define harryPotter_hpp

#include <stdio.h>
#include <string>
#include "character.hpp"

class HarryPotter : public Character
{
protected:
    bool hasDiedOnce;
    
public:
    HarryPotter();
    int attack();
    void defend(int attack);
    bool isDead();
    int attackRollDice();
    int defendRollDice();
    std::string getName();
    int getArmor();
    int getStrength();
    void recovery();
    ~HarryPotter() {}
};



#endif
