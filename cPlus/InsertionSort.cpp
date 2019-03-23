#include "InsertionSort.hpp"
#include <iostream>

void InsertionSort::sort(int list[], int length) {
	int value;
	int i, j;
	for(i = 1; i < length; i++) {
	    value = list[i];
	    j = i-1;

	    while (j >= 0 && list[j] > value) {
	        list[j+1] = list[j];
	        j = j-1;
	    }
	    list[j+1] = value;
	}
}

int InsertionSort::optimizedSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex) {
	int value;
	int i, j;

	long hashVal = 17;

	for(i = 1; i < length; i++) {
	    value = list[i];
	    hashVal = hashVal * 19 + value;

	    if(i == length - 1) { // means all elements checked. Perform hash check
	    	string signature = to_string(hashVal);


			unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
        	if(signatureFinder == signaturesMap.end()) {
				signaturesMap.insert(make_pair(signature, actualIndex));
				// cout << "Inserting into insert HashTable: "<< signature << " " << actualIndex << endl; 

	    	} else {
				int originalIndex = signatureFinder->second;
				return originalIndex;
			}
		}

	    j = i-1;

	    while (j >= 0 && list[j] > value) {
	        list[j+1] = list[j];
	        j = j-1;
	    }
	    list[j+1] = value;
	}

	return -1;
}