//
//  SegmentedOptHashTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "SegmentedOptHashTest.hpp"
#include <string>

#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "MatrixGenerator.hpp"

#include "PrimeHashFunction.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string SegmentedOptHashTest::run(Configuration conf) {
    long totalInsertion = 0;
    long totalMerge = 0;
    long totalInsertionSeg = 0;
    long totalMergeSeg = 0;
    
    InsertionSort insertionSort;
    MergeSort mergeSort;
    MatrixGenerator dataGenerator;
    PrimeHashFunction hashFunc1;
    
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
    runSegmentedHashSort(copiedData2, hashFunc1, conf.arrayLength, insertionSort, conf.blocksLength);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalInsertionSeg = totalInsertionSeg + int_ms.count();
    
    
    start = std::chrono::high_resolution_clock::now();
    runSegmentedHashSort(copiedData3, hashFunc1, conf.arrayLength, mergeSort, conf.blocksLength);
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
    
    cout << "Insertion average time: " <<  to_string(totalInsertion) << endl;
    cout << "Merge average time: " <<  to_string(totalMerge) << endl;
    cout << "InsertionSegmeted average time: " <<  to_string(totalInsertionSeg) << endl;
    cout << "MergeSegmented average time: " <<  to_string(totalMergeSeg) << endl;
    
    return "DONE";
}

int SegmentedOptHashTest::runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength){
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

void SegmentedOptHashTest::runSortFunction(int** data, int arrayLength, SortFunction& sortFunction){
    for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
        sortFunction.sort(data[j], arrayLength);
    }
}
