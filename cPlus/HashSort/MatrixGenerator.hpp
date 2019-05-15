//
//  MatrixGenerator.hpp
//  hashSort
//
//  Created by Gonzalo Urroz on 29/3/19.
//

#ifndef MatrixGenerator_hpp
#define MatrixGenerator_hpp

#include <stdio.h>
#include <iostream>
#include <random>
#include "Configuration.hpp"

using namespace std;

#include "DataGenerator.hpp"

class MatrixGenerator {
public:
    void generateMatrix(int** data, int arrayLength, double uniqueList, int distribuition, int dataOrder, double repeatedElementInArray);
    void generateSegmentedMatrix(int** data, int arrayLength, int dataOrder, double repeatedElementInArray);
    void copyMatrix(int** original, int** newArr, int arrayLength);
private:
};

#endif /* MatrixGenerator_hpp */
