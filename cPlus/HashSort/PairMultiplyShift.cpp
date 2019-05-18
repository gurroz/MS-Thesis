#include "PairMultiplyShift.hpp"
#include <string>
#include <iostream>


using namespace std;

PairMultiplyShift::PairMultiplyShift()
{
    for(int i = 0; i < 512; i++) {
        a1Constant[i] = rand() % 100000;
//        a2Constant[i] = rand() % 100000;
    }
}

string PairMultiplyShift::hash(int list[], int length) {
    uint64_t hashVal1 = 17;
//    uint64_t hashVal2 = 31;

    for(int i = 0; i < (length / 2); i++) {
        int firstIndex = 2*i;
        int secondIndex = firstIndex + 1;

        uint64_t mult1 = (a1Constant[firstIndex] + list[secondIndex]) * (a1Constant[secondIndex] + list[firstIndex]);
//        uint64_t mult2 = (a2Constant[firstIndex] + list[secondIndex]) * (a2Constant[secondIndex] + list[firstIndex]);

//        cout << "PairMultiplyShift " << i << " Val:" << hashVal << " Mult: " << mult << endl;

        hashVal1 = hashVal1 + mult1;
//        hashVal2 = hashVal2 + mult2;
    }
    
    return to_string(hashVal1);
}

