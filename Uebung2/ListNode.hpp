//
// Created by serha on 21.10.2021.
//

#ifndef UEBUNG2_LISTNODE_HPP
#define UEBUNG2_LISTNODE_HPP


class ListNode {
public:
    int element{};    // contains the data element
    ListNode *next; // pointer to the next element in the list

    ListNode();
    ListNode(int d);
    ListNode (int d, ListNode *n);


};


#endif //UEBUNG2_LISTNODE_HPP
