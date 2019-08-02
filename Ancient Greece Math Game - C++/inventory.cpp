/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: inventory.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Implementation file for the Inventory Class.
 ***************************************************************************************/

#include "inventory.hpp"

Inventory::Inventory()
{
    socratesRiddleSolved = false;
    euclidRiddleSolved = false;
    odysseusRiddleSolved = false;
    
    maxInventory = 2;
    currentInventory = 0;
}

void Inventory::setSocratesRiddleSolved(bool boolIn)
{
    socratesRiddleSolved = boolIn;
}

void Inventory::setEuclidRiddleSolved(bool boolIn)
{
    euclidRiddleSolved = boolIn;
}

void Inventory::setOdysseusRiddleSolved(bool boolIn)
{
    odysseusRiddleSolved = boolIn;
}

bool Inventory::getSocratesRiddleSolved()
{
    return socratesRiddleSolved;
}

bool Inventory::getEuclidRiddleSolved()
{
    return euclidRiddleSolved;
}

bool Inventory::getOdysseusRiddleSolved()
{
    return odysseusRiddleSolved;
}

void Inventory::setMaxInventory(int numberIn)
{
    maxInventory = numberIn;
}

int Inventory::getMaxInventory()
{
    return maxInventory;
}

void Inventory::setCurrentInventory(int numberIn)
{
    currentInventory = numberIn;
}

int Inventory::getCurrentInventory()
{
    return currentInventory;
}

void Inventory::printInventory()
{
    std::cout << "INVENTORY:" << std::endl;
    std::cout << "(" << getCurrentInventory() << "/2 inventory slots available)" << std::endl;
    if (getSocratesRiddleSolved())
    {
        std::cout << "Handwritten Note with Socrates' Blessing" << std::endl;
    }
    else
    {
        std::cout << "No Note from Socrates" << std::endl;
    }
    if (getEuclidRiddleSolved())
    {
        std::cout << "Handwritten Note with Euclid's Blessing" << std::endl;
    }
    else
    {
        std::cout << "No Note from Euclid" << std::endl;
    }
    if (getOdysseusRiddleSolved())
    {
        std::cout << "Handwritten Note with Odysseus' Blessing" << std::endl;
    }
    else
    {
        std::cout << "No Note from Odysseus" << std::endl;
    }
    std::cout << aestheticLine << std::endl;
    std::cout << std::endl;
}
