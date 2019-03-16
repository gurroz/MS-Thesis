#include "SortFunction.hpp"

class MergeSort: public SortFunction  {
	public:
		void sort(int list[], int length);
	private:
		void mergeSort(int list[], int length);
		void merge(int arr[], int l, int m, int r) ;
};