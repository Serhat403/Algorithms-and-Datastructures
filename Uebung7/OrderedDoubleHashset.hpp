//
// Created by serha on 06.12.2021.
//

#ifndef UEBUNG7_ORDEREDDOUBLEHASHSET_HPP
#define UEBUNG7_ORDEREDDOUBLEHASHSET_HPP
#include "OrderedNode.hpp"

class OrderedDoubleHashset{

private:
    OrderedNode **hashTable; // Pointer to array representing the hashset
    int nrElements;
    int capacity;


    int hashOne(int key){
        return (key % capacity);
    }
    int hashTwo(int key){
        return 1+ ( key % (capacity-1) );
    }
    //h1 (k) = k mod 7
    //− h2(k) = 1 + (k mod 5)




public:
    OrderedDoubleHashset(int initCapacity) {
            this->nrElements=0;
            this->capacity=initCapacity;
            hashTable = new OrderedNode*[initCapacity];
            for (int i = 0; i < initCapacity; ++i) {
                hashTable[i] = nullptr;
            }
        }
    // Allocates and initialize empty hashset

    bool tableFull(){
        if(nrElements==capacity){
            return true;
        }
        return false;
    }
    ~OrderedDoubleHashset() {
        clear();
        delete[] hashTable;
    }
    // Deallocate memory for the chained nodes and the array
    int size() {
        return nrElements;
    }
    // Returns the number of stored keys
    bool insert(int key) {


        int hashwert = hashOne(key);
        //3 cases
        int counter = capacity+1;
        while(hashTable[hashwert]!= nullptr && counter > 0) {
            //Fall2 hashwert2 position
            int hashwert2 = hashTwo(key);
            if (hashTable[hashwert]->element < key) {
                    hashwert = abs((hashwert - hashwert2) % capacity);
            }

            //Fall3
            else /*(hashTable[hashwert]->element > key)*/ {
                    int zwischenspeicher = hashTable[hashwert]->element;
                    hashTable[hashwert]->element = key;
                    key = zwischenspeicher;
                    hashwert = abs((hashwert - hashwert2) % capacity);
            }
            counter--;

        }
        //Fall1 wenn er leert ist
        OrderedNode *newNode = new OrderedNode(key);
        if(hashTable[hashwert]==nullptr){
            hashTable[hashwert]=newNode;
            nrElements++;
            return true;

        }
       /* //Fall2 hashwert2 position
        int hashwert2 = hashTwo(key);
        if(hashTable[hashwert]->element < key) {
            while(hashTable[hashwert]->element < key){
                hashwert = (hashwert-hashwert2) % capacity;
            }
            if(hashTable[hashwert]==nullptr){
                hashTable[hashwert]=newNode;
                return true;
            }
        }*/

        return false;
    }


    // Inserts the key into the hashset
    // returns true if key has been inserted
    // false otherwise
    bool contains(int key) {
        return true;
    }
    // Returns true if the key is in the hashset
    // false otherwise
    bool remove(int key);
    // removes the key (true if the key was removed,
    // false otherwise

    void clear() {
            OrderedNode *zwischenspeicher;
            for (int i = 0; i < capacity; i++) {
                delete hashTable[i];
                hashTable[i]=nullptr;
            }
            nrElements=0;
    }

    //removes all elements from the set
    friend std::ostream &operator<<(std::ostream &os, OrderedDoubleHashset &chs) {

        for(int i=0;i<chs.capacity;i++){
            os <<  chs.hashTable[i]->element << " ";
        }
        return os << std::endl;
    }


};




#endif //UEBUNG7_ORDEREDDOUBLEHASHSET_HPP
