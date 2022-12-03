//
// Created by serha on 18.11.2021.
//

#ifndef UEBUNG5_BINARYSEARCHTREE_HPP
#define UEBUNG5_BINARYSEARCHTREE_HPP

#include <iosfwd>

template <typename K, typename V>
// internal structure to store node key and value
class BST {
    struct Node {
        K key;
        V value;
        Node *left, *right;
        Node(K k, V v){
            this->key = k;
            this->value=v;
            this->left=nullptr;
            this->right=nullptr;
        }
        // konstruktor für node
        bool operator<(const Node &other);
        bool operator>(const Node &other);
        bool operator>=(const Node &other);
        bool operator<=(const Node &other);
        //friend std::ostream & operator << (std::ostream & os,
        //
        //
        //
        //                                  const Node & node);
        // };
        friend std::ostream &operator<<(std::ostream &os, const Node &node) {
            os << "{" << node.key << ": " << node.value << "}";
            return os;
        }
    };
    Node *root = nullptr;
    void printInOrder(Node *node);
    void clear(Node *n);

    public:
        BST();

        virtual ~BST();

        // removes all nodes of the tree and deletes the memory
        void clear();

        // inserts an element into the binary search tree
        // the elements are sorted according to K key
        void insertElement(K key, V value);


        // returns true if the binary search tree contains the given key
        // false otherwise
        bool containsKey(K key);

        // returns a pointer to the value which is stored under key
        V *getValue(K key);

        // returns a pointer to the value which is referred to
        // by the smallest key
        V *getMinimum(){
            if (root == nullptr) {
                return nullptr ;
            }
            Node *n = root;
            while (n->left != nullptr) {
                n = n->left;
            }
            return &n->value;
        }

        // returns a pointer to the value which is referred to
        // by the highest key
        V *getMaximum();

        // removes the element referred to by key and deletes the allocated
        // memory
        void deleteElement(K key);

        // prints the elements in the tree in order,
        // for each node the pair (key, value) should be printed
        void printInOrder();
    };



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
// ober methoden könnten meine vergeliche erstetzen aber wir müssen
// sie laut professor nicht einsetzen deswegen
template<typename K, typename V>
BST<K, V>::BST() {
    root = nullptr;
}
// konstruktor für baum mit root
template<typename K, typename V>
BST<K, V>::~BST() {
clear();
}
// die clear habe ich einfach hier aufgerufen
template<typename K, typename V>
void BST<K, V>::clear() {
    clear(root);
    root=nullptr;
}
// habe eine hilfsfunktion geschrieben
// die rekursiv ist
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
// ganz normale insert methode unter berücksichtigung der eigenschaften eines binären suchbaumes
// der professor hat gesagt das wir davon ausgehen können das ein key nicht zweimal insertet werden kann
template<typename K, typename V>
bool BST<K, V>::containsKey(K key) {
    Node *n=root;
    while(n != nullptr)
    {
        if(n->key == key) {
            return true;
        }
        if(n->key > key){
            n = n->left;
        }
        else {
            n = n->right;
        }
    }
    return false;
}
// contains methode wir gehen mit einer schlefie durch und überprüfen mti eineem if
// und retournieren true fals gefunden sonst halt false
template<typename K, typename V>
V* BST<K, V>::getValue(K key) {
    if(root->key==key){
        return &root->value;
    }
    if(root->key > key){
        root=root->left;
        while(root->key!=key){
            root=root->left;
        }
        return &root->value;
    }
    if(root->key < key ){
        root=root->right;
        while(root->key!=key){
            root=root->right;
        }
        return &root->value;
    }
    return nullptr;
}
// wir schauen als ersten mit if bei root nach dem key fals ja wird der wert zurückgegebne
// ansosnten gehen wir mit schleifen durch die linke und rechte seite überprüfen mit einem if und
// geben den wert zurück wern ner gefunden wurde ansonsten nullptr wernn er nicht gefudne nwurde

template<typename K, typename V>
V *BST<K, V>::getMaximum() {

    if(root== nullptr)
    {
       return nullptr;
    }
    Node*n = root;
    while(n->right!= nullptr) {
        n = n->right;
    }
    return &n->value;
}
// für den maximum gehen wir die rechte seite mit iner schleife druch
// sobald wir das ende erreichen return value
template<typename K, typename V>
void BST<K, V>::deleteElement(K key) {
Node *current=root;
Node *previous=nullptr;

while(current!=nullptr && current->key!=key) {
    previous = current;
    if (key < current->key) {
        current = current->left;
    } else {
        current = current->right;
    }
}
    if(current==nullptr){
        return;
    }
    if(current->left==nullptr || current->right==nullptr){
        Node *NewCurrent;
        if(current->left==nullptr){
            NewCurrent=current->right;
        }
        else {
            NewCurrent=current->left;
        }
        //if (previous == nullptr)
         //   return;
        if(current==previous->left){
            previous->left=NewCurrent;
        }
        else {
            previous->right=NewCurrent;
        }
        delete current;
    }

    else {
        Node *p=nullptr;
        Node *temp;
        temp=current->right;
        while(temp->left!=nullptr){
            p=temp;
            temp=temp->left;
        }
        if(p!=nullptr){
            p->left=temp->right;
        }
        else{
            current->right=temp->right;
        }
        current->key=temp->key;
        delete temp;
    }

}
// delete methode unter berücksichtigung der eigenschaften eines bst
// iteraitve variante weil die rekursive bei mir probleme gemacht hat

template<typename K, typename V>
void BST<K, V>::printInOrder() {
    printInOrder(root);
}
template<typename K, typename V>
void BST<K, V>::printInOrder(BST<K,V>::Node* node) {

    Node *n=node;
    if(n!=nullptr){
        printInOrder(n->left);
        std::cout << n->value << std::endl;
        printInOrder(n->right);
    }

}
// printInorder mit einer hilffunktion die rekursiv ist
// es funktioniert so anders herum hätte es nicht rekursiv funktiniert
template<typename K, typename V>
void BST<K, V>::clear(BST::Node *n) {
    if(n!=nullptr){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}
// ich habe zum clearen die inorder methode etwas umgeändert
// und gehe den baum quasi so durch und delete die werte


#endif //UEBUNG5_BINARYSEARCHTREE_HPP
