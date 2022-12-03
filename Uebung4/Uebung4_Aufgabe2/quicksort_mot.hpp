//
// Created by serha on 15.11.2021.
//

#ifndef UEBUNG4_AUFGABE2_QUICKSORT_MOT_HPP
#define UEBUNG4_AUFGABE2_QUICKSORT_MOT_HPP

// ich brauche eine void quicksort
// eine int partition
//eine int swap
// eine pivot methode

void quicksort_mot(int array[], int size, int left, int right);
int partition(int array[], int left, int right);
int pivot(int array[], int left, int right) ;
void swap(int *x, int *y);
void swapPivot(int array[], int left, int right);





#endif //UEBUNG4_AUFGABE2_QUICKSORT_MOT_HPP
