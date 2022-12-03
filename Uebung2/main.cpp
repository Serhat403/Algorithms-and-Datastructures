#include <iostream>
#include "LinkedList.hpp"

int main() {

    using namespace std;
    const auto list = new LinkedList();

    list->addFirst(1);
    list->addFirst(2);
    list->addFirst(3);
    list->addFirst(4);

    list->printElements();
    int groesseliste;
    groesseliste=list->size();
    cout << "die größe der liste 1 ist: " << groesseliste << endl;

    const auto list2 = new LinkedList();

    list2->addLast(1);
    list2->addLast(2);
    list2->addLast(3);
    list2->addLast(4);
    list2->printElements();

    int groesseliste2;
    groesseliste2=list2->size();
    cout << "die größe der liste 2 ist: " << groesseliste2 << endl;

    const auto list3 = new LinkedList();

    list3->addLast(4);
    list3->addLast(3);
    list3->addLast(2);
    list3->addLast(1);

    cout<<"Liste bevor sie sortiert wurde:"<<endl;
    list3->printElements();
    cout<<"Liste nachdem sie sortiert wurde:"<<endl;
    list3->sortASC();
    list3->printElements();

    int groesseliste3;
    groesseliste3=list3->size();
    cout << "die größe der liste 3 ist: " << groesseliste3 << endl;

    cout<< "jetzt kommt get first:";
    cout << list3->getFirst()<< endl;
    cout<< "jetzt kommt get last:";
    cout << list3->getLast()<< endl;

    const auto list4 = new LinkedList();

    list4->addLast(1);
    list4->addLast(2);
    list4->addLast(3);
    list4->addLast(4);

    cout<<"Liste4 bevor sie sortiert wurde:"<<endl;
    list4->printElements();
    cout<<"Liste4 nachdem sie sortiert wurde:"<<endl;
    list4->sortDES();
    list4->printElements();

    const auto list5 = new LinkedList();

    list5->addLast(1);
    list5->addLast(3);
    list5->addLast(4);
    list5->addLast(2);

    cout<<"/n"<<endl;
    cout<<"Liste5:"<<endl;
    cout<<"/n"<<endl;
    list5->addSorted(5);
    list5->printElements();

    const auto list6 = new LinkedList();

    list6->addLast(1);
    list6->addLast(3);
    list6->addLast(4);
    list6->addLast(2);

    cout<<"/n"<<endl;
    cout<<"Liste6 vor dem löschen:"<<endl;
    cout<<"/n"<<endl;
    list6->printElements();
    cout<<"/n"<<endl;
    list6->clear();
    cout<<"Liste6 nach dem  löschen:"<<endl;
    list6->printElements();

    const auto list7 = new LinkedList();

    list7->addLast(1);
    list7->addLast(2);
    list7->addLast(3);
    list7->addLast(4);

    cout<<"Liste7 index 1:"<<list7->getAt(0)<<endl;
    cout<<"Liste7 index 2:"<<list7->getAt(1)<<endl;
    cout<<"Liste7 index 3:"<<list7->getAt(2)<<endl;
    cout<<"Liste7 index 4:"<<list7->getAt(3)<<endl;

   cout<<"Liste7 enthählt die Zahl 1? True/False also 1 oder 0:"<<list7->contains(1)<<endl;
   cout<<"Liste7 enthählt die Zahl 2? True/False also 1 oder 0:"<<list7->contains(2)<<endl;
   cout<<"Liste7 enthählt die Zahl 5? True/False also 1 oder 0:"<<list7->contains(5)<<endl;
   cout<<"Liste7 enthählt die Zahl 4? True/False also 1 oder 0:"<<list7->contains(4)<<endl;
   cout<<"Liste7 enthählt die Zahl 5? True/False also 1 oder 0:"<<list7->contains(5)<<endl;


    const auto list8 = new LinkedList();
    list8->addLast(1);
    list8->addLast(2);
    list8->addLast(3);
    list8->addLast(4);

    //remove first
    cout<<"Erstes gelöschtes Element Liste 8:"<<endl;
    cout<<list8->removeFirst()<<endl;
    cout<<"Liste8 nach dem  löschen des ersten Wertes:"<<endl;
    list8->printElements();
    cout<<"/n"<<endl;

    cout<<"Letztes gelöschtes Element Liste 8:"<<endl;
    cout<<list8->removeLast() <<endl;
    cout<<"Liste8 nach dem  löschen des letzten Elements:"<<endl;
    cout<<"/n"<<endl;
    list8->printElements();
    cout<<"/n"<<endl;
    const auto list9 = new LinkedList();

    list9->addLast(1);
    list9->addLast(2);
    list9->addLast(3);
    list9->addLast(4);

    cout<<"Liste9 index 1:"<<list7->getAt(0)<<endl;
    cout<<"Liste9 index 2:"<<list7->getAt(1)<<endl;
    cout<<"Liste9 index 3:"<<list7->getAt(2)<<endl;
    cout<<"Liste9 index 4:"<<list7->getAt(3)<<endl;

    cout<<"Liste9 vor dem löschen:"<<endl;
    cout<<"/n"<<endl;
    list9->printElements();
    cout<<"/n"<<endl;
    cout<<"gelöschtes Element an der Stelle 0 von der  Liste 9:"<<endl;
    cout<<"/n"<<endl;
    cout<<list9->removeAt(0) <<endl;
    cout<<"/n"<<endl;
    cout<<"Liste9 nach dem  löschen des Elementes an der Stelle 0";
    cout<<"/n"<<endl;
    list9->printElements();

    return 0;


}
