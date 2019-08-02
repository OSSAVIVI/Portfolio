/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: riddleSpace.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Implementation file for the RiddleSpace Class.
 ***************************************************************************************/

#include "riddleSpace.hpp"
#include "inputVal.hpp"
#include <iostream>
#include <string>

/*
 Basically, the askQuestion function just takes in a string to display a question, a string to display an answer, and a number which is
 either one or two, which represents true or false, and then the function just displas quesion, then uses
 input validation to get one or two from the user and then it compares it to the paramter passed for the argument and displays either
 correct or incorrect coupled with the answer string, then it compares true or false depending on whether or not the user got the T/F
 question right. The SpaceGrid class is kind of like a gaeboard class and will keep track of whether or not the question was answered right
 and if you answer wrong then the health will go to zero and you will lose, but if you answer all three right, then you can interact with
 the end game object (Pythagoras' Golden Lyre!)
 */


RiddleSpace& RiddleSpace::operator=(const RiddleSpace rightOne)
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
RiddleSpace::RiddleSpace(const Space &obj)
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


bool RiddleSpace::askQuestion(std::string question, std::string answer, int answerNumber)
{
    std::cout << aestheticLine << std::endl;
    int questionRight = false;
    std::cout << question << std::endl;
    std::cout << aestheticLine << std::endl;
    std::cout << "Please enter 1 for TRUE or 2 for FALSE!" << std::endl;
    std::cout << aestheticLine << std::endl;
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

bool RiddleSpace::playerCanMoveHere()
{
    return canMoveHere;
}

char RiddleSpace::getMarker()
{
    return spaceMarker;
}

std::string RiddleSpace::getName()
{
    return spaceName;
}



bool RiddleSpace::invokeLyre(int numberOfRiddlesAnsweredCorrectly)
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
