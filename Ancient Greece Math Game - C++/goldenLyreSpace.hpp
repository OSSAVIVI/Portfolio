/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: goldenLyreSpace.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the GoldenLyreSpace Class.
 ***************************************************************************************/

#ifndef GOLDENLYRESPACE_HPP
#define GOLDENLYRESPACE_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include "space.hpp"

class GoldenLyreSpace : public Space
{
protected:
    
    
public:
    GoldenLyreSpace(Space* top = nullptr, Space* right = nullptr, Space* left = nullptr, Space* bottom = nullptr)
    : Space('U', "Pythagoras' Golden Lyre", false, top, right, left, bottom)
    {
        
    }
    
    GoldenLyreSpace& operator=(const GoldenLyreSpace right);
    
    bool invokeLyre(int numberOfRiddlesAnsweredCorrectly);
    
    bool playerCanMoveHere();
    char getMarker();
    std::string getName();
    
    
    //unused function below nneded implementation for pure virtual function so just copying from another class
    bool askQuestion(std::string question, std::string answer, int answerNumber);
};

#endif
