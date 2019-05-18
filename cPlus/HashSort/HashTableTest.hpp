//
//  HashTableTest.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef HashTableTest_hpp
#define HashTableTest_hpp

#include <stdio.h>
#include <random>
#include <string>
#include "TestRun.hpp"
#include "SortFunction.hpp"

using namespace std;

class HashTableTest: public TestRun {
public:
    string run(Configuration conf);
};
#endif /* HashTableTest_hpp */
