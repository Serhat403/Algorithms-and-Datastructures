//
// Created by serha on 05.12.2021.
//

#ifndef UEBUNG7_CHAININGNODE_HPP
#define UEBUNG7_CHAININGNODE_HPP

class ChainingNode {
public:
    int element; // contains the data element
    ChainingNode *next; // pointer to the next element in the list
    //Constructors
    ChainingNode() {
        this->element=0;
        this->next=nullptr;

    }
    ChainingNode(int d) {
        this->element=d;
    }
    ChainingNode(int d, ChainingNode *n) {
        this->element=d;
        this->next=n;
    }
};








#endif //UEBUNG7_CHAININGNODE_HPP
