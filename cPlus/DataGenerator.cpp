#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <random>

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
		result[i] = rand() % 2000;
	}
};

void DataGenerator::generateRandomNormalArray(int* result, int length) {
	double average = 1000.0;
	double stdDev = 250.0;

	default_random_engine generator;
  	normal_distribution<double> distribution(average, stdDev);

	for(int i = 0; i < length; i++) {
		result[i] = ((int) round(distribution(generator)));
	}
};

void DataGenerator::generateAscOrderedArray(int* result, int length) {
	int multiplier = rand() % 100;
	for(int i = 0; i < length; i++) {
		result[i] = i * multiplier;
	}
};

void DataGenerator::generateDescOrderedArray(int* result, int length) {
	int multiplier = rand() % 100;
	for(int i = 0; i < length; i++) {
		result[i] = (length-i) * multiplier;
	}
};
