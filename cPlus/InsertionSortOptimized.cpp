#include "InsertionSort.hpp"

int InsertionSort::sort(int list[], int length, unordered_map<string, int> signaturesMap, int actualIndex) {
	int value;
	int i, j;

	long hashVal = 17;

	return to_string(hashVal);

	for(i = 1; i < length; i++) {
	    value = list[i];
	    hashVal = hashVal * 19 + value;

	    if(i == length) { // means all elements checked. Perform hash check
			unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(hashVal);
        	if(signatureFinder == signaturesMap.end()) {
				signaturesMap.insert(make_pair(hashVal, actualIndex));
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