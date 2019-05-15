//
//  HashTest.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 23/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//
#include <string>

#include "HashTest.hpp"
#include "MatrixGenerator.hpp"

#include "PrimeHashFunction.hpp"
#include "BenchHash.hpp"
#include "PolinomialHashFunction.hpp"
#include "CriptoHashFunction.hpp"
#include "PairMultiplyShift.hpp"
#include "MemoryUtil.cpp"


using namespace std;
using hi_res_time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;

string HashTest::run(Configuration conf) {
    long totalhashFunc1 = 0;
    long totalhashFunc2 = 0;
    long totalhashFunc3 = 0;
    long totalhashFunc4 = 0;

    long memoryhashFunc1 = 0;
    long memoryhashFunc2 = 0;
    long memoryhashFunc3 = 0;
    long memoryhashFunc4 = 0;
    
    long colissionhashFunc1 = 0;
    long colissionhashFunc2 = 0;
    long colissionhashFunc3 = 0;
    long colissionhashFunc4 = 0;
    
    MatrixGenerator dataGenerator;
    
    PrimeHashFunction hashFunc1;
    BenchHash hashFunc2;
    CriptoHashFunction hashFunc3;
//    PolinomialHashFunction hashFunc4;
    PairMultiplyShift hashFunc4;

    long totalMemoryUsed = MemoryUtil::getVirtualMemoryProcess();
    
    int** originalData = new int*[TOTAL_LIST_NUMBER];
    dataGenerator.generateMatrix(originalData, conf.arrayLength, conf.uniqueness, conf.distribution, conf.listOrder, conf.copiedElements);

    if(conf.debug == 1) {
        printArray(1, originalData, conf.arrayLength);
    }
    
    hi_res_time_point start = std::chrono::high_resolution_clock::now();
    runHash("hashFunc1", originalData, hashFunc1, conf.arrayLength);
    hi_res_time_point finish = std::chrono::high_resolution_clock::now();
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalhashFunc1 = int_ms.count();
    
    if(conf.memoryCheck == 1) {
        memoryhashFunc1 = MemoryUtil::getVirtualMemoryProcess() - totalMemoryUsed;
    }
    
    colissionhashFunc1 = checkColitions(originalData, hashFunc1, conf.arrayLength);
    
    start = std::chrono::high_resolution_clock::now();
    runHash("hashFunc2",originalData, hashFunc2, conf.arrayLength);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalhashFunc2 = int_ms.count();
    
    if(conf.memoryCheck == 1) {
        memoryhashFunc2 = MemoryUtil::getVirtualMemoryProcess() - memoryhashFunc1;
    }

    colissionhashFunc2 = checkColitions(originalData, hashFunc2, conf.arrayLength);
    
    start = std::chrono::high_resolution_clock::now();
    runHash("hashFunc3",originalData, hashFunc3, conf.arrayLength);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalhashFunc3 = int_ms.count();
    
    if(conf.memoryCheck == 1) {
        memoryhashFunc3 = MemoryUtil::getVirtualMemoryProcess() - memoryhashFunc2;
    }
    colissionhashFunc3 = checkColitions(originalData, hashFunc3, conf.arrayLength);
    
    start = std::chrono::high_resolution_clock::now();
    runHash("hashFunc4",originalData, hashFunc4, conf.arrayLength);
    finish = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
    totalhashFunc4 = int_ms.count();
    
    if(conf.memoryCheck == 1) {
        memoryhashFunc4 = MemoryUtil::getVirtualMemoryProcess() - memoryhashFunc3;
    }
    colissionhashFunc4 = checkColitions(originalData, hashFunc4, conf.arrayLength);
    
    cout << "********************************************"<< endl;
    cout << conf.toString() <<endl;
    cout << "********************************************"<< endl;
    
    cout << "H1: " <<  to_string(totalhashFunc1) << ", H2: " <<  to_string(totalhashFunc2) << ", H3: " <<  to_string(totalhashFunc3) << ", H4: " <<  to_string(totalhashFunc4) << endl;
    cout << "C1: " <<  to_string(colissionhashFunc1) << ", C2: " <<  to_string(colissionhashFunc2) << ", C3: " <<  to_string(colissionhashFunc3) << ", C4: " <<  to_string(colissionhashFunc4) << endl;
    cout << "M1: " <<  to_string(memoryhashFunc1) << ", M2: " <<  to_string(memoryhashFunc2) << ", M3: " <<  to_string(memoryhashFunc3) << ", M4: " <<  to_string(memoryhashFunc4) << endl;
    
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

void HashTest::runHash(string name, int** data, HashFunction& hashFunc, int arrayLength) {
    string signature = "";
    for(int j = 0; j < TOTAL_LIST_NUMBER; j++) {
        signature = hashFunc.hash(data[j], arrayLength);
//        cout << name << "SIG: " <<  signature << endl;
    }
}
