#include <iostream>
#include "BinarySearchTree.hpp"

int main() {
    std::cout << "Hier fangen die Tests an!" << std::endl;
    BST<int, int> *Btree=new BST<int,int>();
    Btree->insertElement(0,12);
    Btree->insertElement(1,4);
    Btree->insertElement(2,17);
    Btree->insertElement(3,15);
    Btree->insertElement(4,8);
    Btree->insertElement(5,23);
    Btree->insertElement(6,55);

    BST<int, int> *Btree2=new BST<int,int>();
    Btree2->insertElement(0,12);
    Btree2->insertElement(1,4);
    Btree2->insertElement(2,17);
    Btree2->insertElement(3,15);
    Btree2->insertElement(4,8);
    Btree2->insertElement(5,23);
    Btree2->insertElement(6,55);
    Btree2->printInOrder();
    Btree2->clear();
    Btree2->printInOrder();


   std::cout<<"Max: "<< (*Btree->getMaximum())<< std::endl;
   std::cout << "Min: " << *Btree->getMinimum() << std::endl;
   std::cout << "Contains: " << Btree->containsKey(0) << std::endl;
   // 1 steht für true and 0 steht für false
    std::cout << "Contains: " << Btree->containsKey(7) << std::endl;
   // falls der Wert gefunden wurde wird der retourniert
   std::cout<< "Get value of key 0: "<< *Btree->getValue(0)<< std::endl;
    Btree->printInOrder();
   Btree->deleteElement(4);
    Btree->printInOrder();


    return 0;
}
