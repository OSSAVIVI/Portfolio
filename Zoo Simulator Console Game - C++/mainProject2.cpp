/***************************************************************************************
 ** Program Name: Project 2 | File Name: mainProject2.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II)
 ** Date: 04/28/2019 | Sunday, April 28th 2019
 ** Description: This game simulates a zoo with Tigers, Penguins, and Turtles. Basically,
 ** you can think of the tigers as the top tier animal, the penguins as middle tier, and
 ** turtles as lower tier animals. Each animal costs money each round, but also makes money each round.
 ** random events keep the game interesting by animals either dying, reproducing, and more.
 ** Each of the accompanying files explain more of what is going on.
 ***************************************************************************************/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "menu.hpp"
#include "inputVal.hpp"
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string aestheticLine = "*************************************************"; //used in console output to visually break up text
    srand(time(0));
    const double BASE_COST_OF_FOOD = 10;
    const double COST_OF_TIGER = 10000.00;
    const double COST_OF_PENGUIN = 1000.00;
    const double COST_OF_TURTLE = 100.00;
    double userStartBalance; //User selects this number to set beginning game balance
    inputVal dummyInputVal;
    int userInput;
    int dayNumber = 0;
    bool gameInSession;
    char userYesOrNo;
    
    //Code used with the Menu class object below
    int userChoice; //Stores whatever option user chooses from Menu class
    bool restart = true; //Used for first menu PLAY/EXIT prompt
    bool restart2 = true; //Used for second program PLAY AGAIN/EXIT prompt
    
    Zoo runGame; //Create object, which calls constructor( warGame() )
    
    Menu menu = Menu("the Zoo Tycoon Game (Project 2)"); //calls constructor with the name of the game as a parameter
    while (restart == true)
    {
        userChoice = menu.startMenu(); //Begins Start/Quit prompt
        if (userChoice == 1)
        {
            cout << aestheticLine << endl;
            //run program...(user chose '1')
            cout << "Alright! Let's Play! :-)" << endl;
            cout << "How much money will your Zoo start with?" << endl;
            cout << "(must be between $10,000 and $100,000)" << endl;
            userStartBalance = dummyInputVal.getPosInt(); //User selects starting amount to be passed into the Zoo constructor
            while (userStartBalance > 100000 || userStartBalance < 10000)
            {
                cout << "(must be between $10,000 and $100,000)" << endl;
                userStartBalance = dummyInputVal.getPosInt();
            }
            
            Zoo zooGame(userStartBalance);
            
            cout << std::fixed << std::setprecision(2); //used for formatting console decimal output for displaying zooGame.getBalance()
            cout << "Okay, your Zoo will start with a balnce of $" << zooGame.getBalance() << endl;

            //This code adds your first tigers....
            cout << aestheticLine << endl;
            cout << "How many TIGERS will you start with?" << endl;
            userInput = dummyInputVal.getOneOrTwo();
            if (userInput == 1)
            {
                Tiger firstTiger(1, COST_OF_TIGER, 1, (BASE_COST_OF_FOOD * 5), (COST_OF_TIGER * 0.2));
                zooGame.addTiger(firstTiger);
            }
            else if (userInput == 2)
            {
                Tiger firstTiger(1, COST_OF_TIGER, 1, (BASE_COST_OF_FOOD * 5), (COST_OF_TIGER * 0.2));
                zooGame.addTiger(firstTiger);
                Tiger secondTiger(1, COST_OF_TIGER, 1, (BASE_COST_OF_FOOD * 5), (COST_OF_TIGER * 0.2));
                zooGame.addTiger(secondTiger);
            }
            else //This code should never execute
            {
                cout << "Looks like there's problems with adding your first tigers..." << endl;
            }
            //End adding tigers...
            //This code adds your first penguins....
            cout << aestheticLine << endl;
            cout << "How many PENGUINS will you start with?" << endl;
            userInput = dummyInputVal.getOneOrTwo();
            if (userInput == 1)
            {
                Penguin firstPenguin(1, COST_OF_PENGUIN, 5, BASE_COST_OF_FOOD, (COST_OF_PENGUIN * 0.1));
                zooGame.addPenguin(firstPenguin);
            }
            else if (userInput == 2)
            {
                Penguin firstPenguin(1, COST_OF_PENGUIN, 5, BASE_COST_OF_FOOD, (COST_OF_PENGUIN * 0.1));
                zooGame.addPenguin(firstPenguin);
                Penguin secondPenguin(1, COST_OF_PENGUIN, 5, BASE_COST_OF_FOOD, (COST_OF_PENGUIN * 0.1));
                zooGame.addPenguin(secondPenguin);
            }
            else //This code should never execute
            {
                cout << "Looks like there's problems with adding your first penguins..." << endl;
            }
            //End adding penguins...
            //This code adds your first turtles....
            cout << aestheticLine << endl;
            cout << "How many TURTLES will you start with?" << endl;
            userInput = dummyInputVal.getOneOrTwo();
            if (userInput == 1)
            {
                Turtle firstTurtle(1, COST_OF_TURTLE, 10, (BASE_COST_OF_FOOD * 0.5), (COST_OF_TURTLE * 0.05));
                zooGame.addTurtle(firstTurtle);
            }
            else if (userInput == 2)
            {
                Turtle firstTurtle(1, COST_OF_TURTLE, 10, (BASE_COST_OF_FOOD * 0.5), (COST_OF_TURTLE * 0.05));
                zooGame.addTurtle(firstTurtle);
                Turtle secondTurtle(1, COST_OF_TURTLE, 10, (BASE_COST_OF_FOOD * 0.5), (COST_OF_TURTLE * 0.05));
                zooGame.addTurtle(secondTurtle);
            }
            else //This code should never execute
            {
                cout << "Looks like there's problems with adding your first turtles..." << endl;
            }
            //End adding turtles...
            gameInSession = true;
            //Run program now that initial starting data has been set...
            while (gameInSession)
            {
                cout << "It is day " << ++dayNumber << " at the Zoo" << endl;
                cout << "and you have a balance of $" << zooGame.getBalance() << endl;
                
                //Incrememnt age of animals at the start of each day
                zooGame.increaseAge();
                
                //Generate a random event using the randomEvent() function
                zooGame.randomEvent();
                
                //Adds the profit from each animal to the balance, & takes into account tigers if a bonus was triggered by randomEvent()
                zooGame.calculateProfit();
                
                //Resets profit variable so it can correctly claculate balcance at end of each round
                zooGame.resetProfit();
                
                //Prints current status of zoo
                zooGame.printZoo();
                
                cout << "Would you like to purchase another animal?" << endl;
                userYesOrNo = dummyInputVal.getYesOrNo();
                
                if (userYesOrNo == 'y' || userYesOrNo == 'Y')
                {
                    cout << "What type of animal would you like to purchase?" << endl;
                    cout << "Enter '1' to purchase a TIGER!" << endl;
                    cout << "Enter '2' to purchase a PENGUIN!" << endl;
                    cout << "Enter '3' to purchase a TURTLE!" << endl;
                    
                    userInput = dummyInputVal.getPosInt();
                    while (userInput < 1 || userInput > 3)
                    {
                        userInput = dummyInputVal.getPosInt();
                    }
                    if (userInput == 1)
                    {
                        Tiger anotherTiger(1, COST_OF_TIGER, 1, (BASE_COST_OF_FOOD * 5), (COST_OF_TIGER * 0.2));
                        zooGame.addTiger(anotherTiger);
                    }
                    else if (userInput == 2)
                    {
                        Penguin anotherPenguin(1, COST_OF_PENGUIN, 5, BASE_COST_OF_FOOD, (COST_OF_PENGUIN * 0.1));
                        zooGame.addPenguin(anotherPenguin);
                    }
                    else if (userInput == 3)
                    {
                        Turtle anotherTurtle(1, COST_OF_TURTLE, 10, (BASE_COST_OF_FOOD * 0.5), (COST_OF_TURTLE * 0.05));
                        zooGame.addTurtle(anotherTurtle);
                    }
                    else
                    {
                        cout << "This should never be executed...check the adding animal part of main..." << endl;
                    }
                    
                }
                else if (userYesOrNo == 'n' || userYesOrNo == 'N')
                {
                    cout << "No worries, you don't have to purchase an animal." << endl;
                }
                else
                { //this code should never be displayed
                    std::cout << "This code should never be displayed because inputVal.getYesOrNo() should prevent so" << std::endl;
                }
                
                cout << aestheticLine << endl;
                cout << "Would you like to keep playing?" << endl;
                userYesOrNo = dummyInputVal.getYesOrNo();
                if (userYesOrNo == 'y' || userYesOrNo == 'Y')
                {
                    cout << aestheticLine << endl;
                    cout << "..." << endl;
                    cout << "..." << endl;
                    cout << "Okay we'll start the next day..." << endl;
                    cout << "..." << endl;
                    cout << "..." << endl;
                    cout << aestheticLine << endl;
                }
                else if (userYesOrNo == 'n' || userYesOrNo == 'N')
                {
                    gameInSession = false;
                    cout << "Okay, on day " << dayNumber << " your" << endl;
                    cout << "balance was $" << zooGame.getBalance() << endl;
                    cout << "Thanks for playing!" << endl;
                }
                else
                {
                    std::cout << "This code should never be displayed because inputVal.getYesOrNo() should prevent so" << std::endl;
                }
                if (zooGame.getBalance() < 0)
                {
                    gameInSession = false;
                    cout << "Oh...look's like you're broke!" << endl;
                    cout << aestheticLine << endl;
                    cout << "************GAME OVER!************" << endl;
                    cout << aestheticLine << endl;
                    cout << "************GAME OVER!************" << endl;
                    cout << aestheticLine << endl;
                    cout << "************GAME OVER!************" << endl;
                    cout << aestheticLine << endl;
                }
            }
            
            
            
            //end program...
            
            
            
            
            
            //Ask user if they would like to RESTART the program or QUIT
            while (restart2 == true)
            {
                userChoice = menu.endMenu();
                if (userChoice == 1)
                {
                    restart = true;  //Will remain in outer loop upon exit of nested loop...
                    restart2 = false; //Set this to flase to exit nested loop, but remain in outer...
                }                      //Doing this will call menu.startMenu() again.
                else if (userChoice == 2)
                {
                    restart = false; //Sets both restart flags
                    restart2 = false; //to false to exit program
                }
                else //Will restart this loop and call menu.endMenu() if neither 1 nor 2 are selected
                {
                    cout << "You didn't select 1 or 2. Try again..." << endl;
                }
            }
            restart2 = true;
        }
        
        //cout << aestheticLine << endl;
        
        else if (userChoice == 2)
        {
            restart = false;
        }
        else //Will restart this loop and call menu.startMenu() if neither 1 nor 2 are selected
        {
            cout << "You didn't select 1 or 2. Try again..." << endl;
        }
    }
    
    cout << "Exiting program...goodbye!" << endl;
    return 0; //exits program by returning 0 to main function
}
