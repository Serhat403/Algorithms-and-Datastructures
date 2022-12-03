//
// Created by serha on 21.10.2021.
//

#ifndef UEBUNG2_LINKEDLIST_HPP
#define UEBUNG2_LINKEDLIST_HPP
#include <iostream>
#include "ListNode.hpp"

class LinkedList
{
    unsigned int sizeOfList;
    ListNode *head;
    ListNode *tail;

public:
    LinkedList(); // constructs an empty list
    int size() const ;
    void addFirst(int data); // adds an element at the beginning of the list
    void addLast(int data);  // adds an element at the end of the list
    void addSorted(int val);  // adds an element in a sorted list
    void sortASC();  // sorts the list in ascending order: 1, 2, 3
    void sortDES();  // sorts the list in descending order: 3, 2, 1
    void clear();  // removes and deletes all elements of the list
    int removeFirst();  // removes the first element and returns value of the element,
    int removeLast();  // removes the last element and returns value of the element, //-1 if empty
    int getFirst();  // returns the first element, -1 if empty
    int getLast();  // returns the last element, -1 if empty
    bool contains(int value); // returns true if the list contains value
    int getAt(int index);  // returns element at position index, //-1 if index is out of bounds
    int removeAt(int index);// remove element at position index and returns element value, //-1 if index is out of bounds
    void printElements();// prints the list
    ~LinkedList();// destructor must free all allocated memory
};
#endif /* UEBUNG2_LINKEDLIST_HPP */


