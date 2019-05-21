#include "MergeSort.hpp"
#include <algorithm>    // std::min
#include <iostream>

using namespace std;



void MergeSort::sort(int list[], int length) {
    int tmp[length];
	mergeSort(list, tmp, length);
}

int MergeSort::optimizedSort(int list[], int length, unordered_map<string, int> &signaturesMap, int actualIndex) {
    int tmp[length];
  return mergeSort(list, tmp, length, signaturesMap, actualIndex);
}

void MergeSort::mergeSort(int list[], int tmp[], int length) {
   for(int mergingArraySize = 1; mergingArraySize < length; mergingArraySize = (2 * mergingArraySize)) { 

       for(int startIndex = 0; startIndex < length; startIndex += (2 * mergingArraySize)) {
           int left = startIndex;
           int middle = startIndex + mergingArraySize;
           int right = startIndex + (2 * mergingArraySize);

           merge(list, tmp, left, middle, right);
       }
       
       for(int i = 0; i < length; i++) {
           list[i] = tmp[i];
       }
   }
}


int MergeSort::mergeSort(int list[], int tmp[],  int length, unordered_map<string, int> &signaturesMap, int actualIndex) {
   for(int mergingArraySize = 1; mergingArraySize < length; mergingArraySize = (2 * mergingArraySize)) { 

       long hashVal = 17;
       for(int startIndex = 0; startIndex < length-1; startIndex += (2 * mergingArraySize)) { 
           int left = startIndex;
           int middle = startIndex + mergingArraySize;
           int right = startIndex + (2 * mergingArraySize);

          // Only calculate hash in the first pass
          if(mergingArraySize == 1) {
            hashVal = merge(list, tmp, left, middle, right, hashVal);
          } else {
            merge(list, tmp, left, middle, right);
          }
       } 


      if(mergingArraySize == 1) { // means all elements checked. Perform hash check
        string signature = to_string(hashVal);
        unordered_map<string, int>::const_iterator signatureFinder = signaturesMap.find(signature);
        if(signatureFinder == signaturesMap.end()) {
            signaturesMap.insert(make_pair(signature, actualIndex));
        } else {
          int originalIndex = signatureFinder->second;
          return originalIndex;
        }
      }
       
       for(int i = 0; i < length; i++) {
           list[i] = tmp[i];
       }
   }

   return -1;
}


void MergeSort::merge(int list[], int tmp[], int iLeft, int iMiddle, int iRight) {
  int i = iLeft;
  int j = iMiddle;
  int globalIndex = iLeft;

  while (i < iMiddle || j < iRight) {
      if ( i < iMiddle && j < iRight ) {
          if ( list[i] < list[j] )
              tmp[globalIndex++] = list[i++];
          else
              tmp[globalIndex++] = list[j++];
      }
      else if ( i == iMiddle )
          tmp[globalIndex++] = list[j++];
      else if ( j == iRight )
          tmp[globalIndex++] = list[i++];
  }
}


long MergeSort::merge(int list[], int tmp[], int iLeft, int iMiddle, int iRight, long hashVal) {
    int i = iLeft;
    int j = iMiddle;
    int globalIndex = iLeft;

    while (i < iMiddle || j < iRight) {
        if ( i < iMiddle && j < iRight ) {
            if ( list[i] < list[j] ){
                hashVal = hashVal * 19 + list[i];
                tmp[globalIndex++] = list[i++];
            } else {
                hashVal = hashVal * 19 + list[j];
                tmp[globalIndex++] = list[j++];
            }
        }
        else if ( i == iMiddle ) {
            hashVal = hashVal * 19 + list[j];
            tmp[globalIndex++] = list[j++];
        }
        else if ( j == iRight ) {
            hashVal = hashVal * 19 + list[i];
            tmp[globalIndex++] = list[i++];
        }
    }

  return hashVal;
}
