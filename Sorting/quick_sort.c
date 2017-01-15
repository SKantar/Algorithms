//
// C program for implementation of quick sort
// Created by skantar on 17/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);
void swap(int *a, int *b);


void quick_sort(int array[], int lower_bound, int upper_bound) {
    int a = lower_bound;
    int b = upper_bound;
    int pivot = array[(a + b) / 2];


    while (a < b) {
        while (array[a] < pivot)
            a++;
        while (array[b] > pivot)
            b--;
        if (a <= b) {
            int t = array[a];
            array[a] = array[b];
            array[b] = t;
            b--;
            a++;
        }
    }



    if (lower_bound < b)
        quick_sort(array, lower_bound, b);
    if (upper_bound > a)
        quick_sort(array, a, upper_bound);
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);
    quick_sort(array, 0, n - 1);
    print_array(array, n);


}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *array, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int *generate_array(int n){
    time_t t;
    int *array = (int*)malloc(sizeof(int) * n);
    int i;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    for(i = 0; i < n; i++)
        array[i] = rand() % 50;

    return  array;
}



