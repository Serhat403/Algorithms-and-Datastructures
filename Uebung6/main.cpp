#include <iostream>
#include"AVLTree.hpp"
int main() {



    std::cout << "Hier fangen die Tests an!" << std::endl;
        //nur die public methoden laut professor

    AVLTree<int> *tree;

    tree->insert(13);
    tree->insert(10);
    tree->insert(15);
    tree->insert(5);
    tree->insert(11);
    tree->insert(4);
    tree->insert(8);
    tree->insert(16);

    std::cout << "Find: " << tree->find(1) << std::endl;
    // 1 steht für true and 0 steht für false
    std::cout << "height: " << tree->height() << std::endl;
    std::cout << "size: " << tree->size() << std::endl;
    tree->printInOrder();
    tree->clear();
    tree->printInOrder();

    return 0;






}
