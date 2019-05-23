//
//  SegmentedNaiveTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "SegmentedNaiveTest.hpp"
#include <string>

#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "MatrixGenerator.hpp"

#include "BenchHash.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string SegmentedNaiveTest::run(Configuration conf) {
    long totalInsertion = 0;
    long totalMerge = 0;
    long totalInsertionSeg = 0;
    long totalMergeSeg = 0;
    
    InsertionSort insertionSort;
    MergeSort mergeSort;
    MatrixGenerator dataGenerator;
    BenchHash hashFunc1;
    
    int** originalData = new int*[TOTAL_LIST_NUMBER];
    int** copiedData1 = new int*[TOTAL_LIST_NUMBER];
    int** copiedData2 = new int*[TOTAL_LIST_NUMBER];
    int** copiedData3 = new int*[TOTAL_LIST_NUMBER];
    
    dataGenerator.generateSegmentedMatrix(originalData, conf.arrayLength, conf.listOrder, conf.copiedElements);
    dataGenerator.copyMatrix(originalData, copiedData1, conf.arrayLength);
    dataGenerator.copyMatrix(originalData, copiedData2, conf.arrayLength);
    dataGenerator.copyMatrix(originalData, copiedData3, conf.arrayLength);
    
    if(conf.debug == 1) {
        printArray(1, originalData, conf.arrayLength);
    }
    
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    runSortFunction(originalData, conf.arrayLength, insertionSort);
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalInsertion = totalInsertion + int_ms.count();
    
    start = std::chrono::high_resolution_clock::now();
    runSortFunction(copiedData1, conf.arrayLength, mergeSort);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalMerge = totalMerge + int_ms.count();
    
    start = std::chrono::high_resolution_clock::now();
    runSegmentedHashSort(copiedData2, hashFunc1, conf.arrayLength, insertionSort, conf.blocksLength, conf.copiedElements);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalInsertionSeg = totalInsertionSeg + int_ms.count();
    
    start = std::chrono::high_resolution_clock::now();
    runSegmentedHashSort(copiedData3, hashFunc1, conf.arrayLength, mergeSort, conf.blocksLength, conf.copiedElements);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalMergeSeg = totalMergeSeg + int_ms.count();
    
    if(conf.debug == 1) {
        printArray(2, copiedData1, conf.arrayLength);
        printArray(3, copiedData2, conf.arrayLength);
    }
    
    cout << "********************************************"<< endl;
    cout << conf.toString() <<endl;
    cout << "********************************************"<< endl;
    
    cout << "InSort: " <<  to_string(totalInsertion) << " MerSort: " <<  to_string(totalMerge) << " InSeg: " <<  to_string(totalInsertionSeg)  << " MergSeg: " <<  to_string(totalMergeSeg)  << endl;
    
    return "DONE";
}

int SegmentedNaiveTest::runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength, double arrayRepetition) {
    unordered_map<string, int> signaturesMap;
    
    int arraySegments = (arrayLength/blockLength);
    int totalSegmets = TOTAL_LIST_NUMBER *  arraySegments;
    int hashTableLength = totalSegmets *  arrayRepetition;

    int** segmentMatrix = new int*[totalSegmets];
    
    signaturesMap.reserve(hashTableLength);

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

void SegmentedNaiveTest::runSortFunction(int** data, int arrayLength, SortFunction& sortFunction){
    for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
        sortFunction.sort(data[j], arrayLength);
    }
}
