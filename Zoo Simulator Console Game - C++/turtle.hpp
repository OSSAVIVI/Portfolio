/***************************************************************************************
 ** Program Name: Project 2 | File Name: turtle.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is a sublcass of the Animal Super Class
 ***************************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include <iostream>
#include "animal.hpp"

class Turtle : public Animal
{
public:
    Turtle();
    Turtle(int inputAge, double inputCost, int inputNumberOfBabies, double inputBaseFoodCost, double inputPayoff);
};

#endif
