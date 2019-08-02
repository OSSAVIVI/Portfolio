/***************************************************************************************
 ** Program Name: Fantasty Combat Game (Project 4, Part 2) | File Name: lineup.cpp
 ** Author: Ryan Wells Farran
 ** Class: CS 162 400 S2019 (Intro to CS II) | Date: 05/27/2019 | Sunday, May 27th 2019
 ** Description:  This is the implementation file for the Lineup class.
 ***************************************************************************************/

#include "lineup.hpp"

Lineup::~Lineup()
{
    std::cout << aestheticLine << std::endl;
    std::cout << "...calling destructor..." << std::endl;
    CharacterNode* nodePtr = head;
    while (nodePtr->nextFighter != head && nodePtr == nullptr)
    {
        // Garbage keeps track of node to be deleted
        CharacterNode* garbage = nodePtr;
        // Move on to next node, if any (if nullptr then while loop will be exited)
        nodePtr = nodePtr->nextFighter;
        if (garbage->nextFighter != nullptr)
        {
            delete garbage; //deletes the "garbage" node
        }
        std::cout << "...node deleted..." << std::endl;
    }
    std::cout << aestheticLine << std::endl;
}

void Lineup::addToBack(Character* fighterType, std::string fighterName)
{
    std::cout << aestheticLine << std::endl;
    std::cout << "...finding the end of the Team Lineup..." << std::endl;
    if (head == nullptr) // List is empty
    { // Add the first node to the list and point head/tail to it
        std::cout << "This Lineup was empty...!" << std::endl;
        head = new CharacterNode(fighterType, fighterName, head, head);
        std::cout << "...but now it holds " << head->fighterName << "!" << std::endl;
    }
    else if (head->nextFighter == nullptr) // List has one element
    { // Use nodePtr to traverse the list
        CharacterNode* nodePtr = head;
        std::cout << "Found the last node!" << std::endl;
        nodePtr->nextFighter = new CharacterNode(fighterType, fighterName, nodePtr, head);
        head->prevFighter = nodePtr->nextFighter;
        std::cout << "The newest teammate is " << nodePtr->fighterName << "!" << std::endl;
    }
    else // List is not empty
    { // Use nodePtr to traverse the list
        CharacterNode* nodePtr = head;
        //CharacterNode* savedHead = head;
        while (nodePtr->nextFighter != head)
        {
            std::cout << "...not this node..." << std::endl;
            nodePtr = nodePtr->nextFighter;
        } // After exiting this while loop, nodePtr points to last node!
        std::cout << "Found the last node!" << std::endl;
        nodePtr->nextFighter = new CharacterNode(fighterType, fighterName, nodePtr, head);
        head->prevFighter = nodePtr->nextFighter;
        std::cout << "The newest teammate is " << nodePtr->fighterName << "!" << std::endl;
    }
    std::cout << aestheticLine << std::endl;
}

void Lineup::removeFront()
{
    std::cout << aestheticLine << std::endl;
    CharacterNode* nodePtr = head;
    CharacterNode* nextNodePtr = head->nextFighter;
    std::cout << "...finding the first node..." << std::endl;
    if (head == nullptr) // List is empty
    { // Add the first node to the list and point head/tail to it
        std::cout << "Hey this list is empty!" << std::endl;
        std::cout << "We can't remove the first node since there isn't one." << std::endl;
    }
    else if (head->nextFighter == head) // There is only one node in the list
    {
        nodePtr = head;
        nextNodePtr = nullptr;
        head = nullptr;
        delete nodePtr;  // Do not double delete nextNodePtr
    }
    else // List is not empty
    { // Use nodePtr to traverse the list
        nodePtr = head;
        head = nextNodePtr; // Set tail to now point to the second to last node
        nextNodePtr->prevFighter = nodePtr->prevFighter; //set second to last node's next pointer to nullptr to terminate list
        //delete nodePtr; //With nodePtr still pointing to disattached node, you can deallocate the memory
        std::cout << "The first node was removed." << std::endl;// sets next pointer to nullptr, but  prev pointer to nodePtr
    }
    std::cout << aestheticLine << std::endl;
}

void Lineup::addToLoserList(Lineup list)
{
    CharacterNode* nodePtr = head;
    //while (nodePtr->nextFighter != head)
    //{
        //if (nodePtr->fighterType->isDead()) //if the fighter is dead
        //{
            CharacterNode* prevFighterAlive = nodePtr->prevFighter;
            CharacterNode* nextFigherAlive = nodePtr->nextFighter;
            //prevFighterAlive->nextFighter = nextFigherAlive;
            nextFigherAlive->prevFighter = prevFighterAlive;
            nodePtr->prevFighter = nullptr;
            if (headOfLoserList == nullptr) // List is empty
            { // Add the first node to the list and point head to it
                std::cout << "This Loser List was empty...!" << std::endl;
                headOfLoserList = nodePtr;
                nodePtr->nextFighter = nullptr;
                nodePtr->prevFighter = nullptr;
                std::cout << "...but now it holds " << nodePtr->fighterName << "!" << std::endl;
            }
            else // List is not empty
            { // Use nodePtr to traverse the list
                CharacterNode* nodePtr2 = headOfLoserList;
                while (nodePtr2->nextFighter != nullptr)
                {
                    nodePtr2 = nodePtr->nextFighter;
                } // After exiting this while loop, nodePtr points to last node!
                nodePtr2->nextFighter = nodePtr;
                nodePtr->prevFighter = nodePtr2;
                nodePtr->nextFighter = nullptr;
                std::cout << "The newest member of the Loser List is " << nodePtr->fighterName << "!" << std::endl;
            }
        //}
        //nodePtr = nodePtr->nextFighter;
    //}
}

void Lineup::printLineup1()
{
    CharacterNode* nodePtr = head;
    int count = 1;
    std::cout << aestheticLine << std::endl;
    std::cout << "✢✢✢ TEAM ONE LINEUP ✢✢✢" << std::endl;
    std::cout << aestheticLine << std::endl;
    while (nodePtr->nextFighter != head)
    {
        std::cout << count << ": " << nodePtr->fighterName << std::endl;
        count++;
        nodePtr = nodePtr->nextFighter;
    }
    std::cout << count << ": " << nodePtr->fighterName << std::endl;
}

void Lineup::printLineup2()
{
    CharacterNode* nodePtr = head;
    int count = 1;
    std::cout << aestheticLine << std::endl;
    std::cout << "✢✢✢ TEAM TWO LINEUP ✢✢✢" << std::endl;
    std::cout << aestheticLine << std::endl;
    while (nodePtr->nextFighter != head)
    {
        std::cout << count << ": " << nodePtr->fighterName << std::endl;
        count++;
        nodePtr = nodePtr->nextFighter;
    }
    std::cout << count << ": " << nodePtr->fighterName << std::endl;
}

void Lineup::printLoserLineup()
{
    CharacterNode* nodePtr = head;
    int count = 1;
    std::cout << aestheticLine << std::endl;
    std::cout << "✢✢✢ LOSER LIST LINEUP (reverse) ✢✢✢" << std::endl;
    std::cout << aestheticLine << std::endl;
    while (nodePtr->prevFighter != head)
    {
        nodePtr = nodePtr->nextFighter;
        std::cout << count << ": " << nodePtr->fighterName << std::endl;
        count++;
    }
    std::cout << count << ": " << nodePtr->fighterName << std::endl;
}

Character* Lineup::getHead(Lineup list)
{
    CharacterNode* nodePtr = head;
    return head->fighterType;
}

/*
CharacterNode Lineup::getHeadNode()
{
    CharacterNode nodePtr = head;
    return nodePtr;
}
*/
void Lineup::moveHeadPointerUpOne(Lineup list)
{
    CharacterNode* nodePtr = head;
    head = nodePtr->nextFighter;
}

std::string Lineup::getFighterName()
{
    return head->fighterName;
}
