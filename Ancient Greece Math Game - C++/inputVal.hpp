/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: inputVal.hpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Header file for the InputVal Class.
 ***************************************************************************************/
#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <stdio.h>
#include <iostream>
#include <string>

class InputVal //class interface
{
public://function prototypes
    int getInt(); //verifies input is an integer
    int getPosInt(); //verifies input is a POSITIVE integer
    int getOneOrTwo(); //verifes input is ONLY 1 or 2
    int getYesOrNo(); //verifies input is either y, Y, n, or N for boolean questions
    
    //double getDouble(); //Has not been implemented yet
    //char getChar();     //Has not been implemented yet
};

#endif
