/***************************************************************************************
 ** Program Name: Project 2 | File Name: zoo.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This is where most of the logic of the program takes place, in addition to the
 ** mainProject2.cpp file. There are functions for adding and removing animals, displaying
 ** the populations to the console, calculating and displaying financial statuses of the game, etc.
 ** my logic for adding babies is not correct. I tried making it so when the function ran to test
 ** whether or not there are any adult animals it also added one for each number of babies the animal is
 ** set to have, but the numbers didnt come out right at run time.
 ***************************************************************************************/
#include "zoo.hpp"
#include <iostream>

Zoo::Zoo()
{ //Default Zoo constructor sets starting balance to $100,000
    zooBalance = 100000.00;
    zooProfit = 0.00;
    
    //Will double if capacity is reached
    maxNumOfTigers = 10;
    maxNumOfPenguins = 10;
    maxNumOfTurtles = 10;
    
    //Creates the array at first with size 10
    tigerArray = new Tiger[maxNumOfTigers];
    penguinArray = new Penguin[maxNumOfPenguins];
    turtleArray = new Turtle[maxNumOfTurtles];
    
    //Arrays start off empty
    numOfTigers = 0;
    numOfPenguins = 0;
    numOfTurtles = 0;
}

Zoo::Zoo(double startingBalance)
{ //startingBalance is set by user in mainProject2.cpp
    zooBalance = startingBalance;
    zooProfit = 0.00;
    
    //Will double if capacity is reached
    maxNumOfTigers = 10;
    maxNumOfPenguins = 10;
    maxNumOfTurtles = 10;
    
    //Creates the array at first with size 10
    tigerArray = new Tiger[maxNumOfTigers];
    penguinArray = new Penguin[maxNumOfPenguins];
    turtleArray = new Turtle[maxNumOfTurtles];
    
    //Arrays start off empty
    numOfTigers = 0;
    numOfPenguins = 0;
    numOfTurtles = 0;
}

void Zoo::addTiger(Tiger addedTiger)
{
    if (numOfTigers == maxNumOfTigers) //checks if we are already at maximum capacity
    { //if at maximum capactity, creates a new temporary array that's twice as big
        Tiger* tempBiggerArray = new Tiger[(2 * maxNumOfTigers)]; //creates an array that is twice as big
        for (int index = 0; index < maxNumOfTigers; ++index)
        { //copies Tiger objects into the new temp array
            tempBiggerArray[index] = tigerArray[index];
        }
        delete [] tigerArray; //deallocates and deletes old array
        
        maxNumOfTigers *= 2; //Doubles the maximum capacity
        tigerArray = tempBiggerArray; //sets the new pointer to the temp pointer
        //we don't deallocate the temp pointer because tigerArray is now pointing to it's memory
    }
    tigerArray[numOfTigers] = addedTiger; //adds the Tiger object passed as parameter as the next element in array
    numOfTigers++; //increments the number of tigers the zoo has
    zooBalance -= addedTiger.getCost(); //Cost of addedTiger is subtracted from the balance using the get function
}

void Zoo::addPenguin(Penguin addedPenguin)
{
    if (numOfPenguins == maxNumOfPenguins) //checks if we are already at maximum capacity
    { //if at maximum capactity, creates a new temporary array that's twice as big
        Penguin* tempBiggerArray = new Penguin[(2 * maxNumOfPenguins)]; //creates an array that is twice as big
        for (int index = 0; index < maxNumOfPenguins; ++index)
        { //copies Penguin objects into the new temp array
            tempBiggerArray[index] = penguinArray[index];
        }
        delete [] penguinArray; //deallocates and deletes old array
        
        maxNumOfPenguins *= 2; //Doubles the maximum capacity
        penguinArray = tempBiggerArray; //sets the new pointer to the temp pointer
        //we don't deallocate the temp pointer because penguinArray is now pointing to it's memory
    }
    penguinArray[numOfTigers] = addedPenguin; //adds the Penguin object passed as parameter as the next element in array
    numOfPenguins++; //increments the number of penguins the zoo has
    zooBalance -= addedPenguin.getCost(); //Cost of addedPenguin is subtracted from the balance using the get function
}

void Zoo::addTurtle(Turtle addedTurtle)
{
    if (numOfTurtles == maxNumOfTurtles) //checks if we are already at maximum capacity
    { //if at maximum capactity, creates a new temporary array that's twice as big
        Turtle* tempBiggerArray = new Turtle[(2 * maxNumOfTurtles)]; //creates an array that is twice as big
        for (int index = 0; index < maxNumOfTurtles; ++index)
        { //copies Turtle objects into the new temp array
            tempBiggerArray[index] = turtleArray[index];
        }
        delete [] turtleArray; //deallocates and deletes old array
        
        maxNumOfTurtles *= 2; //Doubles the maximum capacity
        turtleArray = tempBiggerArray; //sets the new pointer to the temp pointer
        //we don't deallocate the temp pointer because penguinArray is now pointing to it's memory
    }
    turtleArray[numOfTigers] = addedTurtle; //adds the Turtle object passed as parameter as the next element in array
    numOfTurtles++; //increments the number of penguins the zoo has
    zooBalance -= addedTurtle.getCost(); //Cost of addedTurtle is subtracted from the balance using the get function
}

bool Zoo::addTigerBabies()
{
    bool adultTigerPresent = false; //variable to be returned by function
    int preBirthNumOfTigers = numOfTigers;
    for (int index = 0; index < preBirthNumOfTigers; ++index)
    {
        if (tigerArray[index].getAge() >= 3)
        {//tests if any of the animals are 3 days or older
            tigerArray[index].setNumberOfBabies(tigerArray[index].getNumberOfBabies() + 1);
            adultTigerPresent = true;
            
            Tiger babyTiger(0, 10000, 1, (10 * 5), (10000 * 0.2));
            addTiger(babyTiger);
            std::cout << "Awe...A baby TIGER was born! <3" << std::endl;
        }
    }
    return adultTigerPresent;
}


bool Zoo::addPenguinBabies()
{
    bool adultPenguinPresent = false; //variable to be returned by function
    int preBirthNumOfPenguins = numOfPenguins;
    for (int index = 0; index < preBirthNumOfPenguins; ++index)
    {//tests if any of the animals are 3 days or older
        if (penguinArray[index].getAge() >= 3)
        {
            penguinArray[index].setNumberOfBabies(penguinArray[index].getNumberOfBabies() + 1);
            adultPenguinPresent = true;
            
            for (int index2 = 0; index2 < penguinArray[index].getNumberOfBabies(); ++index2)
            {
                Penguin babyPenguin(0, 1000, 5, 10, (1000 * 0.1));
                addPenguin(babyPenguin);
                std::cout << "Awe...A baby PENGUIN was born! <3" << std::endl;
            }
        }
    }
    return adultPenguinPresent;
}

bool Zoo::addTurtleBabies()
{
    bool adultTurtlePresent = false; //variable to be returned by function
    int preBirthNumOfTurtles = numOfTurtles;
    for (int index = 0; index < preBirthNumOfTurtles; ++index)
    {//tests if any of the animals are 3 days or older
        if (turtleArray[index].getAge() >= 3)
        {
            turtleArray[index].setNumberOfBabies(turtleArray[index].getNumberOfBabies() + 1);
            adultTurtlePresent = true;
            
            for (int index2 = 0; index2 < turtleArray[index].getNumberOfBabies(); ++index2)
            {
                Turtle babyTurtle(0, 100, 10, (10 * 0.5), (100 * 0.05));
                addTurtle(babyTurtle);
                std::cout << "Awe...A baby TURTLE was born! <3" << std::endl;
            }
        }
    }
    return adultTurtlePresent;
}

//Tests to see if there are any animals available to remove, and if so removes them
bool Zoo::removeTiger()
{
    bool tigerRemoved = false;
    if (numOfTigers == 0)
    {
        tigerRemoved = false;
    }
    else
    {
        std::cout << "A TIGER has been removed from your ZOO!" << std::endl;
        numOfTigers--;
        tigerRemoved = true;
    }
    return tigerRemoved;
}

bool Zoo::removePenguin()
{
    bool penguinRemoved = false;
    if (numOfPenguins == 0)
    {
        penguinRemoved = false;
    }
    else
    {
        std::cout << "A PENGUIN has been removed from your ZOO!" << std::endl;
        numOfPenguins--;
        penguinRemoved = true;
    }
    return penguinRemoved;
}

bool Zoo::removeTurtle()
{
    bool turtleRemoved = false;
    if (numOfTurtles == 0)
    {
        turtleRemoved = false;
    }
    else
    {
        std::cout << "A TURTLE has been removed from your ZOO!" << std::endl;
        numOfTurtles--;
        turtleRemoved = true;
    }
    return turtleRemoved;
}

//Returns animal subclass pointer variables
Tiger* Zoo::getTiger()
{ //returns Tiger pointer
    return tigerArray;
}

Penguin* Zoo::getPenguin()
{ //returns Penguin pointer
    return penguinArray;
}

Turtle* Zoo::getTurtle()
{ //returns Turtle pointer
    return turtleArray;
}

//At end of round animals age increases and a random event occurs
void Zoo::randomEvent()
{
    int randomNumber = ((rand() % 4) + 1); // picks number between one and four
    int randomNumber2;
    int randomTigerBonus;
    bool removeFlag;
    bool babyFlag;
    
    // 1. A sickness occurs to an animal in the zoo
    if (randomNumber == 1)
    {
        std::cout << "One of your animals got sick!" << std::endl;
        removeFlag = false; //Sets the flag to false so we cna trigger it in the following code
        
        randomNumber2 = ((rand() % 3) + 1);
        // 1. Try to remove TIGER first
        if (randomNumber2 == 1)
        {
            removeFlag = removeTiger();
            if (!removeFlag) //if fail try removing a different animal
            {
                removePenguin();
            }
            if (!removeFlag) //if fail try removing a different animal
            {
                removeTurtle();
            }
        }
        
        // 2. Try to remove PENGUIN first
        else if (randomNumber2 == 2)
        {
            removeFlag = removePenguin();
            if (!removeFlag) //if fail try removing a different animal
            {
                removeTiger();
            }
            if (!removeFlag) //if fail try removing a different animal
            {
                removeTurtle();
            }
        }
        // 3. Try to remove TURTLE first
        else if (randomNumber2 == 3)
        {
            removeFlag = removeTurtle();
            if (!removeFlag) //if fail try removing a different animal
            {
                removePenguin();
            }
            if (!removeFlag) //if fail try removing a different animal
            {
                removeTiger();
            }
        }
        
        // 4. This code should never execute
        else
        {
            std::cout << "You should never see this code." << std::endl;
            std::cout << "Check your random number generator in the Zoo Class" << std::endl;
            std::cout << "for randomNumber2." << std::endl;
        }
        
        //This code is called if no animals were available to remove and the remove Flag is still set to false
        if (!removeFlag)
        {
            std::cout << "NO animals were removed from your ZOO!" << std::endl;
        }
    }
    
    // 2. A boom in zoo attendance occurs
    if (randomNumber == 2)
    {
        std::cout << "Attendance is BOOMING today! People love the TIGERS! $$$" << std::endl;
        for (int index = 0; index < numOfTigers; ++index)
        {
            randomTigerBonus = ((rand() % 251) + 250);
            tigerArray[index].setPayoff(tigerArray[index].getPayoff() + randomTigerBonus);
        }
    }
    
    // 3. A baby animal is born
    else if (randomNumber == 3)
    {
        std::cout << "It's a miracle - a baby's been born!" << std::endl;
        babyFlag = false; //Sets the flag to false so we cna trigger it in the following code
        
        randomNumber2 = ((rand() % 3) + 1);
        // 1. determine if TIGER can be born first
        if (randomNumber2 == 1)
        {
            babyFlag = addTigerBabies();
            if (!babyFlag) //if fail try a different animal
            {
                babyFlag = addPenguinBabies();
            }
            if (!babyFlag) //if fail try a different animal
            {
                babyFlag = addTurtleBabies();
            }
        }
        
        // 2. determine if PENGUIN can be born first
        else if (randomNumber2 == 2)
        {
            babyFlag = addPenguinBabies();
            if (!babyFlag) //if fail try a different animal
            {
                babyFlag = addTigerBabies();
            }
            if (!babyFlag) //if fail try a different animal
            {
                babyFlag = addTurtleBabies();
            }
        }
        // 3. determine if TURTLE can be born first
        else if (randomNumber2 == 3)
        {
            babyFlag = addTurtleBabies();
            if (!babyFlag) //if fail try a different animal
            {
                babyFlag = addPenguinBabies();
            }
            if (!babyFlag) //if fail try a different animal
            {
                babyFlag = addTigerBabies();
            }
        }
        
        // 4. This code should never execute
        else
        {
            std::cout << "You should never see this code." << std::endl;
            std::cout << "Check your random number generator in the Zoo Class" << std::endl;
            std::cout << "for randomNumber2 for add baby event." << std::endl;
        }
        
        //This code is called if no animals were available to remove and the remove Flag is still set to false
        if (!babyFlag)
        {
            std::cout << "Oh...wait...false alarm, no baby here...sorry..." << std::endl;
        }
    }
    
    // 4. Nothing happens
    else if (randomNumber == 4)
    {
        std::cout << "On this day, of this month, of this year, nothing happened..." << std::endl;
        std::cout << "(No random event this round)" << std::endl;
    }
    
    // 5. this code should never execute
    else
    {
        //std::cout << "You should never see this code." << std::endl;
        //std::cout << "Check your random number generator in the Zoo Class." << std::endl;
    }
}

void Zoo::increaseAge()
{
    for (int index = 0; index < numOfTigers; ++index)
    {
        tigerArray[index].setAge(tigerArray[index].getAge() + 1);
        zooBalance -= tigerArray[index].getBaseFoodCost();
    }
    
    for (int index = 0; index < numOfPenguins; ++index)
    {
        penguinArray[index].setAge(penguinArray[index].getAge() + 1);
        zooBalance -= penguinArray[index].getBaseFoodCost();
    }
    
    for (int index = 0; index < numOfTurtles; ++index)
    {
        turtleArray[index].setAge(turtleArray[index].getAge() + 1);
        zooBalance -= turtleArray[index].getBaseFoodCost();
    }
    std::cout << "(Your animals are a day older now)" << std::endl;
}

//Function prototypes used for handling financial variables
void Zoo::calculateProfit()
{
    for (int index = 0; index < numOfTigers; ++index)
    {
        zooProfit += tigerArray[index].getPayoff();
    }
    
    for (int index = 0; index < numOfPenguins; ++index)
    {
        zooProfit += penguinArray[index].getPayoff();
    }
    
    for (int index = 0; index < numOfTurtles; ++index)
    {
       zooProfit += turtleArray[index].getPayoff();
    }
    int zooBalancePlusProfit = zooBalance;
    zooBalancePlusProfit += zooProfit;
    std::cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << std::endl;
    std::cout << "You made a profit of $" << zooProfit << std::endl;
    std::cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << std::endl;
    setBalance(zooBalancePlusProfit);
}

void Zoo::setBalance(double inputBalance)
{
    zooBalance = inputBalance;
}

void Zoo::resetProfit()
{
    zooProfit = 0;
}

double Zoo::getBalance()
{
    return zooBalance;
}

double Zoo::getProfit()
{
    return zooProfit;
}

void Zoo::printZoo()
{
    std::cout << "*************************************************" << std::endl;
    std::cout << "You have " << numOfTigers << " TIGERS," << std::endl;
    std::cout << numOfPenguins << " PENGUINS, and " << std::endl;
    std::cout << numOfTurtles << " TURTLES! My goodness!" << std::endl;
    std::cout << "*************************************************" << std::endl;
}
