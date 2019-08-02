/***************************************************************************************
 ** Program Name: Project 2 | File Name: animal.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is the super class for the Tiger, Penguin, and Turtle classes.
 ***************************************************************************************/
#include "animal.hpp"
#include <iostream>

//Constructors
Animal::Animal() //Default constructor
{
    setAge(0);
    setCost(0.0);
    setNumberOfBabies(0);
    setBaseFoodCost(0.0);
    setPayoff(0.0);
}

Animal::Animal(int inputAge, double inputCost, int inputNumberOfBabies, double inputBaseFoodCost, double inputPayoff) //Regular constructor
{ //Sets all of the variables using the setter functions.
    setAge(inputAge);
    setCost(inputCost);
    setNumberOfBabies(inputNumberOfBabies);
    setBaseFoodCost(inputBaseFoodCost);
    setPayoff(inputPayoff);
}

//Getter functions
int Animal::getAge()
{
    return age;
}

double Animal::getCost()
{
    return cost;
}

int Animal::getNumberOfBabies()
{
    return numberOfBabies;
}

double Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

double Animal::getPayoff()
{
    return payoff;
}

//Setter functions
void Animal::setAge(int setAge)
{
    age = setAge;
}
void Animal::setCost(double setCost)
{
    cost = setCost;
}

void Animal::setNumberOfBabies(int setNumberOfBabies)
{
    numberOfBabies = setNumberOfBabies;
}

void Animal::setBaseFoodCost(double setBaseFoodCost)
{
    baseFoodCost = setBaseFoodCost;
}
void Animal::setPayoff(double setPayoff)
{
    payoff = setPayoff;
}
