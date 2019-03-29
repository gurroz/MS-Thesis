#include "SortFunction.hpp"

class InsertionSort: public SortFunction {
	public:
		void sort(int list[], int length);
		int optimizedSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex);
};