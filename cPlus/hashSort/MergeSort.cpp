#include "MergeSort.hpp"
#include <algorithm>    // std::min
#include <iostream>

using namespace std;



void MergeSort::sort(int list[], int length) {
	mergeSort(list, length);
}

int MergeSort::optimizedSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex) {
  return mergeSort(list, length, signaturesMap, actualIndex);
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


int MergeSort::mergeSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex) {
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

      string signature = to_string(hashVal);

      if(mergingArraySize == 1) { // means all elements checked. Perform hash check
        unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
        if(signatureFinder == signaturesMap.end()) {
          signaturesMap.insert(make_pair(signature, actualIndex));
          // cout << "Inserting into merge HashTable: "<< signature << " " << actualIndex << endl; 
        } else {
          int originalIndex = signatureFinder->second;
          return originalIndex;
        }
      }
   }

   return -1;
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


long MergeSort::merge(int list[], int startIndex, int half, int endIndex, long hashVal) {
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

  return hashVal;
}
