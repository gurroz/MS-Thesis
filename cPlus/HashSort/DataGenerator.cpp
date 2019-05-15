#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

#include "DataGenerator.hpp"

void DataGenerator::generateArray(int* result, int type, int length){
	switch(type) {
	    case 0 : 
	    	generateRandomUniformArray(result, length);
	     	break;
		case 1 : 
			generateAscOrderedArray(result, length);
			break;
	    case 2 : 
	    	generateDescOrderedArray(result, length);
	     	break;
		case 3 : 
			generateRandomNormalArray(result, length);
			break;
	}
};

void DataGenerator::generateRandomUniformArray(int* result, int length) {
	for(int i = 0; i < length; i++) {
		result[i] = rand();
	}
};

void DataGenerator::generateRandomNormalArray(int* result, int length) {
    double average = RAND_MAX /2;
    double stdDev = RAND_MAX / 4;
    
//    double average = 1000000 /2; -> Colission 13154
//    double stdDev = 1000000 / 4;
//
  	normal_distribution<double> distribution(average, stdDev);

	for(int i = 0; i < length; i++) {
		result[i] = ((int) round(distribution(generator)));
	}
};

void DataGenerator::generateAscOrderedArray(int* result, int length) {
	for(int i = 0; i < length; i++) {
		result[i] = rand();
	}

    sort(result, result+length);
};

void DataGenerator::generateDescOrderedArray(int* result, int length) {
    for(int i = 0; i < length; i++) {
        result[i] = rand();
    }
    
    sort(result, result+length, greater<int>());

};
