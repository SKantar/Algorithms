//
// C program for implementation of selection sort
// Created by skantar on 20/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);
void swap(int *a, int *b);


void selection_sort(int *array, int n){
    int min_ind, i, j;

    // One by one move boundary of unsorted subarray
    for(i = 0; i < n - 1; i++) {

        // Find the minimum element in unsorted array
        min_ind = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_ind])
                min_ind = j;
        }

        // Swap the found minimum element with the first element
        if(min_ind != i)
            swap(array+i, array+min_ind);
    }
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);
    selection_sort(array, n);
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
