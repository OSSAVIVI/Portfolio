//
//  activitySelection.cpp
//  CS325HW4P4
//
//  Created by Ryan Farran on 10/28/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#include "activitySelection.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;


void ActivitySelection::multiLineHandler(std::string inputFileName)
{
    //Create arrays for storing information.
    MergeSort merge; //used to call stack and merge functions
    
    int currentNumberOfActivities = 0;
    int numOfNumbers = merge.countNumberOfCharactersInFile(inputFileName);
    
    
    //Begin cycling through act.txt and storing numbers into the corresponding arrays and variables!
    int numOfSets = 1;
    int count = 0;
    
    std::ifstream inputFile;
    inputFile.open(inputFileName.c_str()); //opens file using name passed as parameter
    if (!inputFile)
    {
        std::cout << "Unable to open " << inputFileName << std::endl; //explains issue if error opening
    }
    else
    {
        //Outer whiel loop until EOF
        while (!inputFile.eof())
        { //reads data from file into array
            DynArr* activityNumbers;
            DynArr* startTimes;
            DynArr* finishTimes;
            DynArr* chosenActivities;
            activityNumbers = merge.newDynArr((numOfNumbers/3) + 3); //Should be approximately the right size (a bit over one third)
            startTimes = merge.newDynArr((numOfNumbers/3) + 3); //Should be approximately the right size (a bit over one third)
            finishTimes = merge.newDynArr((numOfNumbers/3) + 3); //Should be approximately the right size (a bit over one third)
            chosenActivities = merge.newDynArr((numOfNumbers/3) + 3); //Should be approximately the right size (a bit over one third)
            
            count++;
            inputFile >> currentNumberOfActivities;
            int backUpNumOfActivities = currentNumberOfActivities;
            std::cout << "\tSet " << numOfSets++ << std::endl;
            std::cout << "\tNumber of activities selected = " << currentNumberOfActivities << std::endl;
            std::cout << "\tActivities: ";
            
            //Nested while loop for each SET
            while (currentNumberOfActivities > 0)
            {
                int tempActivityNumber;
                inputFile >> tempActivityNumber;
                merge.addDynArr(activityNumbers, tempActivityNumber);
                
                int tempStartTime;
                inputFile >> tempStartTime;
                merge.addDynArr(startTimes, tempStartTime);
                
                int tempFinishTime;
                inputFile >> tempFinishTime;
                merge.addDynArr(finishTimes, tempFinishTime);
                
                currentNumberOfActivities--;
            }
            
            int currentLastStart2 = 100000;
            int currentLastStart = -1;
            int lastStartIndex = -1;
            while (currentLastStart2 != 1)
            {
                for (int index = (merge.sizeDynArr(startTimes) - 1); index >= 0; index--)
                {
                    if ((int)merge.getDynArr(startTimes, index) > currentLastStart || (int)merge.getDynArr(startTimes, index) > merge.getDynArr(startTimes, lastStartIndex))
                    {
                        //std::cout << "We have entered the loop";
                        currentLastStart = merge.getDynArr(startTimes, index);
                        if ((int)merge.getDynArr(finishTimes, index) <= currentLastStart2)
                        {
                            //std::cout << "We have entered the loop2";
                            lastStartIndex = index;
                            currentLastStart2 = currentLastStart;
                        }
                    }
                }
                if (merge.getDynArr(activityNumbers, lastStartIndex) != -1)
                {
                    merge.addDynArr(chosenActivities, merge.getDynArr(activityNumbers, lastStartIndex));
                    //std::cout << merge.getDynArr(activityNumbers, lastStartIndex) << " ";
                    merge.putDynArr(activityNumbers, lastStartIndex, -1);
                    merge.putDynArr(startTimes, lastStartIndex, -1);
                    merge.putDynArr(finishTimes, lastStartIndex, 1000);
                    backUpNumOfActivities--;
                }
                else
                {
                    merge.deleteDynArr(activityNumbers);
                    merge.deleteDynArr(startTimes);
                    merge.deleteDynArr(finishTimes);
                    break;
                }
            }
            //Print to console in reverse order
            for (int index = merge.sizeDynArr(chosenActivities) - 1; index >= 0; index--)
            {
                std::cout << merge.getDynArr(chosenActivities, index) << " ";
            }
            std::cout << std::endl;
        }
    }
    inputFile.close(); //closes file
}






