//
// Created by skantar on 17/11/16.
//`

#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a < b? b:a;
#define N 10


void quick_sort(int array[], int lower_bound, int upper_bound){
    int a = lower_bound;
    int b = upper_bound;
    int pivot = array[(a + b) / 2];


    while(a <= b){
        while(array[a] < pivot)
            a++;
        while(array[b] > pivot)
            b--;
        if(a <= b){
            int t = array[a];
            array[a] = array[b];
            array[b] = t;
            b--;
            a++;
        }

    if(lower_bound < b)
        quick_sort(array, lower_bound, b);
    if(upper_bound > a)
        quick_sort(array, a, upper_bound);
}


int main(){
    int array[N] = {2, 3, 1, 6, 8, 7, 1, 2, 9, 10};


    quick_sort(array, 0, N-1);

    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }



    return 0;
}


