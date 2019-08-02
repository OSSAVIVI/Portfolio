/***************************************************************************************
 ** Program Name: Project 2 | File Name: tiger.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is a sublcass of the Animal Super Class
 ***************************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include <iostream>
#include "animal.hpp"

class Tiger : public Animal
{
    public:
        Tiger();
        Tiger(int inputAge, double inputCost, int inputNumberOfBabies, double inputBaseFoodCost, double inputPayoff);
};

#endif
