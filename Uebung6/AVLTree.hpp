//
// Created by serha on 28.11.2021.
//

#ifndef UEBUNG6_AVLTREE_HPP
#define UEBUNG6_AVLTREE_HPP



template < typename K >
class AVLTree {
    struct AVLNode {
        // data (also serves as key)
        K element;
        // pointer to the siblings and parents
        AVLNode * left, * right, * parent;
        int node_height = 0;
        AVLNode(K k) {
        this->element=k;
        this->left=nullptr;
        this->right=nullptr;
        this->parent=nullptr;
        node_height=0;
        }

        bool operator < (const AVLNode & other) {
              return this->element< other.element;
        }

        bool operator <= (const AVLNode & other) {
            return!(*this> other);
        }

        bool operator > (const AVLNode & other) {
            return other.element< this->element;
        }

        bool operator >= (const AVLNode & other) {
            return!(*this< other);
        }

        friend std::ostream & operator << (std::ostream & os,
                                           const AVLNode & node) {
            os << "{" << node.key << ": " << node.value << "}";
            return os;
        }


    };


    AVLNode * root = nullptr;
    int no_nodes;
private:
    // Updates the height of the nodes
    void updateHeight(AVLNode * node) {
        while(node!=nullptr){
            int height = max(getHeight(node->left), getHeight(node->right));
            height=height+1;
            node->node_height=height;
            node=node->parent;
        }
    }


    int getHeight(AVLNode * node) {
        if(node==nullptr){
            return 0;
        }
        else {
            return node->node_height;
        }
    }

    // returns the balance of the current node:
    // -1 if the right subtree is higher than the left subtree
    // +1 the left subtree is higher than the right subtree
    int getBalance(AVLNode * node) {
        /*if (node == nullptr) {
            return;
        } else {
            int leftheight = getBalance(node->left);
            int rightheight = getBalance(node->right);

            if (leftheight > rightheight) {
                return +1;
            } else {
                return -1;
            }
        }*/
        if (node == nullptr) {
            return 0;
        }

        else{
            return getHeight(node->left)- getHeight(node->right);
        }
    }
    // der herr professor hat uns gesagt dass wir hier es so machen dürfen
    // ansonsten habe ich den code stehen lassen um es wie in der anforderung zu haben
    // aber so ist es anscheindend besser


    // Recursively search the tree
    bool containselement(AVLNode *n, K element) {

        if(n==nullptr){
            return false;
        }
        if(n->element==element){
            return true;
        }
        if(n->element>element){
        return containselement(n->left,element);
        }
        if(n->element<element){
            return containselement(n->right,element);
        }

        return false;
    }
    //bei übung 5 hatte ich es iterativ
    //jetzt rekursiv

    // methode die wir für right rotate und left rotate brauchen
    //max
    int max(int a, int b){

        if(a > b){
            return a;
        }

    return b;
    }

    // Restructure and return new root node
    AVLNode * rightRotate(AVLNode * y) {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;
        x->right = y;
        y->left = T2;
        // set parent pointer
        x->parent = y->parent;
        y->parent = x;
        if (T2 != nullptr) T2->parent = y;
        // update the height of the nodes
        y->node_height = max(getHeight(y->left), getHeight(y->right)) + 1;

        x->node_height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;

    }
    // Restructure and return new root node
    AVLNode * leftRotate(AVLNode * x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;
        y->left = x;
        x->right = T2;
        // set parent pointer
        y->parent = x->parent;
        x->parent = y;
        if (T2 != nullptr) T2->parent = x;
        // update the height of the nodes
        x->node_height = max(getHeight(x->left), getHeight(x->right)) + 1;

        y->node_height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    void printInOrder2(AVLNode *node){
        AVLNode *n=node;
        if(n!=nullptr){
            printInOrder2(n->left);
            std::cout << n->element << std::endl;
            printInOrder2(n->right);
        }
    }

public:
    //hier sind meine zusätzlichen Methoden Anfang

    void clear2(AVLNode * node){

        if(node!=nullptr){
            clear2(node->left);
            clear2(node->right);
            delete node;
        }
    }



    //hier sind meine zusätzlichen Methoden Ende

    AVLTree() {
    no_nodes=0;
    }

    virtual ~AVLTree() {
    clear();
    }

// Removes all elements of the tree and frees allocated memory
    void clear() {
        clear2(root);
        root=nullptr;
    }

    // Returns the number of nodes in the tree
    int size() {
        return no_nodes;
    }

    // returns the height of the tree, which is stored at the root node,
    // -1, if the tree is empty
    int height() {
        if(root==nullptr){
            return-1;
        }
        else {
            return root->node_height;
        }
    }


    // Insertion of new node
    void insert(K element) {

        if(this->containselement(root,element)){
            return;
        }

        AVLNode *new_node = new AVLNode(element);
        AVLNode *prev = nullptr;
        AVLNode *current = this->root;
        while (current != nullptr) {
            prev = current;
            if (new_node->element < current->element) {
                current = current->left;
            }else {
                current = current->right;
            }
        }
        if (prev == nullptr) {
            root = new_node;
            no_nodes++;
        }else {
            if (new_node->element < prev->element) {
                prev->left = new_node;
                new_node->parent=prev;
            }else {
                prev->right = new_node;
                new_node->parent=prev;
            }
            no_nodes++;
        }
        // folien
        updateHeight(new_node);
        current=new_node;
        int balance = getBalance(current); // start at the inserted node
        do {
            balance = getBalance(current);
        // if this node is not balanced break the search loop
            if (balance < -1 || balance > 1) {
                break;
            }
            // go up the tree
            current = current->parent;
        }while (current != nullptr);

        // überprüfen auf nullptr
        if(current==nullptr){
            return;
        }
        // weiter fall 1
        // balance > 1 means we must deal with some right rotation
        if (balance > 1 && current->left != nullptr && element < current->left->element) {
        // from the last part of the if statement we know, that our element must be on the left subtree
        // → we must deal with the “left-left” case
            if (current->parent == nullptr) {
                root = rightRotate(current);
            }else if (current->parent->left == current) {
                current->parent->left = rightRotate(current);
            }else {
                current->parent->right = rightRotate(current);
            }
        }
        //weiter fall 2
        if (balance > 1 && current->left != nullptr && element > current->left->element) {
            // from the last part of the if statement we know, that our element must be on the right subtree
            // → we must deal with the “left-right” case
            AVLNode *nr = leftRotate(current->left);
            current->left = nr;
            if (current->parent == nullptr) {
                root = rightRotate(current);
            }else if (current->parent->left == current) {
                current->parent->left = rightRotate(current);
            }else if (current->parent->right == current) {
                current->parent->right = rightRotate(current);
            }
        }
        // insgesamt 4 fälle noch 2 übrig
        //hinweis
        // restliche für kleine als -1
        //3 fall
        if (balance < -1 && current->right != nullptr && element > current->right->element) {

            if (current->parent == nullptr) {
                root = leftRotate(current);
            }else if (current->parent->left == current) {
                current->parent->left = leftRotate(current);
            }else {
                current->parent->right = leftRotate(current);
            }
        }
        //4 fall
        if (balance < -1 && current->right != nullptr && element < current->right->element) {

            AVLNode *nr = rightRotate(current->right);
            current->left = nr;
            if (current->parent == nullptr) {
                root = leftRotate(current);
            }else if (current->parent->left == current) {
                current->parent->left = leftRotate(current);
            }else if (current->parent->right == current) {
                current->parent->right = leftRotate(current);
            }
        }
    }
        //die überprüfung ob ein element doppelt drinnen ist
        // ist jetzt mit contatins quasi ausgeschlosssen

    bool find(K element) {
        return containselement(root, element);
    }

    void deleteElement(K element) {
        AVLNode *current=root;
        AVLNode *previous=nullptr;

        while(current!=nullptr && current->element!=element) {
            previous = current;
            if (element < current->element) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if(current==nullptr){
            return;
        }
        if(current->left==nullptr || current->right==nullptr){
            AVLNode *NewCurrent;
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
            AVLNode *p=nullptr;
            AVLNode *temp;
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
            current->element=temp->element;
            delete temp;
        }
    }
    //delet von binary search tree

    void printInOrder()  {
        printInOrder2(root);
    }




};




#endif //UEBUNG6_AVLTREE_HPP
