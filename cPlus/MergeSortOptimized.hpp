#include "SortFunction.hpp"

class MergeSortOptimized: public SortFunction {
	public:
		int sort(int list[], int length, unordered_map<string, int> signaturesMap, int actualIndex);
};