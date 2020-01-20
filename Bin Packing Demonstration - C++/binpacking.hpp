//
//  binpacking.hpp
//  CS325HW8
//
//  Created by Ryan Farran on 12/4/19.
//  Copyright © 2019 Ryan Farran. All rights reserved.
//

#ifndef binpacking_hpp
#define binpacking_hpp

#include <stdio.h>
#include "mergesort.hpp"

class BinPacking {
public:
    std::string aestheticLine = "---------------------------------------------------------------"; //Used to visually seperate console output
    typedef struct DynArr DynArr;

    void multiLineHandler(std::string inputFileName);
    
    int firstFit(DynArr* itemArray, int numberOfItems, int capacity);
    int firstFitDec(DynArr* itemArray, int numberOfItems, int capacity);
    int bestFit(DynArr* itemArray, int numberOfItems, int capacity);
    
};

#endif /* binpacking_hpp */
