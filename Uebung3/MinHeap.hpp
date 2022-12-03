//
// Created by serha on 28.10.2021.
//

#ifndef UEBUNG3_MINHEAP_HPP
#define UEBUNG3_MINHEAP_HPP

#include <string>
#include <limits>

class MinHeap {
private:
    int *heap; //Pointer to array representing the heap
    int nrElements;
    int heapCapacity;
    void upHeap(int index);
    void downHeap(int index);
    static int parent(int index) ;
    static int leftChild(int index) ;
    static int rightChild(int index) ;
    void swap(int index1, int index2);
public:

    explicit MinHeap(int initCapacity);
    bool isEmpty() const; //true if Heap is empty, false otherwise
    int size() const; //returns the amount of elements in the Heap
    void insert(int data); //inserts the element data into the Heap
    int min(); //returns the minimum element, in case the heap is empty,
    //return std::numeric_limits<int>::min();
    int removeMin(); //removes and returns the minimum element
    std::string toString(); //returns a string representation of the Heap
    ~MinHeap(); // destructor
};


#endif //UEBUNG3_MINHEAP_HPP
