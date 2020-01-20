/***************************************************************************************
 ** File Name: inputVal.hpp
 ** Description: This is the header file of the InputVal class.
 ***************************************************************************************/
#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <stdio.h>
#include <iostream>

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
