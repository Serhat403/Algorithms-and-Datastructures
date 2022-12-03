#include <iostream>
#include "ChainingHashset.hpp"
#include "OrderedDoubleHashset.hpp"
int main() {


/*    std::cout << "Hier fangen die Tests an" << std::endl;

        ChainingHashSet *Chain1= new ChainingHashSet(10);

        Chain1->insert(85);
        Chain1->insert(75);
        Chain1->insert(65);
        Chain1->insert(45);
        Chain1->insert(35);
        Chain1->insert(85);
        Chain1->insert(95);
        Chain1->insert(55);
        Chain1->insert(44);
        Chain1->insert(54);

    std::cout << "size: " << Chain1->size();
    std::cout << std::endl;
    std::cout << *Chain1;
    std::cout <<Chain1->contains(45)<< std::endl;
    //Chain1->clear();
    std::cout << *Chain1;

    //1 steht für true und 0 für false
    //Chain1->clear();
    //std::cout << *Chain1;

    ChainingHashSet *Chain2= new ChainingHashSet(7);
    Chain2->insert(85);
    Chain2->insert(75);
    Chain2->insert(65);
    Chain2->insert(45);
    Chain2->insert(35);
    Chain2->insert(44);
    Chain2->insert(54);
    std::cout << *Chain2;

    std::cout <<Chain2->remove(45)<< std::endl;
    std::cout <<Chain2->contains(45)<< std::endl;
    //Chain2->clear();
    std::cout << *Chain2;
    std::cout <<Chain2->remove(65)<< std::endl;
    std::cout <<Chain2->contains(65)<< std::endl;
    std::cout << *Chain2;*/

    std::cout << "OrderedDoubleHashSet"<< std::endl;
    OrderedDoubleHashset *Chain3= new OrderedDoubleHashset(10);
    Chain3->insert(20);
    Chain3->insert(35);
    Chain3->insert(10);
    Chain3->insert(30);
    Chain3->insert(43);
    Chain3->insert(23);
    Chain3->insert(13);
    Chain3->insert(83);
    std::cout << *Chain3;
    return 0;


}
