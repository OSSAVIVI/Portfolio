//
//  mergeTime.hpp
//  CS325HWProblem3
//
//  Created by Ryan Farran on 10/7/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#ifndef mergeTime_hpp
#define mergeTime_hpp

#include <stdio.h>

class MergeTime {
    
public:
    void printArray(int* arrayToPrint, int sizeOfArray);
    void baseMerge(int* arrayToSort, int begIndex, int middleIndex, int endIndex);
    void recursiveMergeSort(int* arrayToSort, int begIndex, int endIndex);
    
};

#endif /* mergeTime_hpp */
