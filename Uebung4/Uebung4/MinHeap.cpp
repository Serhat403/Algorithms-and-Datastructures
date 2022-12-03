//
// Created by serha on 08.11.2021.
//

#include "MinHeap.hpp"
using namespace std;
//private
int MinHeap::parent(int index) {
    return (int) (index - 1) / 2;
}
//parent(i) = floor(j / 2)
// an die formel gehalten
int MinHeap::leftChild(int index) {
    return 2*index +1;
}
//left(i) = 2*i
// an die formel gehalten
int MinHeap::rightChild(int index) {
    return 2*index +2;
}
// right(i) = 2*i + 1
// an die formel gehalten
void MinHeap::swap(int index1, int index2) {
    const int temp =heap[index1];
    heap[index1]=heap[index2];
    heap[index2]=temp;
}
// ein ganz normaler tausch innerhalb eines arrays
// wert zwischengespeichert dann
// dann zeigt der array an der stelle index1 auf array an der stelle index2
// dann bekommt array an der stelle index2 den wert temp
void MinHeap::upHeap(int index) {
    while (nrElements >= 0 && (heap[parent(index)] > heap[index]))
    {
        swap(index, parent(index));
        index = parent(index);
    }
}
// also solange der wert vom parent index größer ist als der wert vom heap index also kind
// wird getauscht und der index bekommt den wert vom parent index
void MinHeap::downHeap(int index) {
    int left = leftChild(index);
    int  right = rightChild(index);
    int smallest=index;
    if( left < nrElements && heap[left] < heap[index] ){
        smallest=left;
    }
    if(right < nrElements && heap[right]<heap[smallest]){
        smallest=right;
    }
    if(smallest!=index){
        swap(index, smallest);
        downHeap(smallest);
        return;
    }
}
//erste if setzt smallest auf left wenn der heap[left] kleiner ist als heap[index] also
// wenn das  kind kleiner als der parent ist
// 2 if setzt smallest auf right wenn der heap an der stelle right kleiner ist als heap an der stelle smallest
// smallest ist right
// 3 if falls smallest ungleich index ist also nach dem es in den ifs oben geändert wurde
// wird getauscht und der downheap rekursiv aufgerufen
// dann return

int MinHeap::contains(int value, int index_subtree) {

    if(heap[index_subtree]==value)
    {
        return 1;
    }
    int gefunden = -1;

    int left = leftChild(index_subtree);
    int right = rightChild(index_subtree);

    if(value>=heap[left]){
        gefunden= contains(value, left);
    }

    if(value>=heap[right] && gefunden == -1){
        gefunden= contains(value, right);
    }

    return gefunden;
}
// beim ersten mal falls es beim index gleich das value ist dann return
// danach habe ich das gefunden und die left udn right sachen variablen festgelegt

// wenn die erste if bedinungung zutrifft wiederholt sich contains methode
// vom index kommt immer wieder der leftChild rein und es geht durch
// und gefunden bleibt minus 1

// falls der wert gefunden wird wird 1 retourniert

// ansonsten wird die zweite if bedingung solange gefunden -1 ist und vlaue größer ist
// danach wird wieder contains aufgerufen rekursiv

// gefunden ändert sich auf 1 oder bleibt -1
// und das nützen wir in der nächsten contains aus
// und falls 1 dann ist es da sonst -1 ist es nciht da


// die private methoden brauchen wir damit wir die  public methoden machen können
//public
MinHeap::MinHeap(int initCapacity) {
    heapCapacity=initCapacity;
    heap = new int[initCapacity];
    nrElements = 0;
}
// der konstruktor um den heap zu initialisieren
bool MinHeap::isEmpty()  {
    if(nrElements==0){
        return true;
    }
    else {
        return false;
    }
}
// mit dem if und nrElements wird überprüft ob der
// heap leer ist
int MinHeap::size()  {
    return nrElements;
}
// nr elements steigt oder sinkt mit der anzahl der elmente die dazu kommen oder reduziert werden
int MinHeap::min() {
    if(nrElements==0){
        return std::numeric_limits<int>::min();
    }
    else {

        return heap[0];
    }
}
// falls der heap leer ist
// wird der return vom if returniert
// sonst else da bei minheap an der stelle 0 immer der kleinste wert ist

int MinHeap::removeMin() {
    if(nrElements==0){
        return std::numeric_limits<int>::min();
    }
    int minimum;
    minimum = heap[0];
    heap[0]=heap[nrElements-1];
    nrElements--;
    downHeap(0);
    return minimum;
}
// wie oben für if
// für den unteren teil
// der minimum wert wird zwischengespeichert und returniert
// der heap wrid mit downheap wieder richtig geordnet
// anzahl der elemente wird reduziett da eins gelöscht wurde

std::string MinHeap::toString() {
    std::string il;
    for (int i = 0; i < nrElements; ++i){
        il.append(std::to_string(heap[i]));
    }
    return il;
}
// an einen string werdend die elemente von einem array quasi apended

MinHeap::~MinHeap() {
    delete[] heap;
}
// der heap wird gelöscht
void MinHeap::insert(int data) {

    //Fall wenn der Heap verdoppelt werden muss
    if(nrElements==heapCapacity){
        //auto doppelheap = new MinHeap(heapCapacity * 2);
        //warum funktioniet das obere nicht
        int *doppelheap=new int[heapCapacity*2];
        heapCapacity=heapCapacity*2;
        for(int i=0;i<heapCapacity;i++){
            doppelheap[i]=heap[i];
        }
        delete heap;
        heap=doppelheap;
    }
    heap[nrElements] = data;
    upHeap(nrElements++);
}
// falls die anzahl der elmente genau so groß sind wie die länge vom heap
// wird ein neuer heap also array geschaffen der doppelt so groß it
// dem werden die die werte in der korrekte nreihenfogle vom index zugewiesen
// der heap wird deleted
// und heap zeigt dann auf den neuen heap also array
// danach an der letzten stelle der neue wert eingefügt

bool MinHeap::contains(int element) {
    if(contains(element,0)!=-1)
    {
        return true;
    }
    else {
        return false;
    }
}
// ich habe minus eins als prüfung genommen falls ja dann return true sonst halt false

void sort(int *array, int sizeOfArray) {

MinHeap maxHeap= MinHeap(sizeOfArray);

    for (int i = 0; i < sizeOfArray; i++) {
        maxHeap.insert(array[i]);
    }

    int tauschwert =0;
    for (int i = 0 ; i <sizeOfArray; i++) {
       tauschwert=maxHeap.removeMin();
        array[i] = tauschwert;
    }

    //for (int i = sizeOfArray - 1; i >= 0; i--) {
    //     tauschwert=maxHeap.removeMin();
    //     array[i] = tauschwert;
    // }
}
// der auskommentierte code ist da falls man es absteigend will
// der nicht auskommentierte code ist da für aufsteigend


// ich kann hier nicht downheap benützen also die private methoden aus diesem
// grund muss ich  hier methoden benützen die public sind
// ein testcode
//int tauschwert=0;
//for (int i = sizeOfArray - 1; i >= 0; i-1) {
//    tauschwert=maxHeap.removeMin();
//     array[i] = tauschwert;
//}// kein -1 oder +1 verwenden führt zu fehlern