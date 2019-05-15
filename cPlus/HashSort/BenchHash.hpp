//
//  BenchHash.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 14/5/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef BenchHash_hpp
#define BenchHash_hpp

#include <string>
#include "HashFunction.hpp"

using namespace std;

class BenchHash: public HashFunction {
public:
    string hash(int list[], int length);
};

#endif /* BenchHash_hpp */
