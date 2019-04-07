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
#include "MatrixGenerator.hpp"
#include "HashFunction.hpp"
#include "AdditiveHashFunction.hpp"
#include "PrimeHashFunction.hpp"
#include "XorHashFunction.hpp"
#include "MinHeap.hpp"


using namespace std;
#define TOTAL_TEST 1

void runSortFunction(int** data, int arrayLength, SortFunction& sortFunction){
	for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
		sortFunction.sort(data[j], arrayLength);
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

void runSortOptimizedFunction(int** data, int arrayLength, SortFunction& sortFunction){
	unordered_map<string, int> signaturesMap;

	for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
		int index = sortFunction.optimizedSort(data[j], arrayLength, signaturesMap, j);
		if(index > 0) {
             cout << "Found Sorted before:"<< index << endl;
		}
	}
}

void runSortingTests(int arrayLength, int distribution, double uniqueness, int listOrder,double copiedElements) {
	long totalInsertion = 0;
	long totalMerge = 0;

	InsertionSort insertionSort;
	MergeSort mergeSort;
    MatrixGenerator dataGenerator;

	for(int i=0; i < TOTAL_TEST; i++) {
		int** originalData = new int*[TOTAL_LIST_NUMBER];
		int** copiedData = new int*[TOTAL_LIST_NUMBER];
		
        dataGenerator.generateMatrix(originalData, arrayLength, uniqueness, distribution, listOrder, copiedElements);

//        printArray(1, originalData, arrayLength);

		dataGenerator.copyMatrix(originalData, copiedData, arrayLength);


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
        
        printArray(2, originalData, arrayLength);
	}

	cout << "********************************************"<< endl; 
	cout << "Array_Length: "<< arrayLength << " Distribution: "<< distribution << " Uniq: "<< uniqueness <<  " Order: "<< listOrder <<endl; 
	cout << "********************************************"<< endl; 

	cout << "Insertion average time: " <<  to_string(totalInsertion / TOTAL_TEST) << endl; 
	cout << "Merge average time: " <<  to_string(totalMerge / TOTAL_TEST) << endl; 

}

void runSortingOptimizedTests(int arrayLength, int distribution, double uniqueness, int listOrder, double copiedElements) {
	long totalInsertion = 0;
    long totalInsertionOpt = 0;
	long totalMerge = 0;

	InsertionSort insertionSort;
	MergeSort mergeSort;
    MatrixGenerator dataGenerator;

	for(int i=0; i < TOTAL_TEST; i++) {
		int** originalData = new int*[TOTAL_LIST_NUMBER];
		int** copiedData1 = new int*[TOTAL_LIST_NUMBER];
        int** copiedData2 = new int*[TOTAL_LIST_NUMBER];
		
        dataGenerator.generateMatrix(originalData, arrayLength, uniqueness, distribution, listOrder, copiedElements);
		dataGenerator.copyMatrix(originalData, copiedData1, arrayLength);
        dataGenerator.copyMatrix(originalData, copiedData2, arrayLength);

		
//        printArray(1, originalData, arrayLength);
        auto start = std::chrono::high_resolution_clock::now();
        runSortFunction(originalData, arrayLength, insertionSort);
        auto finish = std::chrono::high_resolution_clock::now();
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        totalInsertion = totalInsertion + int_ms.count();
        
        start = std::chrono::high_resolution_clock::now();
		runSortOptimizedFunction(copiedData1, arrayLength, insertionSort);
        finish = std::chrono::high_resolution_clock::now();
        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalInsertionOpt = totalInsertionOpt + int_ms.count();


		start = std::chrono::high_resolution_clock::now();
		runSortOptimizedFunction(copiedData2, arrayLength, mergeSort);
		finish = std::chrono::high_resolution_clock::now();
		int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
		totalMerge = totalMerge + int_ms.count();

//         printArray(2, copiedData1, arrayLength);
//         printArray(3, copiedData2, arrayLength);
	}

	cout << "********************************************"<< endl; 
	cout << "Array_Length: "<< arrayLength << " Distribution: "<< distribution << " Uniq: "<< uniqueness <<  " Order: "<< listOrder <<endl; 
	cout << "********************************************"<< endl; 

	cout << "Insertion average time: " <<  to_string(totalInsertion / TOTAL_TEST) << endl;
    cout << "InsertionOptimized average time: " <<  to_string(totalInsertionOpt / TOTAL_TEST) << endl;
	cout << "MergeOptimized average time: " <<  to_string(totalMerge / TOTAL_TEST) << endl;
}

int runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength) {
    unordered_map<string, int> signaturesMap;
    int arraySegments = (arrayLength/blockLength);
    int totalSegmets = TOTAL_LIST_NUMBER *  arraySegments;
    int** segmentMatrix = new int*[totalSegmets];
    
    // loop through each array, per block
    // if found copy ordered result of block
    // if not found, sort and save signature with block elsewerse
    //
    int deadCodeReturn = 0;
    int segmentsIndex = 0;
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
        int indexes[arraySegments];
        int currentIndex = 0;
        for(int j = 0; j < arrayLength; j = j + blockLength) {
            segmentMatrix[segmentsIndex] = new int[blockLength];

            // Copy block
            for(int k = 0; k < blockLength; k++) {
                segmentMatrix[segmentsIndex][k] = data[i][j + k];
            }
            
            string signature = hashFunc.hash(segmentMatrix[segmentsIndex], blockLength);
            unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);

            if(signaturesMap.find(signature) == signaturesMap.end()) {
                sortFunction.sort(segmentMatrix[segmentsIndex], blockLength);
                signaturesMap.insert(make_pair(signature, segmentsIndex));
                
                indexes[currentIndex] = segmentsIndex;
            } else {
                int originalIndex = signatureFinder->second;
                indexes[currentIndex] = originalIndex;
            }
            
            segmentsIndex++;
            currentIndex++;
        }
        
        // Merging all segments to data
        int segmentsLastIndex[arraySegments];
        for(int k = 0; k < arraySegments; k++) {
            segmentsLastIndex[k] = 0;
        }
        
        for(int lastDataIndex = 0; lastDataIndex < arrayLength; lastDataIndex++) {
            int minVal = INT_MAX;
            int usedSegment = 0;
            for(int k = 0; k < arraySegments; k++) {
                int segmentsIndex = indexes[k];
                int lastIndex = segmentsLastIndex[k];
                
                if(lastIndex < blockLength && minVal > segmentMatrix[segmentsIndex][lastIndex]) {
                    minVal = segmentMatrix[segmentsIndex][lastIndex];
                    usedSegment = k;
                }
            }
            
            segmentsLastIndex[usedSegment] = segmentsLastIndex[usedSegment] + 1;
            data[i][lastDataIndex] = minVal;
        }
    
    }
    
    return deadCodeReturn;
}

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
public int *mergeKArrays(int** arr, int n, int k) {
    int *output = new int[n*k]; // To store output array
    
    // Create a min heap with k heap nodes. Every heap node
    // has first element of an array
    MinHeapNode *harr = new MinHeapNode[k];
    for (int i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0]; // Store the first element
        harr[i].i = i; // index of array
        harr[i].j = 1; // Index of next element to be stored from array
    }
    MinHeap hp(harr, k); // Create the heap
    
    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    for (int count = 0; count < n*k; count++)
    {
        // Get the minimum element and store it in output
        MinHeapNode root = hp.getMin();
        output[count] = root.element;
        
        // Find the next elelement that will replace current
        // root of heap. The next element belongs to same
        // array as the current root.
        if (root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        // If root was the last element of its array
        else root.element = INT_MAX; //INT_MAX is for infinite
        
        // Replace root with next element of array
        hp.replaceMin(root);
    }
    
    return output;
}

int runSegmentedHeapHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength) {
    unordered_map<string, int> signaturesMap;
    int arraySegments = (arrayLength/blockLength);
    int totalSegmets = TOTAL_LIST_NUMBER *  arraySegments;
    int** segmentMatrix = new int*[totalSegmets];
    
    // loop through each array, per block
    // if found copy ordered result of block
    // if not found, sort and save signature with block elsewerse
    //
    int deadCodeReturn = 0;
    int segmentsIndex = 0;
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
        int indexes[arraySegments];
        int currentIndex = 0;
        for(int j = 0; j < arrayLength; j = j + blockLength) {
            segmentMatrix[segmentsIndex] = new int[blockLength];
            
            // Copy block
            for(int k = 0; k < blockLength; k++) {
                segmentMatrix[segmentsIndex][k] = data[i][j + k];
            }
            
            string signature = hashFunc.hash(segmentMatrix[segmentsIndex], blockLength);
            unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
            
            if(signaturesMap.find(signature) == signaturesMap.end()) {
                sortFunction.sort(segmentMatrix[segmentsIndex], blockLength);
                signaturesMap.insert(make_pair(signature, segmentsIndex));
                
                indexes[currentIndex] = segmentsIndex;
            } else {
                int originalIndex = signatureFinder->second;
                indexes[currentIndex] = originalIndex;
            }
            
            segmentsIndex++;
            currentIndex++;
        }
        
        // Merging all segments to data
        data[i] = mergeKArrays(, arraySegments);
    }
    
    return deadCodeReturn;
}

int runSegmentedHashSortNaive(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength) {
    unordered_map<string, int> signaturesMap;
    int arraySegments = (arrayLength/blockLength);
    int totalSegmets = TOTAL_LIST_NUMBER *  arraySegments;
    int** segmentMatrix = new int*[totalSegmets];
    
    // loop through each array, per block
    // if found copy ordered result of block
    // if not found, sort and save signature with block elsewerse
    //
    int deadCodeReturn = 0;
    int segmentsIndex = 0;
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
        //        int indexes[arraySegments];
        //        int currentIndex = 0;
        for(int j = 0; j < arrayLength; j = j + blockLength) {
            segmentMatrix[segmentsIndex] = new int[blockLength];

            // Copy block
            for(int k = 0; k < blockLength; k++) {
                segmentMatrix[segmentsIndex][k] = data[i][j + k];
            }
            
            string signature = hashFunc.hash(segmentMatrix[segmentsIndex], blockLength);
            unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
            
            if(signaturesMap.find(signature) == signaturesMap.end()) {
                sortFunction.sort(segmentMatrix[segmentsIndex], blockLength);
                signaturesMap.insert(make_pair(signature, segmentsIndex));
            } else {
                int originalIndex = signatureFinder->second;
                for(int k = 0;  k < blockLength; k++) {
                    data[i][j + k] = segmentMatrix[originalIndex][k];
                }
            }
            
            segmentsIndex++;
        }
        
        sortFunction.sort(data[i], arrayLength);
    }
    
    return deadCodeReturn;
}

void runSegmentedTests(int arrayLength, int distribution, double uniqueness, int listOrder, double copiedElements, int blocksLength) {
    long totalInsertion = 0;
    long totalMerge = 0;
    long totalInsertionSeg = 0;
    long totalMergeSeg = 0;
    
    InsertionSort insertionSort;
    MergeSort mergeSort;
    MatrixGenerator dataGenerator;
    PrimeHashFunction hashFunc1;
    for(int i=0; i < TOTAL_TEST; i++) {
        int** originalData = new int*[TOTAL_LIST_NUMBER];
        int** copiedData1 = new int*[TOTAL_LIST_NUMBER];
        int** copiedData2 = new int*[TOTAL_LIST_NUMBER];
        int** copiedData3 = new int*[TOTAL_LIST_NUMBER];
        
        dataGenerator.generateSegmentedMatrix(originalData, arrayLength, listOrder, copiedElements);
        dataGenerator.copyMatrix(originalData, copiedData1, arrayLength);
        dataGenerator.copyMatrix(originalData, copiedData2, arrayLength);
        dataGenerator.copyMatrix(originalData, copiedData3, arrayLength);
        
//        printArray(1, originalData, arrayLength);
        
        auto start = std::chrono::high_resolution_clock::now();
        runSortFunction(originalData, arrayLength, insertionSort);
        auto finish = std::chrono::high_resolution_clock::now();
        auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        totalInsertion = totalInsertion + int_ms.count();
        
        
        start = std::chrono::high_resolution_clock::now();
        runSortFunction(copiedData1, arrayLength, mergeSort);
        finish = std::chrono::high_resolution_clock::now();
        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        totalMerge = totalMerge + int_ms.count();
        
        start = std::chrono::high_resolution_clock::now();
        runSegmentedHashSort(copiedData2, hashFunc1, arrayLength, insertionSort, blocksLength);
        finish = std::chrono::high_resolution_clock::now();
        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        totalInsertionSeg = totalInsertionSeg + int_ms.count();
        
        
        start = std::chrono::high_resolution_clock::now();
        runSegmentedHashSort(copiedData3, hashFunc1, arrayLength, mergeSort, blocksLength);
        finish = std::chrono::high_resolution_clock::now();
        int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        totalMergeSeg = totalMergeSeg + int_ms.count();
        
//        printArray(2, copiedData1, arrayLength);
        //         printArray(3, copiedData2, arrayLength);
    }
    
    cout << "********************************************"<< endl;
    cout << "Array_Length: "<< arrayLength << " Distribution: "<< distribution << " Block: "<< blocksLength <<  " Order: "<< listOrder <<  " CopiedBlocks: "<< copiedElements << endl;
    
    cout << "********************************************"<< endl;
    cout << "Insertion average time: " <<  to_string(totalInsertion / TOTAL_TEST) << endl;
    cout << "Merge average time: " <<  to_string(totalMerge / TOTAL_TEST) << endl;
    cout << "InsertionSegmeted average time: " <<  to_string(totalInsertionSeg / TOTAL_TEST) << endl;
    cout << "MergeSegmented average time: " <<  to_string(totalMergeSeg / TOTAL_TEST) << endl;
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
    MatrixGenerator dataGenerator;

	for(int i=0; i < TOTAL_TEST; i++) {
		int** originalData = new int*[TOTAL_LIST_NUMBER];
		int** hashData1 = new int*[TOTAL_LIST_NUMBER];
		int** hashData2 = new int*[TOTAL_LIST_NUMBER];
		int** hashData3 = new int*[TOTAL_LIST_NUMBER];
		int** hashData4 = new int*[TOTAL_LIST_NUMBER];

		dataGenerator.generateMatrix(originalData, arrayLength, uniqueness, distribution, listOrder,0);

		dataGenerator.copyMatrix(originalData, hashData1, arrayLength);
		dataGenerator.copyMatrix(originalData, hashData2, arrayLength);
		dataGenerator.copyMatrix(originalData, hashData3, arrayLength);
		dataGenerator.copyMatrix(originalData, hashData4, arrayLength);

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

	if(argc < 7) {
        printf("\nNeed to pass array length, distribution, uniqueness, list order, amount of copied elements as parameter and block to read");
        return 0;
	}

	int arrayLength = atoi(argv[1]);
	int distribution = atoi(argv[2]);
	double uniqueness = strtod(argv[3],NULL);
	int listOrder = atoi(argv[4]);
	double copiedElements = strtod(argv[5],NULL);
    int blocksLength = atoi(argv[6]);


	srand (3141618);

//    runSortingOptimizedTests(arrayLength, distribution, uniqueness, listOrder, copiedElements);
     runSegmentedTests(arrayLength, distribution, uniqueness, listOrder, copiedElements, blocksLength);
	// runHashingTests(arrayLength, distribution, uniqueness, listOrder);
	return 0;
}



