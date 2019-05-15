//
//  HashTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef HashTest_hpp
#define HashTest_hpp

#include <stdio.h>

#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"
#include "HashFunction.hpp"

using namespace std;

class HashTest: public TestRun {
public:
    string run(Configuration conf);
    int checkColitions(int** data, HashFunction& hashFunc, int arrayLength);
    void runHash(string name, int** data, HashFunction& hashFunc, int arrayLength);
};
#endif /* HashTest.hpp */
