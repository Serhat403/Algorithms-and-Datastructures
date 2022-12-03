#include <iostream>
#include "quicksort_mot.hpp"

int main() {
    using namespace std;

    // Übung 4 Aufgabe 2 Test

    int array[]={10,9,8,7,6,5,4,3,2,1};
    int groesse = sizeof(array) / sizeof(array[0]);
    quicksort_mot(array, groesse, 0, groesse - 1);


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

    cout <<"Test2"<< endl;

    int array2[]={7,8,10,2,26,4,12,5,3,16,11,6,13,19};
    int groesse2 = sizeof(array2) / sizeof(array2[0]);
    quicksort_mot(array2, groesse2, 0, groesse2 - 1);

    cout <<array2[0]<< endl;
    cout <<array2[1]<< endl;
    cout <<array2[2]<< endl;
    cout <<array2[3]<< endl;
    cout <<array2[4]<< endl;
    cout <<array2[5]<< endl;
    cout <<array2[6]<< endl;
    cout <<array2[7]<< endl;
    cout <<array2[8]<< endl;
    cout <<array2[9]<< endl;
    cout <<array2[10]<< endl;
    cout <<array2[11]<< endl;
    cout <<array2[12]<< endl;
    cout <<array2[13]<< endl;

}
