//
// C program for implementation of Bubble sort
// Created by skantar on 20/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);
void swap(int *a, int *b);


void bubble_sort(int *array, int n){
    int i, j;

    for(i = n; i > 0; i--){
        for(j = 0; j < i; j++){
            if(array[j] > array[j + 1])
                swap(array + j, array + j + 1);
        }
    }
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);
    bubble_sort(array, n);
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
