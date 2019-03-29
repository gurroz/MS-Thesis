#ifndef SORT_FUNCTION_H
#define SORT_FUNCTION_H

#include <string>
#include <unordered_map> 

using namespace std;

class SortFunction {
	public:
		virtual void sort(int list[], int length) = 0;
		virtual int optimizedSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex) = 0;
};
#endif
