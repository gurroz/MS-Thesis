//
//  BenchHash.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 14/5/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include <string>

#include "BenchHash.hpp"
#include "Murmur3.hpp"
#include <iostream>

using namespace std;

string BenchHash::hash(int list[], int length) {

    uint32_t seed = 31;
    uint64_t hash_otpt[2];  // allocate 128 bits
    MurmurHash3_x64_128(list, (uint32_t)length, seed, hash_otpt);
    
    return to_string(hash_otpt[0]);
}
