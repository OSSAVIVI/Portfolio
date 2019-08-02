/*********************************************************************
** Program Name: Project 2 | File Name: inputVal.cpp file
** Author: Ryan Wells Farran
** Class: CS 162 400 S2019 (Intro to CS II)
** Description: ...
** Sources: https://www.youtube.com/watch?v=m2P5A4nR51g
** Description: have not added double validation yet, but have functions for validating integers,
** positive integers, and yes or no boolean questions.
*********************************************************************/
#include <iostream>
#include <string>
#include "inputVal.hpp"
#include <cmath>

int inputVal::getInt()
{
    //declare integer value used to store, validate, and return input from user
    int userInput;
    
    //Program instructs user to enter an integer value
    std::cout << "Enter an INTEGER value." << std::endl;
    
    //Takes in user input
    while (!(std::cin >> userInput))
    {
        userInput = ceil(userInput);
        //Explain to user a noninteger value has been entered
        std::cout << "Error: NON-INTEGER value was entered!" << std::endl;
        std::cout << "       Please enter an INTEGER value!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input
        std::cin.ignore(123, '\n');
    }
    //returns value entered by user after being validated it was of type integer
    return (userInput);
}

int inputVal::getPosInt()
{
    //declare integer value used to store, validate, and return input from user
    int userInput;
    
    //Program instructs user to enter an integer value
    std::cout << "Enter a POSITIVE INTEGER value." << std::endl;
    
    //Takes in user input
    while (!(std::cin >> userInput) || userInput < 0)
    {
        userInput = ceil(userInput);
        //Explain to user a noninteger value has been entered
        std::cout << "Error: incorrect value was entered!" << std::endl;
        std::cout << "Please enter a POSITIVE INTEGER value!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input
        std::cin.ignore(123, '\n');
    }
    //returns value entered by user after being validated it was of type integer
    return (userInput);
}

int inputVal::getYesOrNo()
{
    
    std::string userInput;
    char newString;
    
    std::cout << "Enter 'Y' for YES or 'N' for NO." << std::endl;
    
    std::cin >> userInput;
    newString = userInput.c_str()[0];
    while (userInput[0] != 'y' && userInput[0] != 'Y' &&
           userInput[0] != 'n' && userInput[0] != 'N')
    {
        //Explain to user the wrong input was entered
        std::cout << "Error: incorrect option was selected!" << std::endl;
        std::cout << "Please enter 'Y' for YES or 'N' for NO!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input
        std::cin.ignore(123, '\n');
        std::cin >> userInput;
    }
    //returns value entered by user after being validated it was of type integer
    return (userInput[0]);
}

int inputVal::getOneOrTwo()
{
    int userInput;
    std::cout << "Enter '1' or '2', nothing else." << std::endl;
    userInput = getPosInt();
    while (userInput != 1 && userInput != 2)
    {
        std::cout << "Enter '1' or '2', nothing else." << std::endl;
        userInput = getPosInt();
    }
    return userInput;
}
