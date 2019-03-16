#include "MergeSort.hpp"
#include <algorithm>    // std::min

using namespace std;



void MergeSort::sort(int list[], int length) {
	mergeSort(list, length);
}


void MergeSort::mergeSort(int list[], int length) {
   for(int mergingArraySize = 1; mergingArraySize < length; mergingArraySize = (2 * mergingArraySize)) { 

       for(int startIndex = 0; startIndex < length-1; startIndex += (2 * mergingArraySize)) { 
           int half = startIndex + mergingArraySize - 1; 
           int endIndex = min((startIndex + (2 * mergingArraySize) - 1), length-1);

           merge(list, startIndex, half, endIndex); 
       } 
   } 
}

void MergeSort::merge(int list[], int startIndex, int half, int endIndex) {
  int leftListLength = half - startIndex + 1; 
  int rightListLength = endIndex - half; 
  
  int leftList[leftListLength];
  int rightList[rightListLength]; 

  for(int i = 0; i < leftListLength; i++) {
    leftList[i] = list[startIndex + i]; 
  }

  for(int i = 0; i < rightListLength; i++)  {
    rightList[i] = list[half + 1 + i]; 
  }

  int i = 0;
  int j = 0;
  int globalIndex = startIndex; 

  while (i < leftListLength && j < rightListLength) { 
      if (leftList[i] <= rightList[j]) { 
          list[globalIndex] = leftList[i]; 
          i++; 
      }  else { 
          list[globalIndex] = rightList[j]; 
          j++; 
      } 
      
      globalIndex++; 
  } 
  
  while (i < leftListLength) { 
      list[globalIndex] = leftList[i]; 
      i++; 
      globalIndex++; 
  } 

  while (j < rightListLength) { 
      list[globalIndex] = rightList[j]; 
      j++; 
      globalIndex++; 
  }
}
