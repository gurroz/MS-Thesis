//
//  HashingSortTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef HashingSortTest_hpp
#define HashingSortTest_hpp

#include <stdio.h>

#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"
#include "HashFunction.hpp"

using namespace std;

class HashingSortTest: public TestRun {
public:
    string run(Configuration conf);
    int runHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, string name);
    int runHashMap(int** data, HashFunction& hashFunc, int arrayLength);
};
#endif /* HashingSortTest */
