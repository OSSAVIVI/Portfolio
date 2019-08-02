/***************************************************************************************
 ** Program Name: Project 2 | File Name: zoo.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is the interface/header file for the zoo.cpp Zoo class. The logic is explained
 ** in the accompanying .cpp file, but basically there are functions to add and remove animals,
 ** display game stats to the consile, and more.
 ***************************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo
{
    private:
        //Finanial variables
        double zooBalance;
        double zooProfit;
    
        //Pointer variables point to animal sublcass objects in arrays of their respective types
        Tiger *tigerArray;
        Penguin *penguinArray;
        Turtle *turtleArray;
    
        //Variables used to store the current max size of each animal subclass array, which doubles when max size is reached
        int maxNumOfTigers;
        int maxNumOfPenguins;
        int maxNumOfTurtles;
    
        //variables used to store current number of animal subclasses, and when number reaches maxNum, then maxNum variables double
        int numOfTigers;
        int numOfPenguins;
        int numOfTurtles;
    
    public:
        //Constructor prototypes
        Zoo(); //Default constructor prototype
        Zoo(double startingBalance); //Regular constructor prototype takes starting balance from user
    
        //Add animal subclasses to their respective arrays
        void addTiger(Tiger addedTiger);
        void addPenguin(Penguin addedPenguin);
        void addTurtle(Turtle addedTurtle);
    
        //Functions use for loop on array and return boolean value true if an adult (3 or older) animal is detected
        bool addTigerBabies();
        bool addPenguinBabies();
        bool addTurtleBabies();
    
        //Tests to see if there are any animals available to remove, and if so removes them
        bool removeTiger();
        bool removePenguin();
        bool removeTurtle();
    
        //Returns animal subclass pointer variables
        Tiger* getTiger();
        Penguin* getPenguin();
        Turtle* getTurtle();
    
        //At end of round animals age increases and a random event occurs
        void randomEvent();
        void increaseAge();
    
        //Function prototypes used for handling financial variables
        void calculateProfit();
        void setBalance(double inputBalance);
        void resetProfit();
        double getBalance();
        double getProfit();
    
        //prints all of the animals in the zoo
        void printZoo();
};

#endif
