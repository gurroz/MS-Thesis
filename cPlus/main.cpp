// basic file operations
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <unordered_map> 
#include <math.h>       /* round, floor, ceil, trunc */
#include <random>

#include "SortFunction.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "DataGenerator.hpp"
#include "HashFunction.hpp"
#include "AdditiveHashFunction.hpp"
#include "PrimeHashFunction.hpp"
#include "XorHashFunction.hpp"

using namespace std;

#define TOTAL_LIST_NUMBER 1036800
// #define TOTAL_LIST_NUMBER 4
#define TOTAL_TEST 1
#define DISTRIBUTION 0 // 0: Unifor, 1: Normal
#define LIST_ORDER 0 // 0: RAND, 1: ASC, 2: DESC


void runSortFunction(int** data, int arrayLength, SortFunction& sortFunction){
	for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
		sortFunction.sort(data[j], arrayLength);
	}
}

void generateData(int** data, int arrayLength, double uniqueList, int distribuition, int dataOrder) {

	int uniqueAmount = round(TOTAL_LIST_NUMBER * uniqueList);
	if (uniqueAmount == 0) {
		uniqueAmount++;
	}

	int** uniqueData = new int*[uniqueAmount];

	DataGenerator DataGen;


    for(int i = 0; i < uniqueAmount; i++) {
		uniqueData[i] = new int[arrayLength];
		DataGen.generateArray(uniqueData[i], dataOrder, arrayLength);
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
			double average = (double) uniqueAmount/2;
			double stdDev = (double)uniqueAmount/4;

			default_random_engine generator;
  			normal_distribution<double> distribution(average, stdDev);

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
	}


}

void printArray(int run, int** originalData, int arrayLength) {
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
		int* currentArr = originalData[i];

		string arrayList = "";
		for(int j = 0; j < arrayLength; j++) {
			arrayList = arrayList + std::to_string(currentArr[j]);
			arrayList = arrayList + ",";
		}
		cout << "Ordered" <<  run  <<  ": " <<  arrayList << endl; 
	}
}

int runHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, string name) {
	unordered_map<string, int> signaturesMap;

	int deadCodeReturn = 0;
	for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
		string signature = hashFunc.hash(data[j], arrayLength);

		if(signaturesMap.find(signature) == signaturesMap.end()) {
			sortFunction.sort(data[j], arrayLength);
			// cout << name << " Sorted: " <<  signature   << endl; 
			signaturesMap.insert(make_pair(signature, 1));
		} 
	}
	return deadCodeReturn;
}

int runHashMap(int** data, HashFunction& hashFunc, int arrayLength) {
	unordered_map<string, int> signaturesMap;

	int deadCodeReturn = 0;
	for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
		string signature = hashFunc.hash(data[j], arrayLength);

		if(signaturesMap.find(signature) == signaturesMap.end()) {
			signaturesMap.insert(make_pair(signature, 1));
			deadCodeReturn++;
		}
	}
	return deadCodeReturn;
}

int checkColitions(int** data, HashFunction& hashFunc, int arrayLength) {
	unordered_map<string, int> signaturesMap;

	int colitions = 0;
	for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
		string signature = hashFunc.hash(data[j], arrayLength);

		unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
		if(signatureFinder == signaturesMap.end()) {
			signaturesMap.insert(make_pair(signature, j));
		} else {
			int originalIndex = signatureFinder->second;
			for(int i = 0; i < arrayLength; i++) {
				if(data[originalIndex][i] != data[j][i]) {
					colitions++;
					break;
				}
			}
		}
	}

	return colitions;
}

void copyMatrix(int** original, int** newArr, int arrayLength) {
 	for(int i=0; i < TOTAL_LIST_NUMBER; i++) {
 		newArr[i] = new int[arrayLength];
        for(int j=0; j < arrayLength; j++) {
        	newArr[i][j] = original[i][j];
        }
 	}
}

void runSortingTests(int arrayLength, int distribution, double uniqueness, int listOrder) {
	long totalInsertion = 0;
	long totalMerge = 0;

	InsertionSort insertionSort;
	MergeSort mergeSort;

	for(int i=0; i < TOTAL_TEST; i++) {
		int** originalData = new int*[TOTAL_LIST_NUMBER];
		int** copiedData = new int*[TOTAL_LIST_NUMBER];
		
		generateData(originalData, arrayLength, uniqueness, distribution, listOrder);
		copyMatrix(originalData, copiedData, arrayLength);
		

		auto start = std::chrono::high_resolution_clock::now();
		runSortFunction(originalData, arrayLength, insertionSort);
		auto finish = std::chrono::high_resolution_clock::now();
		auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalInsertion = totalInsertion + int_ms.count();


		start = std::chrono::high_resolution_clock::now();
		runSortFunction(copiedData, arrayLength, mergeSort);
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalMerge = totalMerge + int_ms.count();
	}

	cout << "********************************************"<< endl; 
	cout << "Array_Length: "<< arrayLength << " Distribution: "<< distribution << " Uniq: "<< uniqueness <<  " Order: "<< listOrder <<endl; 
	cout << "********************************************"<< endl; 

	cout << "Insertion average time: " <<  to_string(totalInsertion / TOTAL_TEST) << endl; 
	cout << "Merge average time: " <<  to_string(totalMerge / TOTAL_TEST) << endl; 

}

void runHashingTests(int arrayLength, int distribution, double uniqueness, int listOrder) {
	long totalHash1 = 0;
	long totalHashInsertSort1= 0;
	long totalHashMergeSort1= 0;

	long totalHash3 = 0;
	long totalHashInsertSort3 = 0;
	long totalHashMergeSort3 = 0;

	PrimeHashFunction hashFunc1;
	XorHashFunction hashFunc3;
	InsertionSort insertionSort;
	MergeSort mergeSort;

	for(int i=0; i < TOTAL_TEST; i++) {
		int** originalData = new int*[TOTAL_LIST_NUMBER];
		int** hashData1 = new int*[TOTAL_LIST_NUMBER];
		int** hashData2 = new int*[TOTAL_LIST_NUMBER];
		int** hashData3 = new int*[TOTAL_LIST_NUMBER];
		int** hashData4 = new int*[TOTAL_LIST_NUMBER];

		generateData(originalData, arrayLength, uniqueness, distribution, listOrder);

		copyMatrix(originalData, hashData1, arrayLength);
		copyMatrix(originalData, hashData2, arrayLength);
		copyMatrix(originalData, hashData3, arrayLength);
		copyMatrix(originalData, hashData4, arrayLength);

		// **** HASH 1 ****

		// ONLY HASHING
		auto start = std::chrono::high_resolution_clock::now();
		runHashMap(hashData1, hashFunc1, arrayLength);
		auto finish = std::chrono::high_resolution_clock::now();
		auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		// cout << "PrimeHashFunction " << i <<" time: " <<  int_ms.count() << endl;
		totalHash1 = totalHash1 + int_ms.count();


		// HASH SORT DINAMIC Intro
		start = std::chrono::high_resolution_clock::now();
		runHashSort(hashData1, hashFunc1, arrayLength, insertionSort, "HASH1Insert");
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalHashInsertSort1 = totalHashInsertSort1 + int_ms.count();

		// HASH SORT DINAMIC Merge
		start = std::chrono::high_resolution_clock::now();
		runHashSort(hashData2, hashFunc1, arrayLength, mergeSort,  "HASH1Merge");
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalHashMergeSort1 = totalHashMergeSort1 + int_ms.count();

		// **** HASH 3 ****

		// ONLY HASHING
		start = std::chrono::high_resolution_clock::now();
		runHashMap(hashData3, hashFunc3, arrayLength);
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalHash3 = totalHash3 + int_ms.count();


		// HASH SORT DINAMIC Intro
		start = std::chrono::high_resolution_clock::now();
		runHashSort(hashData3, hashFunc3, arrayLength, insertionSort,  "HASH2Insert");
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalHashInsertSort3 = totalHashInsertSort3 + int_ms.count();

		// HASH SORT DINAMIC Merge
		start = std::chrono::high_resolution_clock::now();
		runHashSort(hashData4, hashFunc3, arrayLength, mergeSort, "HASH2MErge");
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalHashMergeSort3 = totalHashMergeSort3 + int_ms.count();

		// printArray(2, originalData, arrayLength);
	}

	cout << "********************************************"<< endl; 
	cout << "Array_Length: "<< arrayLength << " Distribution: "<< distribution << " Uniq: "<< uniqueness <<  " Order: "<< listOrder <<endl; 
	cout << "********************************************"<< endl; 

	cout << "PrimeHashFunction average time: " <<  to_string(totalHash1 / TOTAL_TEST) << endl; 
	cout << "PrimeHashFunction HashSortInsert average time: " <<  to_string(totalHashInsertSort1 / TOTAL_TEST) << endl; 
	cout << "PrimeHashFunction HashSortMerge average time: " <<  to_string(totalHashMergeSort1 / TOTAL_TEST) << endl; 

	cout << "XorHashFunction average time: " <<  to_string(totalHash3 / TOTAL_TEST) << endl; 
	cout << "XorHashFunction HashSortInsert average time: " <<  to_string(totalHashInsertSort3 / TOTAL_TEST) << endl; 
	cout << "XorHashFunction HashSortMerge average time: " <<  to_string(totalHashMergeSort3 / TOTAL_TEST) << endl; 

}

int main (int argc,char* argv[]) {

	if(argc < 5) {
        printf("\nNeed to pass array length, distribution, uniqueness and list order as parameter"); 
        return 0;
	}

	int arrayLength = atoi(argv[1]);
	int distribution = atoi(argv[2]);
	double uniqueness = strtod(argv[3],NULL);
	int listOrder = atoi(argv[4]);

	srand (3141618);

	runSortingTests(arrayLength, distribution, uniqueness, listOrder);
	// runHashingTests(arrayLength, distribution, uniqueness, listOrder);
	return 0;
}



