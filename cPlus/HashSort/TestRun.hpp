#ifndef TEST_RUN_H
#define TEST_RUN_H

#include <string>
#include <iostream>

#include "Configuration.hpp"

using namespace std;


class TestRun {
	public:
		virtual string run(Configuration conf) = 0;
    
        void printArray(int run, int** originalData, int arrayLength) {
            for(int i = 0; i < TOTAL_LIST_NUMBER; i++) {
                int* currentArr = originalData[i];
                
                string arrayList = "";
                for(int j = 0; j < arrayLength; j++) {
                    arrayList = arrayList + std::to_string(currentArr[j]);
                    arrayList = arrayList + ",";
                }
                cout << "Array_" <<  run  <<  ": " <<  arrayList << endl;
            }
        }
        
};
#endif
