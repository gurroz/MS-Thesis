//
//  SegmentedNaiveTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef SegmentedNaiveTest_hpp
#define SegmentedNaiveTest_hpp

#include <stdio.h>

#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"
#include "HashFunction.hpp"

using namespace std;

class SegmentedNaiveTest: public TestRun {
public:
    string run(Configuration conf);
    int runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength, double arrayRepetition);
    void runSortFunction(int** data, int arrayLength, SortFunction& sortFunction);
};
#endif /* SegmentedNaiveTest */
