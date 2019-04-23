//
//  HashTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "HashTest.hpp"
#include <string>

#include "MatrixGenerator.hpp"
#include "PrimeHashFunction.hpp"
#include "XorHashFunction.hpp"
#include "AdditiveHashFunction.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string HashTest::run(Configuration conf) {
    long totalInsertion = 0;
    long totalMerge = 0;
    long totalInsertionSeg = 0;
    long totalMergeSeg = 0;
    
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
    
//    hi_res_time_point start = std::chrono::high_resolution_clock::now();
//    runSortFunction(originalData, conf.arrayLength, insertionSort);
//    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
//    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//    totalInsertion = totalInsertion + int_ms.count();
//
//
//    start = std::chrono::high_resolution_clock::now();
//    runSortFunction(copiedData1, conf.arrayLength, mergeSort);
//    finish = std::chrono::high_resolution_clock::now();
//    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//    totalMerge = totalMerge + int_ms.count();
//
//    start = std::chrono::high_resolution_clock::now();
//    runSegmentedHashSort(copiedData2, hashFunc1, conf.arrayLength, insertionSort, conf.blocksLength);
//    finish = std::chrono::high_resolution_clock::now();
//    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//    totalInsertionSeg = totalInsertionSeg + int_ms.count();
//
//
//    start = std::chrono::high_resolution_clock::now();
//    runSegmentedHashSort(copiedData3, hashFunc1, conf.arrayLength, mergeSort, conf.blocksLength);
//    finish = std::chrono::high_resolution_clock::now();
//    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//    totalMergeSeg = totalMergeSeg + int_ms.count();
//
//    if(conf.debug == 1) {
//        printArray(2, copiedData1, conf.arrayLength);
//        printArray(3, copiedData2, conf.arrayLength);
//    }
    
    cout << "********************************************"<< endl;
    cout << conf.toString() <<endl;
    cout << "********************************************"<< endl;
    
    cout << "Insertion average time: " <<  to_string(totalInsertion) << endl;
    cout << "Merge average time: " <<  to_string(totalMerge) << endl;
    cout << "InsertionSegmeted average time: " <<  to_string(totalInsertionSeg) << endl;
    cout << "MergeSegmented average time: " <<  to_string(totalMergeSeg) << endl;
    
    return "DONE";
}

int HashTest::checkColitions(int** data, HashFunction& hashFunc, int arrayLength) {
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
