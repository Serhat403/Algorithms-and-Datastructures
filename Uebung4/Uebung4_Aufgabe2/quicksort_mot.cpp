//
// Created by serha on 15.11.2021.
//

#include "quicksort_mot.hpp"
// in den folien hat partition ein int size im kopf jedoch wird er in den folien nicht benützt also unnötig
int partition(int *array, int left, int right) {
//low == left
// high == right
    int ipivot =  pivot(array, left, right);
    int i = left-1;
    for(int j= left; j<=right-1;j++){
        if(array[j]<=ipivot){
            i=(i+1);
            swap(&array[i],&array[j]);

        }
    }

    swap(&array[i+1], &array[right]);
    i = (i+1);
    return i;
}
// in den folien hat partition ein int size im kopf jedoch wird er in den folien nicht benützt also unnötig
int pivot(int array[], int left, int right) {

    int mitteIndex =  (int) (left + right)/2;
    int mitte =array[mitteIndex];
  //  if (array[right] < array[left]){
       // swapPivot(array, left, right);
  //    swapPivot(array, right, left);

  //  }

    if (array[left] > mitte){
       //swapPivot(array, mitte, left);
       //swapPivot(array, left, mitte);
       // const int zeiger = left;
       // array[left] = array[right];
       // array[right] = zeiger;
        int zeiger = array[left];
        array[left] = array[right];
        array[right] = zeiger;
    }

    if ( array[left] > array[right]){
        int zeiger = array[left];
        array[left] = array[right];
        array[right] = zeiger;
    }


       //swapPivot(array, right, mitte);
        //swapPivot(array, mitte, right);

    else if (mitte <= array[left]) {
        int zeiger = mitte;
        array[mitteIndex] = array[right];
        array[right] = zeiger;
    }
    else if  (mitte <= array[right]) {
        int zeiger = mitte;
        array[mitteIndex] = array[right];
        array[right] = zeiger;
}
    return array[right];

}
// swap für pivot
void swap(int *a, int *b){

    int temp =*a;

    *a=*b;

    *b=temp;
}
// ganz normale swap methode


void swapPivot(int array[], int left, int right){
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;

}

void quicksort_mot(int *array, int size, int left, int right) {

    if(left < right){
        int quicksortwert = partition(array, left, right);
        quicksort_mot(array, size, left, quicksortwert-1);
        quicksort_mot(array, size, quicksortwert+1, right);
    }
}
// hier ist die quicksort mot mit rekursion