//
//  MemoBlockOpt.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "MemoBlockOpt.hpp"
#include <string>

#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "MatrixGenerator.hpp"

#include "PairMultiplyShift.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string MemoBlockOpt::run(Configuration conf) {
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

void MemoBlockOpt::runSegmentedHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, int blockLength, double arrayRepetition){
    unordered_map<string, int> signaturesMap;
    unsigned short numberOfBlocksPerList = (arrayLength/blockLength);
    unsigned int totalBlocks = TOTAL_LIST_NUMBER * numberOfBlocksPerList;
    unsigned int totalUniqueBlocks = totalBlocks * arrayRepetition;
    
    int** uniqueBlocks = new int*[totalUniqueBlocks];
    signaturesMap.reserve(totalUniqueBlocks);

    
    // loop through each array, per block
    // if found copy ordered result of block
    // if not found, sort and save signature with block elsewerse
    //
    unsigned int segmentsIndex = 0;
    for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
        unsigned int orderedListsIndexes[numberOfBlocksPerList];
        unsigned int currentIndex = 0;
        
        // Generate array with all sorted unique blocks
        for(unsigned short j = 0; j < arrayLength; j = j + blockLength) {
            int tmpBlock[blockLength];
            
            // Copy block
            for(unsigned short k = 0; k < blockLength; k++) {
                tmpBlock[k] = data[i][j + k];
            }
            
            string signature = hashFunc.hash(tmpBlock, blockLength);
            unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
            
            if(signaturesMap.find(signature) == signaturesMap.end()) {
                sortFunction.sort(tmpBlock, blockLength);
                signaturesMap.insert(make_pair(signature, segmentsIndex));
    
                // Copy sorted block
                uniqueBlocks[segmentsIndex] = new int[blockLength];
                for(unsigned short k = 0; k < blockLength; k++) {
                    uniqueBlocks[segmentsIndex][k] = tmpBlock[k];
                }
                
                orderedListsIndexes[currentIndex] = segmentsIndex++;
            } else {
                unsigned int originalIndex = signatureFinder->second;
                orderedListsIndexes[currentIndex] = originalIndex;
            }
            
            currentIndex++;
        }

        // Merging all segments to data
        unsigned int blocksLastIndexUsed[numberOfBlocksPerList];
        for(unsigned short k = 0; k < numberOfBlocksPerList; k++) {
            blocksLastIndexUsed[k] = 0;
        }
        
        for(unsigned short j = 0; j < arrayLength; j++) {
            unsigned int minVal = INT_MAX;
            unsigned short usedBlock = 0;
            unsigned short usedElementIndex = 0;
            for(unsigned short k = 0; k < numberOfBlocksPerList; k++) {
                unsigned int uniqueBlockReferece = orderedListsIndexes[k];
                unsigned short lastElementIndex = blocksLastIndexUsed[k];
                
                int blockElement =  uniqueBlocks[uniqueBlockReferece][lastElementIndex];
                if(lastElementIndex < blockLength && minVal > blockElement) {
                    minVal = blockElement;
                    usedBlock = k;
                    usedElementIndex = lastElementIndex;
                }
            }
            
            blocksLastIndexUsed[usedBlock] = usedElementIndex + 1;
            data[i][j] = minVal;
        }
    }
}
