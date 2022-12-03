//
// Created by serha on 05.12.2021.
//

#ifndef UEBUNG7_CHAININGHASHSET_HPP
#define UEBUNG7_CHAININGHASHSET_HPP

#include "ChainingNode.hpp"
class ChainingHashSet {
private:
    ChainingNode **hashTable; // Pointer to array representing the hashset
    int nrElements;
    int capacity;

    int hashfunktion(int key){
            int hashwert=key %capacity;
            return hashwert;
    }
    //Als hashfunktion können Sie die Divisions-Rest-Methode verwenden.

public:

    ChainingHashSet(int initCapacity) {
    this->nrElements=0;
    this->capacity=initCapacity;

        hashTable = new ChainingNode*[initCapacity];
        for (int i = 0; i < initCapacity; ++i) {
            hashTable[i] = nullptr;
        }
    }
    // Allocates and initialize empty hashset

    // info prof
    //Anmerkung: Die Variable hashTable ist ein Array von Zeigern auf ChainingNode. Ein
    //Zeigerarray kann auf folgende Weise angelegt werden: hashTable = new
    //ChainingNode*[initCapacity];
    //info prof



    ~ChainingHashSet() {
        clear();
        delete[] hashTable;
    }
    // Deallocate memory for the chained nodes and the array

    int size() {
        return nrElements;
    }
    // Returns the number of stored keys

    bool insert(int key) {

        if(contains(key)){
            return false;
        }
        // weil kein wert 2 mal rein soll

        int hashWert = hashfunktion(key);
        ChainingNode *next =hashTable[hashWert];
        ChainingNode *node = new ChainingNode(key, next);
        hashTable[hashWert]=node;
        nrElements++;

        return true;
    }


    // Inserts the key into the hashset
    // returns true if key has been inserted
    // false otherwise
    bool contains(int key) {
        int hashwert=hashfunktion(key);
        ChainingNode *current =hashTable[hashwert];
        while(current!=nullptr){
            if(current->element==key){
                return true;
            }
            current=current->next;
        }
        return false;
    }
    // Returns true if the key is in the hashset
    // false otherwise
    bool remove(int key) {

            if(contains(key)==false ){
                return false ;
            }
            int hashwert = hashfunktion(key);
            ChainingNode *current=hashTable[hashwert];

            if(hashTable[hashwert]->element==key){
                hashTable[hashwert]=current->next;
                delete current;
                nrElements--;
                return true;
            }
            else {
                while(current!=nullptr){
                    if(current->element==key){
                        ChainingNode *zwischenspeicher =current->next;
                        delete current;
                        current->next=zwischenspeicher;
                    }
                    nrElements--;
                    current = current->next;
                }

                return true;
            }
          return false;
    }
    // removes the key (true if the key was removed,
    // false otherwise

    void clear() {

        ChainingNode *zwischenspeicher;
        for (int i = 0; i < capacity; i++) {
            ChainingNode *current =hashTable[i];
            while(current!=nullptr){
                zwischenspeicher = current->next;
            delete current;
            current=zwischenspeicher;
            }
            hashTable[i]=nullptr;
        }
        nrElements=0;
    }
    //removes all elements from the set

    friend std::ostream &operator<<(std::ostream &os, ChainingHashSet &chs) {

        for(int i=0; i < chs.capacity; i++){
         ChainingNode *current = chs.hashTable[i];

            os << i<< ": ";

         if(current== nullptr){
             std::cout<<"kein Eintrag"<<std::endl;
             continue;
        }
            while(current!=nullptr){
                os << current->element<<" ";
                current=current->next;
            }
            std::cout << std::endl;
        }
        return os << std::endl;
    }


};

#endif //UEBUNG7_CHAININGHASHSET_HPP
