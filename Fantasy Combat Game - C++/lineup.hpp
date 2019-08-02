/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: lineup.hpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the header file for the Lineup class.
 ***************************************************************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include <stdio.h>
#include <string>
#include "character.hpp"

class Lineup
{
protected:
    std::string aestheticLine = "---------------------------------------------------------------";
    struct CharacterNode //Circular doubly linked list
    {
        Character* fighterType;
        std::string fighterName;
        CharacterNode* nextFighter;
        CharacterNode* prevFighter;
        CharacterNode(Character* fighterType = nullptr, std::string fighterName = "", CharacterNode* prevFighter = nullptr, CharacterNode* nextFighter = nullptr)
        {
            this->nextFighter = nextFighter;
            this->prevFighter = prevFighter;
            this->fighterType = fighterType;
            this->fighterName = fighterName;
        }
    };
    CharacterNode* head; //List head pointer
    CharacterNode* headOfLoserList;
    
public:
    Lineup() { head = nullptr; headOfLoserList = nullptr; }
    ~Lineup();
    void addToBack(Character* fighterType, std::string fighterName);
    void removeFront();
    void addToLoserList(Lineup list);
    void printLineup1();
    void printLineup2();
    void printLoserLineup();
    Character* getHead(Lineup list);
    //CharacterNode getHeadNode();
    void moveHeadPointerUpOne(Lineup list);
    std::string getFighterName();
    
};



#endif
