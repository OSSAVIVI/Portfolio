/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: harryPotter.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the HarryPotter child class.
 ** Characterstics: Harry Potter is a wizard.
 ** Special Abilities: Hogwarts: If Harry Potter's strength reaches 0 or below, he
 ** immediately recovers and his total strength becomes 20. If he were to die again,
 ** then he’s dead.
 ***************************************************************************************/

#include "harryPotter.hpp"
#include "character.hpp"

HarryPotter::HarryPotter() : Character("Harry Potter", 2, 6, 2, 6, 0, 10)
{
    hasDiedOnce = false;
}

int HarryPotter::attack()
{
    std::cout << "The HarryPotter is attacking!" << std::endl;
    int attackDamage = attackRollDice(); //displays rolling dice info
    std::cout << "The HarryPotter dealt " << attackDamage << " attack points!" << std::endl;
    return attackDamage;
}

void HarryPotter::defend(int attack)
{
    int defensePoints = defendRollDice(); //displays rolling dice info
    int inflictedDamage;
    
    if (attack != 666) //test to see if medusa used Glare
    {
        std::cout << "      HarryPotter is defending!" << std::endl;
        std::cout << "      Pre-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        std::cout << "      HarryPotter mustered " << defensePoints << " defense points!" << std::endl;
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
        std::cout << "      HarryPotter defended the attack completely!" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage == armor)
    {
        armor -= inflictedDamage;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        std::cout << "      HarryPotter's armor blocked the attack, but is now ruined." << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage == 666) //Medusa Glare will be trumped by charm
    {
        std::cout << "Total Inflicted Damage: ∞ (infiniti)" << std::endl;
        std::cout << "      ☆☆☆ The HarryPotter looks into Medusa's eyes ☆☆☆" << std::endl;
        std::cout << "      ☆☆☆ and is magically turned into stone!! ☆☆☆" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: 0" << std::endl;
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
            std::cout << "      HarryPotter survived the attack..." << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        }
        else if (strength <=0)
        {
            std::cout << "      HarryPotter didn't survive the attack :(" << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
            if (!hasDiedOnce)
            {
                std::cout << "☆☆☆ The strength of Hogwartz ☆☆☆" << std::endl;
                std::cout << "☆☆☆ restores his strength!!! ☆☆☆" << std::endl;
                strength = 20;
                hasDiedOnce = true;
            }
            else
            {
                isDeadFlag = true;
                isAliveFlag = false;
            }
        }
    }
    else
    {
        std::cout << "This code shoudl never run, check HarryPotter.cpp infilctedDamage and armor variables" << std::endl;
    }
}

bool HarryPotter::isDead()
{
    return isDeadFlag;
}

/*
 numOfAttackDice = numOfAD;
 numOfAttackDiceSides = numOfADS;
 numOfDefenseDice = numOfDD;
 numOfDefenseDiceSides = numOfDDS;
 
 */

int HarryPotter::attackRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfAttackDice; index++)
    {
        int roll = rand() % numOfAttackDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

int HarryPotter::defendRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfDefenseDice; index++)
    {
        int roll = rand() % numOfDefenseDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

std::string HarryPotter::getName()
{
    return name;
}

int HarryPotter::getArmor()
{
    return armor;
}

int HarryPotter::getStrength()
{
    return strength;
}

void HarryPotter::recovery()
{
    if (strength < 10) //if damage was taken, then health is multiplied by 1.5
    {
        std::cout << "Harry Potter is recovering..." << std::endl;
        strength *= 1.5;
        std::cout << "Harry Potter's strength is now " << getStrength() << "!" << std::endl;
    }
}
