/***************************************************************************************
 ** Program Name: Project 2 | File Name: animal.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is the header file for the animal.cpp file.
 ***************************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal
{
    private:
        int age; //Private variable for storing age of animal
        double cost; //Private variable for storing cost of animal
        int numberOfBabies; //Private variable for storing number of babies each animal has at once
        double baseFoodCost; //Private variable for storing base food cost, which will be set by user in mainProject2.cpp
        double payoff; //Private variable for storing payoff of animal, which is a percentage of cost
    public:
        //Constructor prototypes
        Animal(); //Default constructor prototype
        Animal(int inputAge, double inputCost, int inputNumberOfBabies, double inputBaseFoodCost, double inputPayoff); //Regular constructor prototype
        //Getter function prototypes
        int getAge(); //Prototype for function that returns age
        double getCost(); //Prototype for function that returns cost
        int getNumberOfBabies(); //Prototype for function that returns numberOfBabies
        double getBaseFoodCost(); //Prototype for function that returns baseFoodCost
        double getPayoff(); //Prototype for function that returns payoff
        //Setter function prototypes
        void setAge(int setAge); //Prototype for function that sets age
        void setCost(double setCost); //Prototype for function that sets cost
        void setNumberOfBabies(int setNumberOfBabies); //Prototype for function that sets numberOfBabies
        void setBaseFoodCost(double setBaseFoodCost); //Prototype for function that sets baseFoodCost
        void setPayoff(double setPayoff); //Prototype for function that sets payoff
};

#endif
