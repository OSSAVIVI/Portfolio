/***************************************************************************************
 ** Program Name: Project 2 | File Name: tiger.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is a sublcass of the Animal Super Class
 ***************************************************************************************/

#include "tiger.hpp"

Tiger::Tiger() : Animal()
{
    //Calls the super class defaul constructor
}

Tiger::Tiger(int inputAge, double inputCost, int inputNumberOfBabies, double inputBaseFoodCost, double inputPayoff) : Animal(inputAge, inputCost, inputNumberOfBabies, inputBaseFoodCost, inputPayoff)
{
    //Calls the super class regular constructor using the same parameters passed into the subclass
}
