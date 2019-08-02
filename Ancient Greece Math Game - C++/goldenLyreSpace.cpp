/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: goldenLyreSpace.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Implementation file for the GoldenLyreSpace Class.
 ***************************************************************************************/

#include "goldenLyreSpace.hpp"
#include "inputVal.hpp"

bool GoldenLyreSpace::invokeLyre(int numberOfRiddlesAnsweredCorrectly)
{
    bool gameWon = false;
    if (numberOfRiddlesAnsweredCorrectly == 2)
    {
        gameWon = true;
        std::cout << "Congratulations!!!" << std::endl;
        std::cout << "You answered ONLY TWO riddles" << std::endl;
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

GoldenLyreSpace& GoldenLyreSpace::operator=(const GoldenLyreSpace rightOne)
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


bool GoldenLyreSpace::playerCanMoveHere()
{
    return canMoveHere;
}

char GoldenLyreSpace::getMarker()
{
    return spaceMarker;
}

std::string GoldenLyreSpace::getName()
{
    return spaceName;
}

bool GoldenLyreSpace::askQuestion(std::string question, std::string answer, int answerNumber)
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
