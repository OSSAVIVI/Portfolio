/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: space.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the Space Class.
 ***************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <stdio.h>
#include <iostream>
#include <string>

class Space
{
public:
    char spaceMarker; //will be the unique identifier for each derived class when printed
    std::string spaceName;
    bool canMoveHere;
    Space* top;
    Space* right;
    Space* left;
    Space* bottom;
    
    //Constructor prototype below
    Space(char spaceMarker, std::string spaceName, bool canMoveHere = false,
          Space* top = nullptr, Space* right = nullptr,
          Space* left = nullptr, Space* bottom = nullptr)
    {
        this->spaceMarker = spaceMarker;
        this->spaceName = spaceName;
        this->canMoveHere = canMoveHere;
        this->top = top;
        this->right = right;
        this->left = left;
        this->bottom = bottom;
    }
    
    
    virtual bool askQuestion(std::string question, std::string answer, int answerNumber) = 0;
    virtual bool invokeLyre(int numberOfRiddlesAnsweredCorrectly) = 0;
    virtual char getMarker() = 0;
    virtual std::string getName() = 0;
    virtual bool playerCanMoveHere() = 0;
};

#endif
