#include "SortFunction.hpp"

class MergeSort: public SortFunction  {
	public:
		void sort(int list[], int length);
		int optimizedSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex);
	private:
		void mergeSort(int list[], int tmp[], int length);
		void merge(int list[],  int tmp[], int startIndex, int half, int endIndex) ;
		int mergeSort(int list[], int tmp[], int length, unordered_map<string, int> &signaturesMap, int actualIndex);
		long merge(int list[], int tmp[], int startIndex, int half, int endIndex, long hashVal);
};
