/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: mainProject4.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description: This is the main program for the Fantasy Combat Game program.
 ***************************************************************************************/
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.hpp"
#include "inputVal.hpp"
#include "gameEngine.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "lineup.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main() {
    string aestheticLine = "---------------------------------------------------------------"; //used to visually break up console output
    InputVal dummyInputVal; //Used to call input validation functions
    GameEngine dummyGameEngine; //Used to call game engine functions
    Lineup dummyLineup;
    
    //Code used with the Menu class object below
    int userChoice; //Stores whatever option user chooses from Menu class
    bool restart1 = true; //Used for first menu PLAY/EXIT prompt
    bool restart2 = true; //Used for second program PLAY AGAIN/EXIT prompt
    bool restart3 = true; //Used to continuously display menu options until quit option is selected
    
    //Pointers to character objects for players 1 and 2
    Character* playerOnePtr = nullptr;
    Character* playerTwoPtr = nullptr;
    
    Menu menu = Menu("the Fantasty Combat Game (Project 4, Part 2)"); //calls constructor with the name of the game as a parameter
    while (restart1 == true) //Initially set to true, so will always execute on the program's first run
    {
        userChoice = menu.startMenu(); //Begins Start/Quit prompt
        if (userChoice == 1)
        {   //run program...(user chose '1')
            
            srand(time(0));
            
            cout << "Enter the number of fighters for both teams!" << endl;
            int numOfPlayersForEachTeam = dummyInputVal.getPosInt();
            cout << aestheticLine << endl;
            cout << "Okay, each team will have " << numOfPlayersForEachTeam << " players!" << endl;
            cout << "Now we'll choose what type of fighter each player will be" << endl;
            cout << "and also choose a name for each player on the team." << endl;
            cout << aestheticLine << endl;
            
            Lineup TeamOneLineUp;
            Lineup TeamTwoLineUp;
            Lineup LoserList;
            
            //Get Player One character
            cout << "✪✪✪ TEAM ONE ✪✪✪" << endl;
            int count = 1;
            for (int teamOneIndex = 0; teamOneIndex < numOfPlayersForEachTeam; teamOneIndex++)
            {
                
                cout << "✪✪✪ PLAYER " << count << " ✪✪✪" << endl;
                count++;
                int menuOptionsChoicePlayerOne = menu.getMenuOptionsPlayerOne();
                while (menuOptionsChoicePlayerOne != 1 && menuOptionsChoicePlayerOne != 2 &&
                       menuOptionsChoicePlayerOne != 3 && menuOptionsChoicePlayerOne != 4 &&
                       menuOptionsChoicePlayerOne != 5 && menuOptionsChoicePlayerOne != 6)
                {
                    cout << "Invlaid option...try again...(user chose invalid option)" << endl;
                    menuOptionsChoicePlayerOne = menu.getMenuOptionsPlayerOne();
                }
                //Go through and create player one pointer first
                if (menuOptionsChoicePlayerOne == 1)
                {
                    std::cout << "Player One chose Vampire" << std::endl;
                    playerOnePtr = new Vampire();
                    std::string playerOneName;
                    cout << "What is your Vampire's name?" << endl;
                    cin.ignore();
                    getline(cin, playerOneName);
                    cout << "Okay, this Vampire's name is " << playerOneName << endl;
                    TeamOneLineUp.addToBack(playerOnePtr, playerOneName);
                    cout << aestheticLine << endl;
                }
                else if (menuOptionsChoicePlayerOne == 2)
                {
                    std::cout << "Player One chose Barbarian" << std::endl;
                    playerOnePtr = new Barbarian();
                    std::string playerOneName;
                    cout << "What is your Barbarian's name?" << endl;
                    cin.ignore();
                    getline(cin, playerOneName);
                    cout << "Okay, this Barbarian's name is " << playerOneName << endl;
                    TeamOneLineUp.addToBack(playerOnePtr, playerOneName);
                    cout << aestheticLine << endl;
                }
                else if (menuOptionsChoicePlayerOne == 3)
                {
                    std::cout << "Player One chose Blue Men" << std::endl;
                    playerOnePtr = new BlueMen();
                    std::string playerOneName;
                    cout << "What is your Blue Men's name?" << endl;
                    cin.ignore();
                    getline(cin, playerOneName);
                    cout << "Okay, this Blue Men's name is " << playerOneName << endl;
                    TeamOneLineUp.addToBack(playerOnePtr, playerOneName);
                    cout << aestheticLine << endl;
                }
                else if (menuOptionsChoicePlayerOne == 4)
                {
                    std::cout << "Player One chose Medusa" << std::endl;
                    playerOnePtr = new Medusa();
                    std::string playerOneName;
                    cout << "What is your Medusa's name?" << endl;
                    cin.ignore();
                    getline(cin, playerOneName);
                    cout << "Okay, this Medusa's name is " << playerOneName << endl;
                    TeamOneLineUp.addToBack(playerOnePtr, playerOneName);
                    cout << aestheticLine << endl;
                }
                else if (menuOptionsChoicePlayerOne == 5)
                {
                    std::cout << "Player One chose Harry Potter" << std::endl;
                    playerOnePtr = new HarryPotter();
                    std::string playerOneName;
                    cout << "What is your Harry Potter's name?" << endl;
                    cin.ignore();
                    getline(cin, playerOneName);
                    cout << "Okay, this Harry Potter's name is " << playerOneName << endl;
                    TeamOneLineUp.addToBack(playerOnePtr, playerOneName);
                    cout << aestheticLine << endl;
                }
                else if (menuOptionsChoicePlayerOne == 6)
                {
                    cout << "Quitting program...goodbye!" << endl;
                    cout << aestheticLine << endl;
                    restart3 = false; // Breaks out of menuOptions = getMenuOptions() loop
                }
                else
                { //Code should never execute because of validation in while loop above and because inputVal class functions
                    cout << "Invlaid option...try again...(user inputted invalid data)" << endl;
                }
            }
            
            if (restart3 != false) //If Player One did not quit, then Player Two will choose a character
            {
                //Get Player Two character
                cout << "✪✪✪ TEAM TWO ✪✪✪" << endl;
                int count2 = 1;
                for (int teamTwoIndex = 0; teamTwoIndex < numOfPlayersForEachTeam; teamTwoIndex++)
                {
                    cout << "✪✪✪ PLAYER " << count2 << " ✪✪✪" << endl;
                    count2++;
                    int menuOptionsChoicePlayerTwo = menu.getMenuOptionsPlayerTwo();
                    while (menuOptionsChoicePlayerTwo != 1 && menuOptionsChoicePlayerTwo != 2 &&
                           menuOptionsChoicePlayerTwo != 3 && menuOptionsChoicePlayerTwo != 4 &&
                           menuOptionsChoicePlayerTwo != 5 && menuOptionsChoicePlayerTwo != 6)
                    {
                        cout << "Invlaid option...try again...(user chose invalid option)" << endl;
                        menuOptionsChoicePlayerTwo = menu.getMenuOptionsPlayerTwo();
                    }
                    //Go through and create player two pointer first
                    if (menuOptionsChoicePlayerTwo == 1)
                    {
                        std::cout << "Player Two chose Vampire" << std::endl;
                        playerTwoPtr = new Vampire();
                        std::string playerTwoName;
                        cout << "What is your Vampire's name?" << endl;
                        cin.ignore();
                        getline(cin, playerTwoName);
                        cout << "Okay, this Vampire's name is " << playerTwoName << endl;
                        TeamTwoLineUp.addToBack(playerTwoPtr, playerTwoName);
                        cout << aestheticLine << endl;
                    }
                    else if (menuOptionsChoicePlayerTwo == 2)
                    {
                        std::cout << "Player Two chose Barbarian" << std::endl;
                        playerTwoPtr = new Barbarian();
                        std::string playerTwoName;
                        cout << "What is your Barbarian's name?" << endl;
                        cin.ignore();
                        getline(cin, playerTwoName);
                        cout << "Okay, this Barbarian's name is " << playerTwoName << endl;
                        TeamTwoLineUp.addToBack(playerTwoPtr, playerTwoName);
                        cout << aestheticLine << endl;
                    }
                    else if (menuOptionsChoicePlayerTwo == 3)
                    {
                        std::cout << "Player Two chose Blue Men" << std::endl;
                        playerTwoPtr = new BlueMen();
                        std::string playerTwoName;
                        cout << "What is your Blue Men's name?" << endl;
                        cin.ignore();
                        getline(cin, playerTwoName);
                        cout << "Okay, this Blue Men's name is " << playerTwoName << endl;
                        TeamTwoLineUp.addToBack(playerTwoPtr, playerTwoName);
                        cout << aestheticLine << endl;
                    }
                    else if (menuOptionsChoicePlayerTwo == 4)
                    {
                        std::cout << "Player Two chose Medusa" << std::endl;
                        playerTwoPtr = new Medusa();
                        std::string playerTwoName;
                        cout << "What is your Medusa's name?" << endl;
                        cin.ignore();
                        getline(cin, playerTwoName);
                        cout << "Okay, this Medusa's name is " << playerTwoName << endl;
                        TeamTwoLineUp.addToBack(playerTwoPtr, playerTwoName);
                        cout << aestheticLine << endl;
                    }
                    else if (menuOptionsChoicePlayerTwo == 5)
                    {
                        std::cout << "Player Two chose Harry Potter" << std::endl;
                        playerTwoPtr = new HarryPotter();
                        std::string playerTwoName;
                        cout << "What is your Harry Potter's name?" << endl;
                        cin.ignore();
                        getline(cin, playerTwoName);
                        cout << "Okay, this Harry Potter's name is " << playerTwoName << endl;
                        TeamTwoLineUp.addToBack(playerTwoPtr, playerTwoName);
                        cout << aestheticLine << endl;
                    }
                    else if (menuOptionsChoicePlayerTwo == 6)
                    {
                        cout << "Quitting program...goodbye!" << endl;
                        cout << aestheticLine << endl;
                        restart3 = false; // Breaks out of menuOptions = getMenuOptions() loop
                    }
                    else
                    { //Code should never execute because of validation in while loop above and because inputVal class functions
                        cout << "Invlaid option...try again...(user inputted invalid data)" << endl;
                    }
                }
            }
            
            while (restart3 == true)
            {
                srand(time(0));
                
                TeamOneLineUp.printLineup1();
                
                TeamTwoLineUp.printLineup2();
                
                cout << endl;
                
                int matchNumber = 1;
                int plyaerOneLivesLeft = numOfPlayersForEachTeam;
                int plyaerTwoLivesLeft = numOfPlayersForEachTeam;
                int playerOneScore = 0;
                int playerTwoScore = 0;
                
                while (plyaerOneLivesLeft > 0 && plyaerTwoLivesLeft > 0)
                {
                    cout << "MATCH NUMBER: " << matchNumber << endl;
                    matchNumber++;
                    
                    playerOnePtr = TeamOneLineUp.getHead(TeamOneLineUp);
                    playerTwoPtr = TeamTwoLineUp.getHead(TeamTwoLineUp);
                    
                    dummyGameEngine.startRounds(playerOnePtr, playerTwoPtr);
                    
                    if (playerTwoPtr->getStrength() <= 0)
                    {
                        std::cout << aestheticLine << std::endl;
                        playerOneScore += 2;
                        playerTwoScore -= 1;
                        cout << "✶✶✶ PLAYER ONE WINS!!! ✶✶✶" << endl;
                        cout << "✶✶✶ PLAYER ONE SCORE: " << playerOneScore << " ✶✶✶" << endl;
                        cout << "✶✶✶ PLAYER TWO SCORE: " << playerTwoScore << " ✶✶✶" << endl;
                        plyaerTwoLivesLeft--;
                        //TeamTwoLineUp.addToLoserList(TeamTwoLineUp);
                        LoserList.addToBack(playerTwoPtr, "blank");
                        TeamTwoLineUp.removeFront();
                        playerOnePtr->recovery();
                        TeamOneLineUp.moveHeadPointerUpOne(TeamOneLineUp);
                        TeamTwoLineUp.moveHeadPointerUpOne(TeamTwoLineUp);
                        std::cout << aestheticLine << std::endl;
                        std::cout << std::endl;
                    }
                    else if (playerOnePtr->getStrength() <= 0)
                    {
                        std::cout << aestheticLine << std::endl;
                        playerTwoScore += 2;
                        playerOneScore -= 1;
                        cout << "✶✶✶ PLAYER TWO WINS!!! ✶✶✶" << endl;
                        cout << "✶✶✶ PLAYER ONE SCORE: " << playerOneScore << " ✶✶✶" << endl;
                        cout << "✶✶✶ PLAYER TWO SCORE: " << playerTwoScore << " ✶✶✶" << endl;
                        plyaerOneLivesLeft--;
                        //TeamOneLineUp.addToLoserList(TeamOneLineUp);
                        LoserList.addToBack(playerOnePtr, "blank");
                        TeamOneLineUp.removeFront();
                        playerTwoPtr->recovery();
                        TeamOneLineUp.moveHeadPointerUpOne(TeamOneLineUp);
                        TeamTwoLineUp.moveHeadPointerUpOne(TeamTwoLineUp);
                        std::cout << aestheticLine << std::endl;
                        std::cout << std::endl;
                    }
                    else
                    {
                        std::cout << aestheticLine << std::endl;
                        cout << "✶✶✶ IT'S A DRAW!!! ✶✶✶" << endl;
                        cout << "✶✶✶ PLAYER ONE SCORE: " << playerOneScore << " ✶✶✶" << endl;
                        cout << "✶✶✶ PLAYER TWO SCORE: " << playerTwoScore << " ✶✶✶" << endl;
                        plyaerOneLivesLeft--;
                        plyaerTwoLivesLeft--;
                        std::cout << aestheticLine << std::endl;
                        std::cout << std::endl;
                    }
                   
                    
                    
                    
                }
                
                if (playerOneScore > playerTwoScore)
                {
                    cout << "PLAYER ONE WINS THE TOURNAMENT WITH " << playerOneScore << " POINTS!" << endl;
                    cout << "THE TOURNAMENT TOOK " << matchNumber << " MATCHES TO FINISH!" << endl;
                }
                else
                {
                    cout << "PLAYER TWO WINS THE TOURNAMENT WITH " << playerTwoScore << " POINTS!" << endl;
                    cout << "THE TOURNAMENT TOOK " << matchNumber << " MATCHES TO FINISH!" << endl;
                }
                LoserList.printLoserLineup();
                delete playerOnePtr;
                delete playerTwoPtr;
                
                restart3 = false;
                
            }
            

            
            //end program...
            
            //Ask user if they would like to RESTART the program or QUIT
            while (restart2 == true) //Initially set to true, so will always run on the first run through
            {
                userChoice = menu.endMenu();
                if (userChoice == 1)
                {
                    restart1 = true;  //Will remain in outer loop upon exit of nested loop...
                    restart2 = false;
                    //Set this to flase to exit nested loop, but remain in outer...
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
