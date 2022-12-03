//
// Created by serha on 06.12.2021.
//

#ifndef UEBUNG7_ORDEREDNODE_HPP
#define UEBUNG7_ORDEREDNODE_HPP
class OrderedNode {
public:
    int element; // contains the data element

    // pointer to the next element in the list
    //Constructors
    OrderedNode() {
        this->element=0;
    }
    OrderedNode(int d) {
        this->element=d;
    }
    OrderedNode(int d, OrderedNode *n) {
        this->element=d;
    }
};







#endif //UEBUNG7_ORDEREDNODE_HPP
