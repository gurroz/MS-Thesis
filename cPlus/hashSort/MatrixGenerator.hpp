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
using namespace std;

#include "DataGenerator.hpp"

//#define TOTAL_LIST_NUMBER 1036800
#define TOTAL_LIST_NUMBER 4


class MatrixGenerator {
public:
    void generateMatrix(int** data, int arrayLength, double uniqueList, int distribuition, int dataOrder, double repeatedElementInArray);
    void generateSegmentedMatrix(int** data, int arrayLength, int dataOrder, double repeatedElementInArray);
    void copyMatrix(int** original, int** newArr, int arrayLength);
private:
};

#endif /* MatrixGenerator_hpp */
