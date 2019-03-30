//
//  MatrixGenerator.cpp
//  hashSort
//
//  Created by Gonzalo Urroz on 29/3/19.
//

#include "MatrixGenerator.hpp"

void MatrixGenerator::generateMatrix(int** data, int arrayLength, double uniqueList, int distribuition, int dataOrder, double repeatedElementInArray) {
    int uniqueAmount = round(TOTAL_LIST_NUMBER * uniqueList);
    if (uniqueAmount == 0) {
        uniqueAmount++;
    }
    
    int** uniqueData = new int*[uniqueAmount];
    
    DataGenerator dataGen;
    double average = (double) uniqueAmount/2;
    double stdDev = (double)uniqueAmount/4;
    
    default_random_engine generator;
    normal_distribution<double> distribution(average, stdDev);
    
    for(int i = 0; i < uniqueAmount; i++) {
        uniqueData[i] = new int[arrayLength];
        dataGen.generateArray(uniqueData[i], dataOrder, arrayLength);
    }
    
    int i=0;
    switch(distribuition) {
        case 0 : // Uniform
            while( i < TOTAL_LIST_NUMBER) {
                data[i] = new int[arrayLength];
                
                int k = i % uniqueAmount;
                for(int j=0; j < arrayLength; j++) {
                    data[i][j] = uniqueData[k][j];
                }
                
                i++;
            }
            
            break;
        case 1 : // Normal
            i=0;
            while( i < TOTAL_LIST_NUMBER) {
                int k = round(distribution(generator));
                while( k < 0 || k >= uniqueAmount) {
                    k = round(distribution(generator));
                }
                
                
                data[i] = new int[arrayLength];
                for(int j=0; j < arrayLength; j++) {
                    data[i][j] = uniqueData[k][j];
                }
                i++;
            }
            
            break;
        case 2 : // differences (Add -1000 by some amount on some of the rows)
            int repeatElements = round(arrayLength * repeatedElementInArray);
            if (repeatElements == 0) {
                repeatElements++;
            }
            i=0;
            
            while( i < TOTAL_LIST_NUMBER) {
                data[i] = new int[arrayLength];
                
                
                int k = i % uniqueAmount;
                for(int j=0; j < arrayLength; j++) {
                    data[i][j] = uniqueData[k][j];
                }
                
                cout << "Replacing " <<  i  <<  ": " <<  repeatElements << endl;
                
                // Replaces random positions with uniqe value
                int currentRepeatedElements = 0;
                for(int j=0; j < arrayLength; j++) {
                    if(currentRepeatedElements < repeatElements) {
                        int randomIndex = rand() % arrayLength;
                        while( randomIndex < 0 || randomIndex >= arrayLength) {
                            randomIndex = rand() % arrayLength;
                        }
                        data[i][randomIndex] = -1000;
                        currentRepeatedElements++;
                    }
                }
                
                i++;
            }
            break;
    }
};


void MatrixGenerator::generateSegmentedMatrix(int** data, int arrayLength, int dataOrder, double repeatedElementInArray) {
  // Generate unique arrays of length X. X is the lenth of the array divided by something
    // fill each array with one of the unique, Y times (Given by parameter: repeatedElementInArray)
    // Fill the rest of the array with new random data
    int uniqueSegmentLength = round(arrayLength * repeatedElementInArray);
    
    int* seminalArray = new int[uniqueSegmentLength];
    
    DataGenerator dataGen;
    dataGen.generateArray(seminalArray, dataOrder, uniqueSegmentLength);
    
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
        data[i] = new int[arrayLength];
        dataGen.generateArray(data[i], dataOrder, arrayLength);

        for(int j=0; j < uniqueSegmentLength; j++) {
            data[i][j] = seminalArray[j];
        }
    }
};

void MatrixGenerator::copyMatrix(int** original, int** newArr, int arrayLength) {
    for(int i=0; i < TOTAL_LIST_NUMBER; i++) {
        newArr[i] = new int[arrayLength];
        for(int j=0; j < arrayLength; j++) {
            newArr[i][j] = original[i][j];
        }
    }
}
