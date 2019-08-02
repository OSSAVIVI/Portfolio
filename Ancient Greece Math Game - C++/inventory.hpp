/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: inventory.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the Inventory Class.
 ***************************************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <stdio.h>
#include <iostream>

class Inventory
{
private:
    std::string aestheticLine = "---------------------------------------------------------------";
    bool socratesRiddleSolved;
    bool euclidRiddleSolved;
    bool odysseusRiddleSolved;
    int maxInventory;
    int currentInventory;
    
public:
    
    Inventory();
    
    void setSocratesRiddleSolved(bool boolIn);
    void setEuclidRiddleSolved(bool boolIn);
    void setOdysseusRiddleSolved(bool boolIn);
    
    bool getSocratesRiddleSolved();
    bool getEuclidRiddleSolved();
    bool getOdysseusRiddleSolved();
    
    void setMaxInventory(int numberIn);
    int getMaxInventory();
    void setCurrentInventory(int numberIn);
    int getCurrentInventory();
    
    void printInventory();
    
};

#endif
