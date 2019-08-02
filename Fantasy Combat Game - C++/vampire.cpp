/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: vampire.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the Vampire child class.
 ** Characterstics: Suave, debonair, but vicious and surprisingly resilient.
 ** Special Abilities: Charm: Vampires can charm an opponent into not attacking.
 ** For a given attack there is a 50% chance that their opponent does not actually attack them.
 ***************************************************************************************/

#include "vampire.hpp"
#include "character.hpp"

Vampire::Vampire() : Character("Vampire", 1, 12, 1, 6, 1, 18)
{
    charm = false;
}

int Vampire::attack()
{
    std::cout << "The Vampire is attacking!" << std::endl;
    int attackDamage = attackRollDice(); //displays rolling dice info
    std::cout << "The Vampire dealt " << attackDamage << " attack points!" << std::endl;
    return attackDamage;
}

void Vampire::defend(int attack)
{ //Special defend function because of charm
    int randomNumber = ((rand() % 2) + 1); //chooses number between one and twoo (50% chance of charm)
    if (randomNumber == 2)
    {
        charm = true;
    }
    else // if charm = 1
    {
        charm = false;
    }
    
    if (charm) //charm  is activated
    {
        std::cout << "☆☆☆ The Vampire charmed the opponent into not attacking! ☆☆☆" << std::endl;
        std::cout << "☆☆☆ The Vampire has received no damage this turn. ☆☆☆" << std::endl;
        charm = false; //resets charm back to false
    }
    else // if charm is false, roll dice to defend
    {
        int defensePoints = defendRollDice(); //displays rolling dice info
        int inflictedDamage;
        
        if (attack != 666) //test to see if medusa used Glare
        {
            std::cout << "      The Vampire is defending!" << std::endl;
            std::cout << "      Pre-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
            std::cout << "      The Vampire mustered " << defensePoints << " defense points!" << std::endl;
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
            std::cout << "      The Vampire defended the attack completely!" << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        }
        else if (inflictedDamage == armor)
        {
            armor -= inflictedDamage;
            std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
            std::cout << "      The Vampire's armor blocked the attack, but is now ruined." << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        }
        else if (inflictedDamage == 666) //Medusa Glare will be trumped by charm
        {
            std::cout << "Total Inflicted Damage: ∞ (infiniti)" << std::endl;
            std::cout << "      ☆☆☆ The Vampire looks into Medusa's eyes ☆☆☆" << std::endl;
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
                std::cout << "      The Vampire survived the attack..." << std::endl;
                std::cout << "      Post-Defend Stats:" << std::endl;
                std::cout << "      Armor: " << armor << std::endl;
                std::cout << "      Strength: " << strength << " (health points)" << std::endl;
            }
            else if (strength <=0)
            {
                std::cout << "      The Vampire didn't survive the attack :(" << std::endl;
                std::cout << "      Post-Defend Stats:" << std::endl;
                std::cout << "      Armor: " << armor << std::endl;
                std::cout << "      Strength: " << strength << " (health points)" << std::endl;
                isDeadFlag = true;
                isAliveFlag = false;
            }
        }
        else
        {
            std::cout << "This code shoudl never run, check vampire.cpp infilctedDamage and armor variables" << std::endl;
        }
    }
}

bool Vampire::isDead()
{
    return isDeadFlag;
}

/*
 numOfAttackDice = numOfAD;
 numOfAttackDiceSides = numOfADS;
 numOfDefenseDice = numOfDD;
 numOfDefenseDiceSides = numOfDDS;
 
 */

int Vampire::attackRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfAttackDice; index++)
    {
        int roll = rand() % numOfAttackDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

int Vampire::defendRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfDefenseDice; index++)
    {
        int roll = rand() % numOfDefenseDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

std::string Vampire::getName()
{
    return name;
}

int Vampire::getArmor()
{
    return armor;
}

int Vampire::getStrength()
{
    return strength;
}

void Vampire::recovery()
{
    if (strength < 18) //if damage was taken, then health is multiplied by 1.5
    {
        std::cout << "Vampire is recovering..." << std::endl;
        strength *= 1.5;
        std::cout << "Vampire's strength is now " << getStrength() << "!" << std::endl;
    }
}
