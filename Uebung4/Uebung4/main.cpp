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

    // ich habe die tests von übung 3 stehen lassen damit man sieht das
    // vorherigne funktionen funktionieren
    // Übung 4
    //Aufgabe 1 Test
    auto *heap2=new MinHeap(10);

    heap2->insert(1);
    heap2->insert(2);
    heap2->insert(3);
    heap2->insert(4);
    heap2->insert(5);
    heap2->insert(6);
    heap2->insert(7);
    heap2->insert(8);
    heap2->insert(9);
    heap2->insert(10);

    cout <<"ob der Heap die zahl beinhaltet"<< endl;
    bool ifcontain = heap2->contains(2);
    cout <<ifcontain<< endl;
    if(ifcontain==0){
        cout << "nein er beinhaltet es nicht"<< endl;
    }
    else{
        cout << "ja er beinhaltet es "<< endl;
    }

    int array[]={10,9,8,7,6,5,4,3,2,1};
    sort(array,10);
    cout <<array[0]<< endl;
    cout <<array[1]<< endl;
    cout <<array[2]<< endl;
    cout <<array[3]<< endl;
    cout <<array[4]<< endl;
    cout <<array[5]<< endl;
    cout <<array[6]<< endl;
    cout <<array[7]<< endl;
    cout <<array[8]<< endl;
    cout <<array[9]<< endl;

    int array2[] = {18, 13, 15, 10, 8, 12, 9, 5, 3, 2};
    sort(array2, 10);
    cout << array2[0] << endl;
    cout << array2[1] << endl;
    cout << array2[2] << endl;
    cout << array2[3] << endl;
    cout << array2[4] << endl;
    cout << array2[5] << endl;
    cout << array2[6] << endl;
    cout << array2[7] << endl;
    cout << array2[8] << endl;
    cout << array2[9] << endl;






    return 0;



}
