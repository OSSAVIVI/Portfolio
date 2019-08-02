/***************************************************************************************
 ** Program Name: Text-Based Game (Final Project)
 ** Author: Ryan Wells Farran | File Name: mainFinalProject.cpp
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 06/11/2019 | Tuesday, June 11th 2019
 ** Description: Main file of the Text-Based Game program.
 ***************************************************************************************/
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include "menu.hpp"
#include "inputVal.hpp"
#include "spaceGrid.hpp"
#include "space.hpp"
#include "movementSpace.hpp"
#include "riddleSpace.hpp"
#include "goldenLyreSpace.hpp"
#include "inventory.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::fstream;

int main()
{
    //srand(time(0));
    
    string aestheticLine = "---------------------------------------------------------------"; //used to visually break up console output
    
    string socratesQ = "One of my student's students was Aristotle...";
    string socratesA = "My famous student Plato's famous student was Aristotle!";
    string euclidQ = "Pythagoras is the Father of Geometry...";
    string euclidA = "He wishes! I proved his work, so I'm the Father of Geometry!";
    string odysseusQ = "Some of my legendary voyage involved seafaring...";
    string odysseusA = "Aye, I know Poseidon's wrath all too well...";
    
    InputVal dummyInputVal; //Used to call functions in InputVal to validate user input
    
    //Code used with the Menu class object below
    int userChoice; //Stores whatever option user chooses from Menu class
    bool restart1 = true; //Used for first menu PLAY/EXIT prompt
    bool restart2 = true; //Used for second program PLAY AGAIN/EXIT prompt
    bool restart3 = true; //Used to continuously display menu options until 4 is selected
    Menu menu = Menu("the Text-Based Game (Final Project)!"); //calls constructor with the name of the game as a parameter
   
    while (restart1 == true) //Initially set to true, so will always run on the first run through
    {
        userChoice = menu.startMenu(); //Begins Start/Quit prompt
        if (userChoice == 1)
        {
            //run program...(user chose '1')
            cout << "Starting program...(user chose '1')" << endl;
            
            int menuOptionsChoice;
            menuOptionsChoice = menu.getMenuOptions();
            
            while (menuOptionsChoice != 1 && menuOptionsChoice != 2)
            {
                cout << "Invlaid option...try again...(user chose invalid option)" << endl;
                menuOptionsChoice = menu.getMenuOptions();
            }
            while (restart3 == true)
            {
                if (menuOptionsChoice == 1)
                {
                    
                    
                    //Instructions will go here
                    
                    
                    
                    //Code for creating the game board
                    SpaceGrid gameBoard;
                    gameBoard.connectPointers();
                    Inventory inventory;
                    gameBoard.setRiddlers();
                    gameBoard.setLyres();
                    gameBoard.placeCharacter();
                    gameBoard.printGrid();
                    inventory.printInventory();
                    
                    bool gameActive = true;
                    
                    int numberAnsweredCorrectly = 0;
                    
                    while (gameActive && gameBoard.getPlayerHealth() > 0)
                    {
                        std::cout << "INSTRUCTIONS:" << std::endl;
                        std::cout << "Enter 1 to move up, 2 to move right," << std::endl;
                        std::cout << "3 to move left, and 4 to move down." << std::endl;
                        std::cout << "Note: You can't move to previously" << std::endl;
                        std::cout << "visited spaces (marked with *)" << std::endl;
                        std::cout <<  std::endl;
                        std::cout << "The goal of the game is to answer" << std::endl;
                        std::cout << "ONLY TWO riddles by going underneath " << std::endl;
                        std::cout << "a great thinker (S, E, or O) and" << std::endl;
                        std::cout << "pressing 5 to invoke a riddle!" << std::endl;
                        std::cout << "Note: If you answer more than two riddles," << std::endl;
                        std::cout << "you're a show-off and you'll die!" << std::endl;
                        std::cout <<  std::endl;
                        std::cout << "After you've answered two riddles and" << std::endl;
                        std::cout << "received the two handwritten notes" << std::endl;
                        std::cout << "from the great thinkers, go under the Lyre (U)" << std::endl;
                        std::cout << "and then press 6 to invoke a jam session!" << std::endl;
                        std::cout << "Note: If you try to play the Lyre before," << std::endl;
                        std::cout << "getting expressed permission you'll die!" << std::endl;
                        std::cout <<  std::endl;
                        std::cout << "Note: If the player gets trapped you die!" << std::endl;
                        std::cout << "Note: Pressing 7 will QUIT the game!" << std::endl;
                        std::cout <<  std::endl;
                        
                        int movementChoice = dummyInputVal.getPosInt();
                        
                        while (movementChoice != 1 && movementChoice != 2 &&
                               movementChoice != 3 && movementChoice != 4 &&
                               movementChoice != 5 && movementChoice != 6 &&
                               movementChoice != 7)
                        {
                            std::cout << "ERROR!" << std::endl;
                            std::cout << "Enter 1 for up, 2 for right, 3 for left, 4 for down" << std::endl;
                            std::cout << "Note: you can't move to spaces previously visited, marked * )" << std::endl;
                            int movementChoice = dummyInputVal.getPosInt();
                        }
                        if (movementChoice == 1)
                        {
                            gameBoard.moveUp();
                        }
                        else if (movementChoice == 2)
                        {
                            gameBoard.moveRight();
                        }
                        else if (movementChoice == 3)
                        {
                            gameBoard.moveLeft();
                        }
                        else if (movementChoice == 4)
                        {
                            gameBoard.moveDown();
                        }
                        else if (movementChoice == 5)
                        {
                            if (gameBoard.riddlerIsAbovePlayer())
                            {
                                if (gameBoard.socratesAbove())
                                {
                                    bool gotTheQuestionRight = gameBoard.board[gameBoard.getPlayerRow()- 1][gameBoard.getPlayerColumn()].getRiddler()->askQuestion(socratesQ, socratesA, 1);
                                    if (gotTheQuestionRight)
                                    {
                                        inventory.setSocratesRiddleSolved(true);
                                        numberAnsweredCorrectly++;
                                        inventory.setCurrentInventory(inventory.getCurrentInventory()+1);
                                        if (inventory.getCurrentInventory() > 2)
                                        {
                                            std::cout << "I thought we warned you," << std::endl;
                                            std::cout << "cool, ancient Greek homies" << std::endl;
                                            std::cout << "like us HATE show-offs!" << std::endl;
                                            std::cout << "Get out of here, ya bozo!" << std::endl;
                                            gameBoard.setPlayerHealthToZero();
                                            gameActive = false;
                                            restart3 = false;
                                        }
                                    }
                                    else
                                    {
                                        std::cout << "WRONG! I thought you" << std::endl;
                                        std::cout << "were smart! Get our of" << std::endl;
                                        std::cout << "here, you low-life!!!" << std::endl;
                                        gameBoard.setPlayerHealthToZero();
                                        gameActive = false;
                                        restart3 = false;
                                    }
                                }
                                if (gameBoard.euclidAbove())
                                {
                                    bool gotTheQuestionRight = gameBoard.board[gameBoard.getPlayerRow()- 1][gameBoard.getPlayerColumn()].getRiddler()->askQuestion(euclidQ, euclidA, 2);
                                    if (gotTheQuestionRight)
                                    {
                                        inventory.setEuclidRiddleSolved(true);
                                        numberAnsweredCorrectly++;
                                        inventory.setCurrentInventory(inventory.getCurrentInventory()+1);
                                        if (inventory.getCurrentInventory() > 2)
                                        {
                                            std::cout << "I thought we warned you," << std::endl;
                                            std::cout << "cool, ancient Greek homies" << std::endl;
                                            std::cout << "like us HATE show-offs!" << std::endl;
                                            std::cout << "Get out of here, ya bozo!" << std::endl;
                                            gameBoard.setPlayerHealthToZero();
                                            gameActive = false;
                                            restart3 = false;
                                        }
                                    }
                                    else
                                    {
                                        std::cout << "WRONG! You probably" << std::endl;
                                        std::cout << "stink at Math, too..." << std::endl;
                                        std::cout << "beat it, nerd!!!" << std::endl;
                                        gameBoard.setPlayerHealthToZero();
                                        gameActive = false;
                                        restart3 = false;
                                    }
                                }
                                if (gameBoard.odysseusAbove())
                                {
                                    bool gotTheQuestionRight = gameBoard.board[gameBoard.getPlayerRow()- 1][gameBoard.getPlayerColumn()].getRiddler()->askQuestion(odysseusQ, odysseusA, 1);
                                    if (gotTheQuestionRight)
                                    {
                                        inventory.setOdysseusRiddleSolved(true);
                                        ++numberAnsweredCorrectly;
                                        inventory.setCurrentInventory(inventory.getCurrentInventory()+1);
                                        if (inventory.getCurrentInventory() > 2)
                                        {
                                            std::cout << "I thought we warned you," << std::endl;
                                            std::cout << "cool, ancient Greek homies" << std::endl;
                                            std::cout << "like us HATE show-offs!" << std::endl;
                                            std::cout << "Get out of here, ya bozo!" << std::endl;
                                            gameBoard.setPlayerHealthToZero();
                                            gameActive = false;
                                            restart3 = false;
                                        }
                                    }
                                    else
                                    {
                                        std::cout << "WRONG! You know nothing" << std::endl;
                                        std::cout << "wof honor and adventure," << std::endl;
                                        std::cout << "you bloody coward!!!" << std::endl;
                                        gameBoard.setPlayerHealthToZero();
                                        gameActive = false;
                                        restart3 = false;
                                    }
                                }
                            }
                            else
                            {
                                std::cout << "Try pressing 5 again," << std::endl;
                                std::cout << "but when a thinker (S," << std::endl;
                                std::cout << "E, or O) is above you!" << std::endl;
                            }
                        }
                        else if (movementChoice == 6)
                        {
                            if (gameBoard.lyreIsAbovePlayer())
                            {
                                //invoke lyre
                                bool correctNumberOfInventroy = gameBoard.board[gameBoard.getPlayerRow()- 1][gameBoard.getPlayerColumn()].getLyre()->invokeLyre(inventory.getCurrentInventory());
                                if (correctNumberOfInventroy)
                                {
                                    std::cout << "You won!" << std::endl;
                                    std::cout << "Time to jam, matey!" << std::endl;
                                    std::cout << aestheticLine << std::endl;
                                    std::cout << "Final Stats:" << std::endl;
                                    gameActive = false;
                                }
                                else
                                {
                                    std::cout << "I thought we warned you..." << std::endl;
                                    std::cout << "No touching without two" << std::endl;
                                    std::cout << "handwritten notes from great" << std::endl;
                                    std::cout << "thinkers...time to die, matey!" << std::endl;
                                    gameBoard.setPlayerHealthToZero();
                                    gameActive = false;
                                }
                            }
                            else
                            {
                                std::cout << "Try pressing 6 again," << std::endl;
                                std::cout << "but when the Lyre (U)" << std::endl;
                                std::cout << "is above you!" << std::endl;
                            }
                        }
                        else if (movementChoice == 7)
                        {
                            std::cout << "...Quitting game...Goodbye..." << std::endl;
                            gameActive = false;
                        }
                        else
                        {
                            std::cout << "you should never see this...check to be sure the logic for handling 1, 2, 3, 4 movment is good!" << std::endl;
                        }
                        gameBoard.printGrid();
                        inventory.printInventory();
                    }
                    
                    menuOptionsChoice = menu.getMenuOptions();
                }
                else if (menuOptionsChoice == 2)
                {
                    cout << "Executing option 2...(user chose '2')" << endl;
                    cout << aestheticLine << endl;
                    cout << "Quitting program...goodbye!" << endl;
                    cout << aestheticLine << endl;
                    restart3 = false; // Breaks out of menuOptions = getMenuOptions() loop
                }
                else
                { //Code should never execute because of validation in while loop above and because inputVal class functions
                    cout << "Invlaid option...try again...(user inputted invalid data)" << endl;
                }
            }
            //end program...
            
            //Ask user if they would like to RESTART the program or QUIT
            while (restart2 == true) //Initially set to true, so will always run on the first run through
            {
                userChoice = menu.endMenu();
                if (userChoice == 1)
                {
                    restart1 = true;  //Will remain in outer loop upon exit of nested loop...
                    restart2 = false; //Set this to flase to exit nested loop, but remain in outer...
                }                      //Doing this will call menu.startMenu() again.
                else if (userChoice == 2)
                {
                    restart1 = false; //Sets both restart flags
                    restart2 = false; //to false to exit program
                }
                else //Will restart this loop and call menu.endMenu() if neither 1 nor 2 are selected
                {
                    cout << "You didn't select 1 or 2. Try again..." << endl;
                }
            }
            restart2 = true; //Sets back to true so the program may be restarted a second time
            restart3 = true; //Sets back to true so the program may loop on second run again
        }
        
        else if (userChoice == 2)
        {
            //end program...(user chose '2')
            cout << "Ending program...(user chose '2')" << endl;
            restart1 = false;
        }
        else //Will restart this loop and call menu.startMenu() if neither 1 nor 2 are selected
        { //This code should never execute because getOneOrTwo() should prevent any option other than 1 or 2 being entered
            cout << "You didn't select 1 or 2. Try again..." << endl;
        }
    }
    
    cout << "Exiting program...goodbye!" << endl;
    return 0; //exits program by returning 0 to main function
}
//Have a great day! :)
