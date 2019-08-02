/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: barbarian.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the Barbarian child class.
 ** Characterstics: Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.
 ** Special Abilities: none
 ***************************************************************************************/

#include "barbarian.hpp"
#include "character.hpp"

Barbarian::Barbarian() : Character("Barbarian", 2, 6, 2, 6, 0, 12)
{
    //no other values are set besides those in constructor
}

int Barbarian::attack()
{
    std::cout << "The Barbarian is attacking!" << std::endl;
    int attackDamage = attackRollDice(); //displays rolling dice info
    std::cout << "The Barbarian dealt " << attackDamage << " attack points!" << std::endl;
    return attackDamage;
}

void Barbarian::defend(int attack)
{ 
    int defensePoints = defendRollDice(); //displays rolling dice info
    int inflictedDamage;
    
    if (attack != 666) //test to see if medusa used Glare
    {
        std::cout << "      The Barbarian is defending!" << std::endl;
        std::cout << "      Pre-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << "(barbarian has no armor)" << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        std::cout << "      The Barbarian mustered " << defensePoints << " defense points!" << std::endl;
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
        std::cout << "      The Barbarian defended the attack completely!" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << " (barbarian has no armor)"  << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    /* commented out since barbarian doesnt ahve any armor
    else if (inflictedDamage == armor)
    {
        armor -= inflictedDamage;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        std::cout << "The Barbarian's armor blocked the attack, but is now ruined." << std::endl;
        std::cout << "Post-Defend Stats:" << std::endl;
        std::cout << "Armor: " << armor << std::endl;
        std::cout << "Strength: " << strength << " (health points)" << std::endl;
    }
     */
    else if (inflictedDamage == 666) //Medusa Glare will be trumped by charm
    {
        std::cout << "Total Inflicted Damage: ∞ (infiniti)" << std::endl;
        std::cout << "      ☆☆☆ The Barbarian looks into Medusa's eyes ☆☆☆" << std::endl;
        std::cout << "      ☆☆☆ and is magically turned into stone!! ☆☆☆" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: 0 (barbarian has no armor)"  << std::endl;
        armor = 0;
        std::cout << "      Strength: 0 (health points)" << std::endl;
        strength = 0;
        isDeadFlag = true;
        isAliveFlag = false;
    }
    else if (inflictedDamage > armor)
    {
        inflictedDamage -= armor;
        strength -= inflictedDamage;
        armor = 0;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        if (strength > 0)
        {
            std::cout << "      The Barbarian survived the attack..." << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << "(barbarian has no armor)"  << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        }
        else if (strength <=0)
        {
            std::cout << "      The Barbarian didn't survive the attack :(" << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << "(barbarian has no armor)"  << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
            isDeadFlag = true;
            isAliveFlag = false;
        }
    }
    else
    {
        std::cout << "This code should never run, check Barbarian.cpp infilctedDamage and armor variables" << std::endl;
    }
}

bool Barbarian::isDead()
{
    return isDeadFlag;
}

/*
 numOfAttackDice = numOfAD;
 numOfAttackDiceSides = numOfADS;
 numOfDefenseDice = numOfDD;
 numOfDefenseDiceSides = numOfDDS;
 
 */

int Barbarian::attackRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfAttackDice; index++)
    {
        int roll = rand() % numOfAttackDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

int Barbarian::defendRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfDefenseDice; index++)
    {
        int roll = rand() % numOfDefenseDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

std::string Barbarian::getName()
{
    return name;
}

int Barbarian::getArmor()
{
    return armor;
}

int Barbarian::getStrength()
{
    return strength;
}

void Barbarian::recovery()
{
    if (strength < 12) //if damage was taken, then health is multiplied by 1.5
    {
        std::cout << "Barbarian is recovering..." << std::endl;
        strength *= 1.5;
        std::cout << "Barbarian's strength is now " << getStrength() << "!" << std::endl;
    }
}
