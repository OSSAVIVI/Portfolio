/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: medusa.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the Medusa child class.
 ** Characterstics: Scrawny lady with snakes for hair which helps her during combat.
 ** Just don’t look at her!
 ** Special Abilities: Glare: If a Medusa rolls a 12 when attacking then the target
 ** instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter
 ** on his first life, then Harry Potter comes back to life.
 ***************************************************************************************/

#include "medusa.hpp"
#include "character.hpp"

Medusa::Medusa() : Character("Medusa", 2, 6, 1, 6, 3, 8)
{
    //no other variables
}

int Medusa::attack()
{
    std::cout << "The Medusa is attacking!" << std::endl;
    int attackDamage = attackRollDice(); //displays rolling dice info
    if (attackDamage == 12)
    {
        std::cout << "The Medusa dealt " << attackDamage << " attack points!" << std::endl;
        std::cout << "☆☆☆ Medusa used glare!!! ☆☆☆" << std::endl;
        std::cout << "☆☆☆ Don't look into her eyes! ☆☆☆" << std::endl;
        attackDamage = 666; //triggers defend function in sibling classes
    }
    else
    {
        std::cout << "The Medusa dealt " << attackDamage << " attack points!" << std::endl;
    }
    return attackDamage;
}

void Medusa::defend(int attack)
{ 
    int defensePoints = defendRollDice(); //displays rolling dice info
    int inflictedDamage;
    
    if (attack != 666) //test to see if medusa used Glare
    {
        std::cout << "      Medusa is defending!" << std::endl;
        std::cout << "      Pre-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        std::cout << "      Medusa mustered " << defensePoints << " defense points!" << std::endl;
        inflictedDamage = attack - defensePoints;
    }
    else
    {
        inflictedDamage = attack; //set this for medusa attack code later
    }
    
    if (inflictedDamage <= 0)
    {
        inflictedDamage = 0;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        std::cout << "      Medusa defended the attack completely!" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage == armor)
    {
        armor -= inflictedDamage;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        std::cout << "      Medusa's armor blocked the attack, but is now ruined." << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage == 666) //Medusa Glare will be trumped by charm
    {
        std::cout << "Total Inflicted Damage: ∞ (infiniti)" << std::endl;
        std::cout << "      ☆☆☆ Medusa looks into Medusa's eyes ☆☆☆" << std::endl;
        std::cout << "      ☆☆☆ and is magically turned into stone!! ☆☆☆" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: 0" << std::endl;
        armor = 0;
        std::cout << "      Strength: 0 (health points)" << std::endl;
        strength = 0;
        isDeadFlag = true;
        isAliveFlag = false;
    }
    else if (inflictedDamage < armor)
    {
        armor -= inflictedDamage;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        std::cout << "      Medusa's armor blocked the attack, but was damaged." << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage > armor)
    {
        inflictedDamage -= armor;
        strength -= inflictedDamage;
        armor = 0;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        if (strength > 0)
        {
            std::cout << "      Medusa survived the attack..." << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        }
        else if (strength <=0)
        {
            std::cout << "      Medusa didn't survive the attack :(" << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
            isDeadFlag = true;
            isAliveFlag = false;
        }
    }
    else
    {
        std::cout << "This code shoudl never run, check Medusa.cpp infilctedDamage and armor variables" << std::endl;
    }
}

bool Medusa::isDead()
{
    return isDeadFlag;
}

/*
 numOfAttackDice = numOfAD;
 numOfAttackDiceSides = numOfADS;
 numOfDefenseDice = numOfDD;
 numOfDefenseDiceSides = numOfDDS;
 
 */

int Medusa::attackRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfAttackDice; index++)
    {
        int roll = rand() % numOfAttackDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

int Medusa::defendRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfDefenseDice; index++)
    {
        int roll = rand() % numOfDefenseDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

std::string Medusa::getName()
{
    return name;
}

int Medusa::getArmor()
{
    return armor;
}

int Medusa::getStrength()
{
    return strength;
}

void Medusa::recovery()
{
    if (strength < 8) //if damage was taken, then health is multiplied by 1.5
    {
        std::cout << "Medusa is recovering..." << std::endl;
        strength *= 1.5;
        std::cout << "Medusa's strength is now " << getStrength() << "!" << std::endl;
    }
}
