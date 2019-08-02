/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: movementSpace.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the MovementSpace Class.
 ***************************************************************************************/

#ifndef MOVEMENTSPACE_HPP
#define MOVEMENTSPACE_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include "space.hpp"
#include "riddleSpace.hpp"

class MovementSpace : public Space
{
public:
    Space* riddler = nullptr;
    Space* lyre = nullptr;
    
public:
    MovementSpace(Space* top = nullptr, Space* right = nullptr, Space* left = nullptr, Space* bottom = nullptr)
    : Space(' ', "Movement Space", true, top, right, left, bottom)
    {

    }
    

    MovementSpace& operator=(const MovementSpace right);
    //MovementSpace(const Space &obj);
    
    
    bool playerCanMoveHere();
    void setCanMoveHere(bool userIn);
    char getMarker();
    void setMarker(char markerIn);
    std::string getName();
    void setName(std::string nameIn);
    void setRiddler(Space* riddlerIn);
    Space* getRiddler();
    void setLyre(Space* lyreIn);
    Space* getLyre();
    
    //unused functions needed for pure virtual function
    bool askQuestion(std::string question, std::string answer, int answerNumber);
    bool invokeLyre(int numberOfRiddlesAnsweredCorrectly);
};

#endif
