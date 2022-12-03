#include <iostream>


#include "MinHeap.hpp"


int main() {
    using namespace std;
    auto *heap1=new MinHeap(10);

    heap1->insert(1);
    heap1->insert(2);
    heap1->insert(3);
    heap1->insert(4);
    heap1->insert(5);

cout <<"die werte im Heap"<< endl;
std::string test;
test =heap1->toString();
cout <<test<< endl;
cout <<"/n"<< endl;

cout <<"der minimum wert im Heap"<< endl;
int minimum = heap1->min();
cout <<minimum<< endl;
cout <<"/n"<< endl;

cout <<"Die größe vom Heap"<< endl;
cout <<heap1->size()<< endl;
cout <<"/n"<< endl;

cout <<"ob der Heap leer ist"<< endl;
bool ifempty = heap1->isEmpty();
cout <<ifempty<< endl;
if(ifempty==0){
    cout << "heap ist nicht leer"<< endl;
}
else{
     cout << "heap ist leer"<< endl;
}
cout <<"/n"<< endl;
    cout <<"wie sieht der heap nach dem löschen aus"<< endl;
    heap1->removeMin();
    test =heap1->toString();
    cout <<test<< endl;

return 0;



}
