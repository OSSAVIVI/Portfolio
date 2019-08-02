/*********************************************************************
 ** Author: Ryan Wells Farran
 ** Description: Modular inputValidation function...work in progress,
 ** but got the job done for now (I think). Referenced this YouTube video below:
 ** https://www.youtube.com/watch?v=m2P5A4nR51g
 *********************************************************************/
#include <iostream>
#include "inputVal.hpp"

int inputVal::getInt()
{
    //declare integer value used to store, validate, and return input from user
    int userInput;
    
    //Program instructs user to enter an integer value
    std::cout << "Enter an INTEGER value." << std::endl;
    
    //Takes in user input
    while (!(std::cin >> userInput))
    {
        //Explain to user a noninteger value has been entered
        std::cout << "Error: NON-INTEGER value was entered!" << std::endl;
        std::cout << "       Please enter an INTEGER value!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input
        std::cin.ignore(123, '\n');
    }
    //returns value entered by user after being validated it was of type integer
    return userInput;
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
        //Explain to user a noninteger value has been entered
        std::cout << "Error: incorrect value was entered!" << std::endl;
        std::cout << "Please enter a POSITIVE INTEGER value!" << std::endl;
        //Clear previous input
        std::cin.clear();
        //Discard previous input
        std::cin.ignore(123, '\n');
    }
    //returns value entered by user after being validated it was of type integer
    return userInput;
}
//Code below has not been implemented yet
/*
double inputVal::getDouble()
{
    
}

char inputVal::getChar()
{
    
}
*/

