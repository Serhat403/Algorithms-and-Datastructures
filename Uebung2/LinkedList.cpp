//
// Created by serha on 21.10.2021.
//

#include "LinkedList.hpp"

using namespace std;


LinkedList::LinkedList() {
    sizeOfList = 0;
    head = nullptr;
    tail = nullptr;
}
// Konstruktor in dem Standard mäßig der, head, tail, sizeOfList eingeleitet werden

int LinkedList::size() const {
    return sizeOfList;
}
// die sizeOfList, ist eine Variable die mit jeder dazu geaddeten Node wächst oder  mit jeder removed reduziert wird
//gibt die anzahl an ListNodes also Werte in einer Liste an, und in dieser Methode wird sie zurückgegeben

void LinkedList::printElements(){

    ListNode *current = head;

    if (current == nullptr){
        cout << "Liste ist leer" << endl;
    return;
    }

    cout << "Listenwerte:";

    for(int i =0; i < sizeOfList;i++){
        cout << current->element << ":";
        current = current->next;
    }

}
// eine for schleife die solange geht wie sizeOfList werte hat
// danach werden die einzelnen werte auf der konsole ausgegeben
//current wird auf den nächsten gezeigt

void LinkedList::addFirst(int data){

    auto *const node = new ListNode(data, head);
    head = node;

    if (sizeOfList == 0){

        tail = node;
    }
    sizeOfList++;

    //node->element = data;
    //node->next = head;
    //head = node;
}
// also ich mache ein node, dieser Node soll der head sein also lasse ich head auf ihne zeigen,
//falls die liste leer ist muss tail auch auf ihn zeigen, und sizeOfList steigt an um 1

void LinkedList::addLast(int data) {

    auto *const node = new ListNode(data);

    if (head == nullptr) {
        head = node;
        tail = node;
        sizeOfList++;
        return;
    }else {
        tail->next = node;
        tail = node;
        sizeOfList++;
    }

}
// also falls head null ist quasi die liste ist leer, könnte man auch machen indem man sagt sizeOflist ==0
//aber wollte es so machen, falls das der fall wäre soll head und tail auf das neue node zeigen,
// falls es bereits werte gibt, zeigt tail.next auf das neue node, und dannach soll tail auf das neue node zeigen,
// somit ist tail der letzte werte und der letzte wert wäre halt der neue Node

int LinkedList::getFirst(){

    if (head != nullptr)
    {

        return head->element;

    }

    else{

        return -1;
    }
}
//  ich überprüfe mit dem ersten if ob die liste nicht leer ist, also ob die liste werte hat,
// falls ja returne ich einfach das element von head,
// mit dem else also wenn die liste leer ist wird ein -1 returned

int LinkedList::getLast(){
    if (tail != nullptr){

        return tail->element;
    }


    else{
        return -1;
    }

}
// hier überprüfe ich nochmal ob die liste leer ist oder nicht falls sie nicht leer ist
// gebe ich einfach den wert von tail zurück
// ansonsten wird im else ein -1 zurückgegeben

void LinkedList::sortASC() {
    struct ListNode *i;
    struct  ListNode *j;
    int speicher;
    ListNode *start = head;
    if (sizeOfList == 0)
        return;
    for (i = start; i->next != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j=j->next) {
            if (i->element > j->element) {
                speicher = i->element;
                i->element = j->element;
                j->element = speicher;
            }
        }
    }
}
// also die ListNode i und j sind quasi zeiger mit denen ich arbeite,
// das struct davor wurde vom System empfohlen und stand in den folien so
// so ich überprüfe mit dem if ob die liste leer ist falls ja einfach return
// Kurzversion: danach habe ich zwei for schleifen mit denen ich i und j miteinander vergleiche
// i ist am header und j nach dem header
// erst kommt die erste forschleife mit dem ersten wert der wird in der zweiten forschleife durch alle anderen vergliechen
// danach der verlgeich fals i höher als j dann kommt j vor i
// und der speicher ist ein zwischenspeicher für den hohen wert

void LinkedList::sortDES(){
    struct ListNode *i;
    struct  ListNode *j;
    int speicher;
    ListNode *start = head;
    if (sizeOfList == 0)
        return;
    for (i = start; i->next != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j=j->next) {
            if (i->element < j->element) {
                speicher = i->element;
                i->element = j->element;
                j->element = speicher;
            }
        }
    }
}
// sort desc ist genau wie sort ASC
// mit dem unterschied dass die umgekehrte logik verwende
// also ich ändere in der if bedingung das größer zeichen zu einem kleiner zeichen

void LinkedList::addSorted(int val){
    addFirst(val);
    sortASC();

}
// ich habe den Professor gefragt und er hat gesagt ich darf dieses Problem so lösen
// also ich habe das jetz so verstanden dass ein wert in der richtigen reihenfolge in eine liste rein soll
// deswegen habe ich ein add methode genommen und danach die liste sortiert
// sizeOfList wird bereits in addfirst erhöht

LinkedList::~LinkedList() {
    clear();
}
// ich habe das so verstanden das hier eine löschung der liste stattfinden soll und geht ja über clear()
// deswegen einfach aufgerufen

void LinkedList::clear(){

    if(head == nullptr || sizeOfList==0){
        return;
    }
    const ListNode *current;
    current = head;
    const ListNode *nextvoncurrent;
    nextvoncurrent=current->next;

    while (current->next != nullptr) {
        delete current;
        current=nextvoncurrent;
        nextvoncurrent=current->next;
    }
    //  der grund wieso man das so lösen muss
    // ist weil wenn ich current lösche und es als nächstes current=current->next
    //eingebe kommt es zu einer fehlermeldung mit allocated memory
    // also es funktioniert nicht weil es darauf nicht zugreifen kann weil es vorher gelsöcht wurde
    // deswegen muss man das so lösen
    this->head=nullptr;
    this->tail=nullptr;
    this->sizeOfList=0;
}
// also erster fall fall die liste leer ist return
// im 2 schritt lösche ich mit einer schleife im speicher die daten für die nodes
// im dritten schritt setze ich ich tail, head, sizeOfList auf 0
//

int LinkedList::getAt(int index){

    if (sizeOfList == 0)
    {
        return -1;
    }

    if (index < 0 || index > sizeOfList)
    {

        return -1;
    }

    ListNode *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->element;
}
// also ich überprüfe erstmal ob die liste leer ist falls ja return minus1
// danach ob das index kleiner als 0 oder größer als sizeOfList ist also ob der index höher ist
// als die anzahl an stellen in meiner lsite falls ja return minus 1
// so falls die if alse sind wird ein zeiger erstellt der geht mit einer for schleife über die liste bis er ander richtige stelle
// angekommen ist und an der stelle wo der index ist gibt er dann mit return den index wert

bool LinkedList::contains(int value) {

    if(sizeOfList==0)
    {
        return false;
    }

    ListNode *current;
    current = head;

    while (current != nullptr) {

        if(current->element==value){
            return true;
        }
        current = current->next;

    }
return false;
}

// erstmal überprüfen ob die liste leer ist falls ja return false
// danach current zeigt auf head
// danach while schleife soll durchgehen solange current nicht auf null zeigt
// if bedingungen falls element gleich value return true
// sonst return fals

    int LinkedList::removeFirst(){

        if(sizeOfList==0)
        {
            return -1;
        }

        if (head != nullptr) {
            const int first = head->element;
            struct ListNode *temp =head;
            head =temp->next;
            delete temp;
            sizeOfList--;
            return first;
        }

        return -1;

        //const int first = head->element;
        //struct ListNode *temp =head;
        //head =temp->next;
       // delete temp;
        // sizeOfList--;
        //  return first;

    }
    // erste Überprüfung falls die liste 0 werte hat return -1
    // zweite überprüfung falls head nicht zu null ptr also nicht komplett leer ist
    // also was beinhaltet wird first wird der element von head übergeben
    // danach zeigt temp auf head, danach wird zu head gesagt zeig auf das neue head also temp.next
    // danach wird temp gelöscht
    // liste wird gekürzt um 1
    // first wird zurückgegeben

int LinkedList::removeLast(){
  const int last = tail->element;
    if(sizeOfList==0)
    {
        return -1;
    }
    struct ListNode *temp = head;
    struct ListNode *temp2 = head;
    while(temp->next!=nullptr){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=nullptr;
    delete temp;
    tail=temp2;
    delete temp2;
    sizeOfList--;
    return last;
}
//temp und temp2 sind zeiger die helfen soll den letzten node zu kriegen
// dabei temp2 ist immer eins hinter temp sobald der letzte Node erreicht wird
// der letzte node wird gelöscht, tail zeigt auf temp2 also den vorletzte der zum letzten wird
// temps werden ebenfalls gelöscht
//last wurde vorher tail.element übergeben und wird returned
int LinkedList::removeAt(int index){
    int elementAt;
    if (sizeOfList == 0) {
        return -1;
    }
    if (index < 0 || index > sizeOfList-1){
        return -1;
    }// -1 weil der index bei 0 anfängt
    if (index == 0)
    {
        return removeFirst();
    }
    if (index == (sizeOfList-1)) {
        return removeLast();
    }
    // index fängt bei 0 an deswegen bei sizeOfList -1
    struct ListNode *current =head;
    struct ListNode *prev=head;
    while(index!=1){
        prev=current;
        current=current->next;
        index--;
    }
    prev->next=current->next;
    elementAt=current->element;
    current=nullptr;
    delete current;
    //muss man  vorher current auf null setzen
    sizeOfList--;
    return elementAt;
}
// erstmal werden ein paar bedingungen überprüft wie wenn die liste leer ist return-1
//falls der index kleiner ist als 0 oder größer als die vorhanden und benützen index der list ist
//bei index 0 wird removefirst benützt ber letzten index stelel einfach removelast
//so jetzt haben wir einen current und prev
// die helfen sich gegenseitig auf die stlele hinzukommen
// mit dre schleife wird der index runtergezählt
// elementAt ist halt der wert der indexstelle
// und wird dann am ende returned