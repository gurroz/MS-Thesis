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

#include "PairMultiplyShift.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string SegmentedOptHashTest::run(Configuration conf) {
    InsertionSort insertionSort;
    MergeSort mergeSort;
    MatrixGenerator dataGenerator;
    PairMultiplyShift hashFunc1;
    
    int** originalData = new int*[TOTAL_LIST_NUMBER];
    int** copiedData1 = new int*[TOTAL_LIST_NUMBER];
    
    dataGenerator.generateSegmentedMatrix(originalData, conf.arrayLength, conf.listOrder, conf.copiedElements);
    dataGenerator.copyMatrix(originalData, copiedData1, conf.arrayLength);
    
    if(conf.debug == 1) {
        printArray(1, originalData, conf.arrayLength);
    }
    
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    runSegmentedHashSort(originalData, hashFunc1, conf.arrayLength, insertionSort, conf.blocksLength, conf.copiedElements);
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    long totalInsertionSeg = int_ms.count();
    
    start = std::chrono::high_resolution_clock::now();
    runSegmentedHashSort(copiedData1, hashFunc1, conf.arrayLength, mergeSort, conf.blocksLength, conf.copiedElements);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    long totalMergeSeg = int_ms.count();
    
    if(conf.debug == 1) {
        printArray(2, originalData, conf.arrayLength);
        printArray(3, copiedData1, conf.arrayLength);
    }
    
    cout << "********************************************"<< endl;
    cout << conf.toString() <<endl;
    cout << "********************************************"<< endl;
    
    cout << "InSeg: " <<  to_string(totalInsertionSeg)  << " MergSeg: " <<  to_string(totalMergeSeg)  << endl;
    
    return "DONE";
}

int SegmentedOptHashTest::runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength, double arrayRepetition){
    unordered_map<string, int> signaturesMap;
    int arraySegments = (arrayLength/blockLength);
    int totalSegmets = TOTAL_LIST_NUMBER * arraySegments;
    int hashTableLength = totalSegmets * arrayRepetition;
    
    int** segmentMatrix = new int*[totalSegmets];
    signaturesMap.reserve(hashTableLength);

    
    // loop through each array, per block
    // if found copy ordered result of block
    // if not found, sort and save signature with block elsewerse
    //
    int deadCodeReturn = 0;
    int segmentsIndex = 0;
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
        int orderedListsIndexes[arraySegments];
        int currentIndex = 0;
        
        // Generate array with all sorted unique blocks
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
                
                orderedListsIndexes[currentIndex] = segmentsIndex;
            } else {
                int originalIndex = signatureFinder->second;
                orderedListsIndexes[currentIndex] = originalIndex;
            }
            
            segmentsIndex++;
            currentIndex++;
        }
        // 2 way merge
        int tmpMerge[arrayLength];
        for(int k = 0; k < arrayLength; k++) {
            tmpMerge[k] = INT_MAX;
        }
        
        for(int j = 0; j < arraySegments; j++) { // For each block
            int secondTmpMerge[arrayLength];
            for(int k = 0; k < arrayLength; k++) {
                secondTmpMerge[k] = INT_MAX;
            }
            int segmentsIndex = orderedListsIndexes[j];

            // Merge block with current tmp array
            int currentSegmentIndex = 0;
            int currentDataIndex = 0;
            int globalIndex = 0;
            while(currentDataIndex < arrayLength || currentSegmentIndex < blockLength) {
                if(currentDataIndex < arrayLength && currentSegmentIndex < blockLength) {
                    if(tmpMerge[currentDataIndex] < segmentMatrix[segmentsIndex][currentSegmentIndex]) {
                        secondTmpMerge[globalIndex++] = tmpMerge[currentDataIndex++];
                    } else {
                        secondTmpMerge[globalIndex++] = segmentMatrix[segmentsIndex][currentSegmentIndex++];
                    }
                } else if(currentDataIndex == arrayLength) {
                    secondTmpMerge[globalIndex++] = segmentMatrix[segmentsIndex][currentSegmentIndex++];
                } else if(currentSegmentIndex == blockLength) {
                    secondTmpMerge[globalIndex++] = tmpMerge[currentDataIndex++];
                }
            }

            for(int k = 0; k < arrayLength; k++) { //Copies current order for next merge
                tmpMerge[k] = secondTmpMerge[k];
            }
        }

        for(int k = 0; k < arrayLength; k++) { // Copies final list
           data[i][k] = tmpMerge[k];
        }
    }
    return deadCodeReturn;
}
