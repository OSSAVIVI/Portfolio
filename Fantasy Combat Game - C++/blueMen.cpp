/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: blueMen.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the BlueMen child class.
 ** Characterstics: They are small, 6 inch tall, but fast and tough. They are hard to
 ** hit so they can take some damage. They can also do a LOT of damage when they crawl
 ** inside enemies’ armor or clothing.
 ** Special Abilities: Mob: Blue Men are actually a swarm of small individuals. For
 ** every 4 points of damage, they lose one defense die. For example, if they have a
 ** strength of 8, they would have 2d6 for defense.
 ***************************************************************************************/
#include "blueMen.hpp"
#include "character.hpp"

BlueMen::BlueMen() : Character("Blue Men", 2, 10, 3, 6, 3, 12)
{
    //no other variables
}

int BlueMen::attack()
{
    std::cout << "The Blue Men are attacking!" << std::endl;
    int attackDamage = attackRollDice(); //displays rolling dice info
    std::cout << "The Blue Men dealt " << attackDamage << " attack points!" << std::endl;
    return attackDamage;
}

void BlueMen::defend(int attack)
{
    if (strength <= 8 && strength > 4)
    {
        std::cout << "☆☆☆ The Blue Men's strength and defense have fallen. ☆☆☆" << std::endl;
        numOfDefenseDice = 2;
    }
    else if (strength <= 4)
    {
        std::cout << "☆☆☆ The Blue Men's strength and defense have greatly fallen! ☆☆☆" << std::endl;
        numOfDefenseDice = 1;
    }
    else
    {
        //do nothing
    }
    int defensePoints = defendRollDice(); //displays rolling dice info
    int inflictedDamage;
    
    if (attack != 666) //test to see if medusa used Glare
    {
        std::cout << "      The Blue Men are defending!" << std::endl;
        std::cout << "      Pre-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        std::cout << "      The Blue Men mustered " << defensePoints << " defense points!" << std::endl;
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
        std::cout << "      The Blue Men defended the attack completely!" << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage > 0 && inflictedDamage <= armor)
    {
        armor -= inflictedDamage;
        std::cout << "Total Inflicted Damage: " << inflictedDamage << std::endl;
        std::cout << "      The Blue Men's armor blocked the attack, but is now ruined." << std::endl;
        std::cout << "      Post-Defend Stats:" << std::endl;
        std::cout << "      Armor: " << armor << std::endl;
        std::cout << "      Strength: " << strength << " (health points)" << std::endl;
    }
    else if (inflictedDamage == 666) //Medusa Glare will be trumped by charm
    {
        std::cout << "Total Inflicted Damage: ∞ (infiniti)" << std::endl;
        std::cout << "      ☆☆☆ The Blue Men look into Medusa's eyes ☆☆☆" << std::endl;
        std::cout << "      ☆☆☆ and are magically turned into stone! ☆☆☆" << std::endl;
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
            std::cout << "      The Blue Men survived the attack..." << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
        }
        else if (strength <=0)
        {
            std::cout << "      The Blue Men didn't survive the attack :(" << std::endl;
            std::cout << "      Post-Defend Stats:" << std::endl;
            std::cout << "      Armor: " << armor << std::endl;
            std::cout << "      Strength: " << strength << " (health points)" << std::endl;
            isDeadFlag = true;
            isAliveFlag = false;
        }
    }
    else
    {
        std::cout << "This code shoudl never run, check BlueMen.cpp infilctedDamage and armor variables" << std::endl;
    }
}

bool BlueMen::isDead()
{
    return isDeadFlag;
}

/*
 numOfAttackDice = numOfAD;
 numOfAttackDiceSides = numOfADS;
 numOfDefenseDice = numOfDD;
 numOfDefenseDiceSides = numOfDDS;
 
 */

int BlueMen::attackRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfAttackDice; index++)
    {
        int roll = rand() % numOfAttackDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

int BlueMen::defendRollDice()
{
    int sumOfRolls = 0;
    for (int index = 0; index < numOfDefenseDice; index++)
    {
        int roll = rand() % numOfDefenseDiceSides + 1;
        sumOfRolls += roll;
    }
    return sumOfRolls;
}

std::string BlueMen::getName()
{
    return name;
}

int BlueMen::getArmor()
{
    return armor;
}

int BlueMen::getStrength()
{
    return strength;
}

void BlueMen::recovery()
{
    if (strength < 12) //if damage was taken, then health is multiplied by 1.5
    {
        std::cout << "Blue Men are recovering..." << std::endl;
        strength *= 1.5;
        std::cout << "Blue Men's strength is now " << getStrength() << "!" << std::endl;
    }
}
