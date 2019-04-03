//
//  MinHeap.hpp
//  HashSort
//
//  Created by Gonzalo Urroz on 3/4/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>

// A min heap node
struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the array from which the element is taken
    int j; // index of the next element to be picked from array
};

// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

// A class for Min Heap
class MinHeap
{
    MinHeapNode *harr; // pointer to array of elements in heap
    int heap_size; // size of min heap
public:
    // Constructor: creates a min heap of given size
    MinHeap(MinHeapNode a[], int size);
    
    // to heapify a subtree with root at given index
    void MinHeapify(int );
    
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
    
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
    
    // to get the root
    MinHeapNode getMin() { return harr[0]; }
    
    // to replace root with new node x and heapify() new root
    void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};

#endif /* MinHeap_hpp */
