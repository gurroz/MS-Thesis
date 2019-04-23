//
//  SortingTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef SortingTest_hpp
#define SortingTest_hpp

#include <stdio.h>

#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"

using namespace std;

class SortingTest: public TestRun {
public:
    string run(Configuration conf);
    void runSortFunction(int** data, int arrayLength, SortFunction& sortFunction);
};
#endif /* SortingTest_hpp */
