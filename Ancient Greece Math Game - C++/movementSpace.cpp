/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: movementSpace.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Implementation file for the MovementSpace Class.
 ***************************************************************************************/

#include "movementSpace.hpp"
#include "inputVal.hpp"

MovementSpace& MovementSpace::operator=(const MovementSpace rightOne)
{
    spaceMarker = rightOne.spaceMarker;
    spaceName = rightOne.spaceName;
    canMoveHere = rightOne.canMoveHere;
    top = rightOne.top;
    right = rightOne.right;
    left = rightOne.left;
    bottom = rightOne.bottom;
    
    return *this;
}

/*
MovementSpace::MovementSpace(const Space &obj)
{
    spaceMarker = obj.spaceMarker;
    spaceName = obj.spaceName;
    canMoveHere = obj.canMoveHere;
    top = obj.top;
    right = obj.right;
    left = obj.left;
    bottom = obj.bottom;
}
 */

bool MovementSpace::playerCanMoveHere()
{
    return canMoveHere;
}

void MovementSpace::setCanMoveHere(bool userIn)
{
    canMoveHere = userIn;
}

char MovementSpace::getMarker()
{
    return spaceMarker;
}

void MovementSpace::setMarker(char markerIn)
{
    spaceMarker = markerIn;
}

std::string MovementSpace::getName()
{
    return spaceName;
}
void MovementSpace::setName(std::string nameIn)
{
    spaceName = nameIn;
}

void MovementSpace::setRiddler(Space* riddlerIn)
{
    riddler = riddlerIn;
}

 Space* MovementSpace::getRiddler()
{
    return riddler;
}

void MovementSpace::setLyre(Space* lyreIn)
{
    lyre = lyreIn;
}

Space* MovementSpace::getLyre()
{
    return lyre;
}

bool MovementSpace::askQuestion(std::string question, std::string answer, int answerNumber)
{
    int questionRight = false;
    std::cout << question << std::endl;
    std::cout << "Please enter 1 for TRUE or 2 for FALSE" << std::endl;
    InputVal inputValidation;
    int userChoice = inputValidation.getOneOrTwo();
    
    if (userChoice == answerNumber)
    {
        std::cout << "CORRECT!: " << std::endl << answer << std::endl;
        questionRight = true;
    }
    else
    {
        std::cout << "INCORRECT!: " << std::endl << answer << std::endl;
    }
    
    return questionRight;
}

bool MovementSpace::invokeLyre(int numberOfRiddlesAnsweredCorrectly)
{
    bool gameWon = false;
    if (numberOfRiddlesAnsweredCorrectly == 2)
    {
        gameWon = true;
        std::cout << "Congratulations!!!" << std::endl;
        std::cout << "You answered all three riddles" << std::endl;
        std::cout << "correctly and didn't run out of steps!" << std::endl;
        std::cout << "Feel free to play with Pythagoras'" << std::endl;
        std::cout << "Golden Lyre for as long as you'd like!" << std::endl;
    }
    else
    {
        std::cout << "Hey!!! Stop!!!" << std::endl;
        std::cout << "Don't touch that!" << std::endl;
        std::cout << "Only wise homies of Pythagoras may" << std::endl;
        std::cout << "jammeth on his most epic Golden Lyre..." << std::endl;
    }
    
    return gameWon;
}
