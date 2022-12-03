//
// Created by serha on 08.11.2021.
//

#ifndef UEBUNG4_MINHEAP_HPP
#define UEBUNG4_MINHEAP_HPP
#include <iostream>
#include <string>
#include <limits>

class MinHeap {
private:
    int *heap; //Pointer to array representing the heap
    int nrElements;
    int heapCapacity;
    void upHeap(int index);
    void downHeap(int index);
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
    void swap(int index1, int index2);
    int contains(int value, int index_subtree); // recursive Methode zum Suchen
public:
    MinHeap(int initCapacity);
    bool isEmpty(); //true if Heap is empty, false otherwise
    int size(); //returns the amount of elements in the Heap
    void insert(int data); //inserts the element data into the Heap
    int min(); //returns the minimum element
    int removeMin(); //removes and returns the minimum element
    std::string toString(); //returns a string representation of the Heap
    // Erweiterung Übung 4
    bool contains(int element); // returns true, if the heap contains element
    ~MinHeap(); // destructor
};
// sorts the array elements using the MinHeap
void sort(int array[], int sizeOfArray);


#endif //UEBUNG4_MINHEAP_HPP
