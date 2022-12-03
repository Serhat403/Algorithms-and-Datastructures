//
// Created by serha on 18.11.2021.
//

#include <iostream>
#include "BinarySearchTree.hpp"

/*
template<typename K, typename V>
BST<K, V>::Node::Node(K k, V v) {
this->key = k;
this->value=v;
this->left=nullptr;
this->right=nullptr;
}

template<typename K, typename V>
bool BST<K, V>::Node::operator<(const BST::Node &other) {
    return this->key< other.key;
}

template<typename K, typename V>
bool BST<K, V>::Node::operator>(const BST::Node &other) {
    return other.key< this->key;
}

template<typename K, typename V>
bool BST<K, V>::Node::operator>=(const BST::Node &other) {
    return!(*this< other);
}

template<typename K, typename V>
bool BST<K, V>::Node::operator<=(const BST::Node &other) {
    return!(*this> other);
}

//std::ostream &operator<<(std::ostream &os, const BST::Node &node) {
// return nullptr;
//}

template<typename K, typename V>
BST<K, V>::BST() {
    new Node();
}

template<typename K, typename V>
BST<K, V>::~BST() {

}

template<typename K, typename V>
void BST<K, V>::clear() {

}

template<typename K, typename V>
void BST<K, V>::insertElement(K key, V value) {
    Node *new_node = new Node(key, value);
    Node *prev = nullptr;
    Node *current = this->root;
    while (current != nullptr) {
        prev = current;
        if (new_node->key < current->key) {
            current = current->left;
        }else {
            current = current->right;
        }
    }
    if (prev == nullptr) {
        root = new_node;
    }else {
        if (new_node->key < prev->key) {
            prev->left = new_node;
        }else {
            prev->right = new_node;
        }
    }
}



template<typename K, typename V>
bool BST<K, V>::containsKey(K key) {
    Node *n=root;
    while(n != nullptr)
    {
        if(n->value == key->value) {
            return true;
        }
        if(n->value > key->value){
            n = n->left;
        }
        else {
            n = n->right;
        }
    }
    return false;
}

template<typename K, typename V>
V *BST<K, V>::getValue(K key) {

    if(root->key==key){
        return root;
    }

    if(root->key>key){
        root=root->left;
        while(root->key!=key){
            root=root->left;
        }
        return root->value;
    }

    if(root->key<key){
        root=root->right;
        while(root->key!=key){
            root=root->right;
        }
            return root->value;
    }

}

template<typename K, typename V>
V *BST<K, V>::getMinimum() {
    if (root == nullptr) {
        return -1;
    }
    Node *n = root;
    while (n->left != nullptr) {
        n = n->left;
    }
    return &n->value;
}

template<typename K, typename V>
V *BST<K, V>::getMaximum() {
    if(root== nullptr)
    {
       -1;
    }
    Node*n = root;
    while(n->right!= nullptr) {
        n = n->right;
    }
    return &n->value;
}

template<typename K, typename V>
void BST<K, V>::deleteElement(K key) {

}

template<typename K, typename V>
void BST<K, V>::printInOrder() const {

    Node *n=root;
    if(n!=nullptr){
        printInOrder(n->left);
        std::cout << n->value << std::endl;
        printInOrder(n->right);

    }


}*/
