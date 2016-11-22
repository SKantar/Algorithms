//
// C program for implementation of heap sort
// Created by skantar on 22/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);
void swap(int *a, int *b);

void heapify(int array[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    if (l < n && array[l] > array[largest])
        largest = l;

    if (r < n && array[r] > array[largest])
        largest = r;

    if (largest == i)
        return;

    swap(array + i, array + largest);
    heapify(array, n, largest);
}



void heap_sort(int array[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (i = n - 1; i >= 0; i--){
        swap(array, array + i);
        heapify(array, i, 0);
    }
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);
    heap_sort(array, n);
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



