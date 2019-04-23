//
//  HashingSortTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "HashingSortTest.hpp"
#include <string>

#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "MatrixGenerator.hpp"

#include "PrimeHashFunction.hpp"


using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;

string HashingSortTest::run(Configuration conf) {
    long totalHash = 0;
    long totalHashInsertSort = 0;
    long totalHashMergeSort = 0;
    
    PrimeHashFunction hashFunc;
//    XorHashFunction hashFunc3;
    
    InsertionSort insertionSort;
    MergeSort mergeSort;
    MatrixGenerator dataGenerator;
    
    int** originalData = new int*[TOTAL_LIST_NUMBER];
    int** hashData1 = new int*[TOTAL_LIST_NUMBER];
    int** hashData2 = new int*[TOTAL_LIST_NUMBER];
    
    dataGenerator.generateMatrix(originalData, conf.arrayLength, conf.uniqueness, conf.distribution, conf.listOrder, 0);
    
    dataGenerator.copyMatrix(originalData, hashData1, conf.arrayLength);
    dataGenerator.copyMatrix(originalData, hashData2, conf.arrayLength);
    
    if(conf.debug == 1) {
        printArray(1, hashData1, conf.arrayLength);
    }
    
    // **** HASH 1 ****
    
    // ONLY HASHING
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    runHashMap(hashData1, hashFunc, conf.arrayLength);
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalHash = int_ms.count();
    
    
    // HASH SORT DINAMIC Intro
    start = std::chrono::high_resolution_clock::now();
    runHashSort(hashData1, hashFunc, conf.arrayLength, insertionSort, "HASH1Insert");
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalHashInsertSort = int_ms.count();
    
    // HASH SORT DINAMIC Merge
    start = std::chrono::high_resolution_clock::now();
    runHashSort(hashData2, hashFunc, conf.arrayLength, mergeSort,  "HASH1Merge");
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalHashMergeSort = int_ms.count();
    
        
    if(conf.debug == 1) {
        printArray(2, hashData1, conf.arrayLength);
    }
    
    cout << "********************************************"<< endl;
    cout << conf.toString() <<endl;
    cout << "********************************************"<< endl;
    
    cout << "PrimeHashFunction average time: " <<  to_string(totalHash) << endl;
    cout << "PrimeHashFunction HashSortInsert average time: " <<  to_string(totalHashInsertSort) << endl;
    cout << "PrimeHashFunction HashSortMerge average time: " <<  to_string(totalHashMergeSort) << endl;
    
    
    return "DONE";
}

int HashingSortTest::runHashSort(int** data, HashFunction& hashFunc, int arrayLength, SortFunction& sortFunction, string name) {
    unordered_map<string, int> signaturesMap;
    
    int deadCodeReturn = 0;
    for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
        string signature = hashFunc.hash(data[j], arrayLength);
        
        if(signaturesMap.find(signature) == signaturesMap.end()) {
            sortFunction.sort(data[j], arrayLength);
            signaturesMap.insert(make_pair(signature, 1));
        }
    }
    return deadCodeReturn;
}


int HashingSortTest::runHashMap(int** data, HashFunction& hashFunc, int arrayLength) {
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
