#include "InsertionSort.hpp"

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