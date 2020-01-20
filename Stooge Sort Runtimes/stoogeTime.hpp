//
//  StoogeTime.hpp
//  CS325HWProblem3
//
//  Created by Ryan Farran on 10/7/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#ifndef stoogeTime_hpp
#define stoogeTime_hpp

#include <stdio.h>

class StoogeTime {
    
public:
    void printArray(int* arrayToPrint, int sizeOfArray);
    void recursiveStoogeSort(int* arrayToSort, int begIndex, int endIndex);
};

#endif /* StoogeTime_hpp */
