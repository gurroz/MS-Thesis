//
//  HashTableTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include "HashTableTest.hpp"
#include <string>

#include "MemoryUtil.cpp"
#include "MatrixGenerator.hpp"

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string HashTableTest::run(Configuration conf) {
    long totalMemoryUsed = MemoryUtil::getVirtualMemoryProcess();
    long memoryInsert = 0;
    bool resp = false;
    int totalLength = TOTAL_LIST_NUMBER * conf.uniqueness;
    unordered_map<string, int> signaturesMap;
    signaturesMap.reserve(totalLength);

    long totalInsertion = 0;
    long totalLookup = 0;
    for(int i = 0; i < totalLength ; i++) {
        string randomStr = to_string(rand()) + "-" +  to_string(rand());
        hi_res_time_point start = std::chrono::high_resolution_clock::now();
        signaturesMap.insert(make_pair(randomStr, 1));
        hi_res_time_point finish = std::chrono::high_resolution_clock::now();
        auto int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
        totalInsertion += int_ms.count();
        
        start = std::chrono::high_resolution_clock::now();
        resp = signaturesMap.find(randomStr) == signaturesMap.end();
        finish = std::chrono::high_resolution_clock::now();
        
        int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
        totalLookup += int_ms.count();
    }
    
    int** originalData = new int*[TOTAL_LIST_NUMBER];
    
    MatrixGenerator dataGenerator;
    dataGenerator.generateMatrix(originalData, conf.arrayLength, conf.uniqueness, conf.distribution, conf.listOrder, conf.copiedElements);
   
    long long dead = 0;
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < TOTAL_LIST_NUMBER ; i++) {
        for(int j = 0; j < conf.arrayLength ; j++) {
            dead += originalData[i][j];
        }
    }
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    long totalReading = int_ms.count();
    
//    long totalLookup = 0;
//    start = std::chrono::high_resolution_clock::now();
//    resp = signaturesMap.find(randomStr) == signaturesMap.end();
//    finish = std::chrono::high_resolution_clock::now();
//    auto int_msn = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//    totalLookup = int_msn.count();
//
    
//    int totalTest = 1024;
//    long* totalInsertion = new long[totalTest];
//    long* totalLookUp = new long[totalTest];
//
//    for(int i = 0; i < totalTest ; i++) {
//        string randomStr = to_string(rand()) + "-" +  to_string(rand());
//        start = std::chrono::high_resolution_clock::now();
//        signaturesMap.insert(make_pair(randomStr, 1));
//        finish = std::chrono::high_resolution_clock::now();
//        int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
//
//        totalInsertion[i] = int_ms.count();
//
//        start = std::chrono::high_resolution_clock::now();
//        resp = signaturesMap.find(randomStr) == signaturesMap.end();
//        finish = std::chrono::high_resolution_clock::now();
//        int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
//
//        totalLookUp[i] = int_ms.count();
//    }
    
    
    if(conf.memoryCheck == 1) {
        memoryInsert = MemoryUtil::getVirtualMemoryProcess() - totalMemoryUsed;
    }
    
//    for(int i = 0; i < totalTest ; i++) {
//        cout << to_string(totalInsertion[i]) << "," << to_string(totalLookUp[i]) << endl;
//    }
//
    
    cout << "Total Lookup: " << (totalLookup / 1000000) << endl;
    cout << "Total Insertion: " << (totalInsertion / 1000000) << endl;
    cout << "Total Reading: " << totalReading << endl;

    if(resp) {
        return "DONE";
    }
    return "DONE";
}
