//
//  SegmentedOptHashTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef MemoBlockOpt_hpp
#define MemoBlockOpt_hpp

#include <stdio.h>

#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"
#include "HashFunction.hpp"

using namespace std;

class MemoBlockOptTest: public TestRun {
public:
    string run(Configuration conf);
    void runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength, double arrayRepetition);
};
#endif /* MemoBlockOpt_hpp */
