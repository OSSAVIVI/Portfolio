/*********************************************************************
 ** Author: Ryan Wells Farran
 ** Description: Modular inputValidation function...work in progress,
 ** but got the job done for now (I think). Referenced this YouTube video below:
 ** https://www.youtube.com/watch?v=m2P5A4nR51g
 *********************************************************************/
#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP

#include <iostream>

class inputVal //class interface
{
    public://function prototypes
        int getInt(); //verifies input is an integer
        int getPosInt(); //verifies input is a POSITIVE integer
        //double getDouble();
        //char getChar();
};

#endif
