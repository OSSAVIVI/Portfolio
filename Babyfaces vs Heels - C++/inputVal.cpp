/***************************************************************************************
 ** File Name: inputVal.cpp
 ** Description: This is the implementation file of the InputVal class.
 ***************************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include "inputVal.hpp"
#include <cmath>

int InputVal::getInt()
{
    //declare integer variable used to store, validate, and return input from user
    int userInput;
    
    //Program instructs user to enter an integer value
    std::cout << "[inputVal] - Enter an INTEGER value." << std::endl;
    
    //Takes in user input
    while (!(std::cin >> userInput))
    { //Loop continues until the desired INTEGER value is entered
        userInput = ceil(userInput);
        //Explain to user a noninteger value has been entered
        std::cout << "Error: NON-INTEGER value was entered!" << std::endl;
        std::cout << "            Value MUST be an INTEGER!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input (learned this from a YouTube video sourced at top of file under description)
        std::cin.ignore(123, '\n');
    }
    //returns value entered by user after being validated it was of type integer
    std::cout << "[inputVal] - You choose option " << userInput << std::endl;
    return (userInput);
}

int InputVal::getPosInt()
{
    //declare integer variable used to store, validate, and return input from user
    int userInput;
    
    //Program instructs user to enter an integer value
    //std::cout << "[inputVal] - Enter a POSITIVE INTEGER value." << std::endl;
    
    //Takes in user input
    while (!(std::cin >> userInput) || userInput < 0)
    { //Loop continues until the desired POSITIVE INTEGER value is entered
        userInput = ceil(userInput);
        //Explain to user a noninteger value has been entered
        std::cout << "Error: NON-INTEGER or NEGATIVE value was entered!" << std::endl;
        std::cout << "                Value MUST be a POSITIVE INTEGER!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input (learned this from a YouTube video sourced at top of file under description)
        std::cin.ignore(123, '\n');
    }
    //returns value entered by user after being validated it was of type integer
    //std::cout << "[inputVal] - You chose option " << userInput << std::endl;
    return (userInput);
}

int InputVal::getOneOrTwo()
{
    int userInput;
    //std::cout << "[inputVal] - Enter '1' or '2' (nothing else)." << std::endl;
    userInput = getPosInt(); //Used to first validate it is a positive integer
    //std::cin >> userInput;
    while (userInput != 1 && userInput != 2) //Used to secondly validate it is not a number other than 1 or 2
    {
        userInput = ceil(userInput);
        std::cout << "Error: INVALID integer was entered!" << std::endl;
        std::cout << "   Value MUST be either '1' or '2'!" << std::endl;
        userInput = getPosInt(); //Called again number is greater than 2 (not 1 or 2)
    }
    return userInput;
}

int InputVal::getYesOrNo()
{
    //declare string variable used to store, validate, and return input from user
    std::string userInput;
    char newString;
    
    std::cout << "[inputVal] - Enter 'Y' for YES or 'N' for NO." << std::endl;
    
    std::cin >> userInput;
    newString = userInput.c_str()[0];
    while (userInput[0] != 'y' && userInput[0] != 'Y' &&
           userInput[0] != 'n' && userInput[0] != 'N') //Function only tests the value at the zeroth subscript
    { //Loop continues until the desired CHAR value is entered (y, Y, n, or N)
        //Explain to user the wrong input was entered
        std::cout << "Error: INVALID character was entered!" << std::endl;
        std::cout << " Value MUST be 'y', 'Y', 'n', or 'N'!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input (learned this from a YouTube video sourced at top of file under description)
        std::cin.ignore(123, '\n');
        std::cin >> userInput;
    }
    //returns value entered by user after being validated it was of type integer
    std::cout << "[inputVal] - You choose option " << userInput << std::endl;
    return (userInput[0]);
}
