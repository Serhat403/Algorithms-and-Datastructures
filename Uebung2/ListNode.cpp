//
// Created by serha on 21.10.2021.
//

#include "ListNode.hpp"

ListNode::ListNode() {
    next = nullptr;
}

ListNode::ListNode(int d) {
    element = d;
    next = nullptr;
}

ListNode::ListNode(int d, ListNode *n) {
    element = d;
    next = n;
}

