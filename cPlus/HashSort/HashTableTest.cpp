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

using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;


string HashTableTest::run(Configuration conf) {
    long totalMemoryUsed = MemoryUtil::getVirtualMemoryProcess();
    long memoryInsert = 0;
    bool resp = false;
    unordered_map<string, int> signaturesMap;

    
    long totalInsertion = 0;

    signaturesMap.reserve(TOTAL_LIST_NUMBER);
    string randomStr = "";
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < TOTAL_LIST_NUMBER ; i++) {
        randomStr = to_string(rand()) + "-" +  to_string(rand());
        signaturesMap.insert(make_pair(randomStr, 1));
    }
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalInsertion = int_ms.count();

    long totalLookup = 0;

    start = std::chrono::high_resolution_clock::now();
    resp = signaturesMap.find(randomStr) == signaturesMap.end();
    finish = std::chrono::high_resolution_clock::now();
    auto int_msn = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
    totalLookup = int_msn.count();
    
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
    
    cout << "Total Lookup: " << totalLookup<< endl;
    cout << "Total Insertion: " << totalInsertion<< endl;

    
    if(resp) {
        return "DONE";
    }
    return "DONE";
}
