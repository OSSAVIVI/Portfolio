/*********************************************************************
** Program Name: Project 2 | File Name: inputVal.hpp file
** Author: Ryan Wells Farran
** Class: CS 162 400 S2019 (Intro to CS II)
** Sources: https://www.youtube.com/watch?v=m2P5A4nR51g
** Description: have not added double validation yet, but have functions for validating integers,
** positive integers, and yes or no boolean questions.
*********************************************************************/
#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <iostream>

class inputVal //class interface
{
public://function prototypes
    int getInt(); //verifies input is an integer
    int getPosInt(); //verifies input is a POSITIVE integer
    int getYesOrNo();
    int getOneOrTwo();
    //double getDouble(); //Has not been implemented yet
    //char getChar();     //Has not been implemented yet
};

#endif
