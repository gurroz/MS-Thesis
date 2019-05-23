//
//  SegmentedOptHashTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef SegmentedOptHashTest_hpp
#define SegmentedOptHashTest_hpp

#include <stdio.h>

#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"
#include "HashFunction.hpp"

using namespace std;

struct HashAndRange {
    string hash;
    int min;
    int max;
};

class SegmentedOptHashTest: public TestRun {
public:
    string run(Configuration conf);
    int runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength, double arrayRepetition);
};
#endif /* SegmentedOptHashTest_hpp */
