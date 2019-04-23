//
//  SortingTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "SortingTest.hpp"
#include <string>

#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "MatrixGenerator.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string SortingTest::run(Configuration conf) {
    long totalInsertion = 0;
    long totalMerge = 0;
    
    InsertionSort insertionSort;
    MergeSort mergeSort;
    MatrixGenerator dataGenerator;
    
    int** originalData = new int*[TOTAL_LIST_NUMBER];
    int** copiedData = new int*[TOTAL_LIST_NUMBER];
    
    dataGenerator.generateMatrix(originalData, conf.arrayLength, conf.uniqueness, conf.distribution, conf.listOrder, conf.copiedElements);
    
    if(conf.debug == 1) {
        printArray(1, originalData, conf.arrayLength);
    }
    
    dataGenerator.copyMatrix(originalData, copiedData, conf.arrayLength);
    
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    runSortFunction(originalData, conf.arrayLength, insertionSort);
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalInsertion = int_ms.count();
    
    
    start = std::chrono::high_resolution_clock::now();
    runSortFunction(copiedData, conf.arrayLength, mergeSort);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalMerge = int_ms.count();
        
    if(conf.debug == 1) {
        printArray(2, originalData, conf.arrayLength);
    }
    cout << "********************************************"<< endl;
    cout << conf.toString() <<endl;
    cout << "********************************************"<< endl;
    
    cout << "Insertion average time: " <<  to_string(totalInsertion) << endl;
    cout << "Merge average time: " <<  to_string(totalMerge) << endl;
    
    return "DONE";
}

void SortingTest::runSortFunction(int** data, int arrayLength, SortFunction& sortFunction){
    for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
        sortFunction.sort(data[j], arrayLength);
    }
}
