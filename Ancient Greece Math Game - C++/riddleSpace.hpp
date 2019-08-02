/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: riddleSpace.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the RiddleSpace Class.
 ***************************************************************************************/

#ifndef riddleSpace_hpp
#define riddleSpace_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "space.hpp"
#include "movementSpace.hpp"
#include "inventory.hpp"

class RiddleSpace : public Space
{
protected:
    std::string aestheticLine = "---------------------------------------------------------------";
    
public:
    RiddleSpace(char spaceMarkerIn, std::string riddlerNameIn, Space* top = nullptr, Space* right = nullptr, Space* left = nullptr, Space* bottom = nullptr)
    : Space(spaceMarkerIn, riddlerNameIn, false, top, right, left, bottom)
    {
        
    }
    
    RiddleSpace& operator=(const RiddleSpace right);
    //RiddleSpace(const Space &obj);
    
    bool askQuestion(std::string question, std::string answer, int answerNumber);
    bool invokeLyre(int numberOfRiddlesAnsweredCorrectly);
    
    bool playerCanMoveHere();
    char getMarker();
    std::string getName();
};

#endif
