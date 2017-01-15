//
// C program for insertion sort
// Created by skantar on 20/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);
void swap(int *a, int *b);


void insertion_sort(int *array, int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j+1] = key;
    }
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);
    insertion_sort(array, n);
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
