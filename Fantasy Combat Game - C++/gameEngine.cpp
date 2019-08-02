/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: gameEngine.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the GameEngine class.
 ***************************************************************************************/

#include "gameEngine.hpp"
#include "character.hpp"

void GameEngine::setWhoAttacksFirstRand()
{ //sets whether or not player one or two attacks first
    int randNumber = ((rand() % 2) + 1);
    if (randNumber == 1)
    {
        playerOneAttacksFirst = true;
        std::cout << "✧✧✧ PLAYER ONE IS ATTACKING FIRST! ✧✧✧" << std::endl;
    }
    else
    {
        playerOneAttacksFirst = false;
        std::cout << "✧✧✧ PLAYER TWO IS ATTACKING FIRST! ✧✧✧" << std::endl;
    }
}

void GameEngine::startRounds(Character* playerOne, Character* playerTwo)
{
    round = 1; //resets rounds variable
    setWhoAttacksFirstRand(); //sets whether or not player one or two attacks first
    
    if (playerOneAttacksFirst)
    {
        while (!(playerOne->isDead()) && !(playerTwo->isDead()))
        {
            std::cout << aestheticLine << std::endl;
            std::cout << "Round: " << round << std::endl;
            std::cout << aestheticLine << std::endl;
            std::cout << "✧ PLAYER ONE IS ATTACKING! ✧" << std::endl;
            playerTwo->defend(playerOne->attack());
            if (!(playerTwo->isDead()))
            {
                std::cout << std::endl;
                std::cout << "✧ PLAYER TWO IS ATTACKING! ✧" << std::endl;
                playerOne->defend(playerTwo->attack());
            }
            round++;
        }
    }
    else
    {
        while (!(playerOne->isDead()) && !(playerTwo->isDead()))
        {
            std::cout << aestheticLine << std::endl;
            std::cout << "Round: " << round << std::endl;
            std::cout << aestheticLine << std::endl;
            std::cout << "✧ PLAYER TWO IS ATTACKING! ✧" << std::endl;
            playerOne->defend(playerTwo->attack());
            if (!(playerOne->isDead()))
            {
                std::cout << std::endl;
                std::cout << "✧ PLAYER ONE IS ATTACKING! ✧" << std::endl;
                playerTwo->defend(playerOne->attack());
            }
            round++;
        }
    }
    std::cout << std::endl;
    std::cout << aestheticLine << std::endl;
    std::cout << "✶✶✶ Great Match!!! ✶✶✶" << std::endl;
    std::cout << "✶✶✶ Great Match!!! ✶✶✶" << std::endl;
    std::cout << "✶✶✶ Great Match!!! ✶✶✶" << std::endl;
    std::cout << aestheticLine << std::endl;
    std::cout << std::endl;
}
