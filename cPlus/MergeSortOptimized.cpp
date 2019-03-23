#include "MergeSortOptimized.hpp"
#include <algorithm>    // std::min

using namespace std;



int MergeSortOptimized::sort(int list[], int length, unordered_map<string, int> signaturesMap, int actualIndex) {
	return mergeSort(list, length, signaturesMap, actualIndex);
}


int MergeSortOptimized::mergeSort(int list[], int length, unordered_map<string, int> signaturesMap, int actualIndex) {
   for(int mergingArraySize = 1; mergingArraySize < length; mergingArraySize = (2 * mergingArraySize)) { 

       long hashVal = 17;
       for(int startIndex = 0; startIndex < length-1; startIndex += (2 * mergingArraySize)) { 
           int half = startIndex + mergingArraySize - 1; 
           int endIndex = min((startIndex + (2 * mergingArraySize) - 1), length-1);

          // Only calculate hash in the first pass
          if(mergingArraySize == 1) {
            hashVal = merge(list, startIndex, half, endIndex, hashVal); 
          } else {
            merge(list, startIndex, half, endIndex); 
          }
       } 

      if(mergingArraySize == 1) { // means all elements checked. Perform hash check
        unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(hashVal);
        if(signatureFinder == signaturesMap.end()) {
          signaturesMap.insert(make_pair(signature, j));
        } else {
          int originalIndex = signatureFinder->second;
          return originalIndex;
        }
      }
   }

   return -1;
}

void MergeSortOptimized::merge(int list[], int startIndex, int half, int endIndex) {
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


long MergeSortOptimized::merge(int list[], int startIndex, int half, int endIndex, long hash) {
  int leftListLength = half - startIndex + 1; 
  int rightListLength = endIndex - half; 
  
  int leftList[leftListLength];
  int rightList[rightListLength]; 

  for(int i = 0; i < leftListLength; i++) {
    leftList[i] = list[startIndex + i]; 
    hashVal = hashVal * 19 + leftList[i];
  }

  for(int i = 0; i < rightListLength; i++)  {
    rightList[i] = list[half + 1 + i]; 
    hashVal = hashVal * 19 + leftList[i];
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