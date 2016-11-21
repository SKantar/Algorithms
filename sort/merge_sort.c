//
// C program for implementation of merge sort
// Created by skantar on 21/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);

void merge(int *array, int lower_bound, int mid, int upper_bound){
    int k;
    int n = upper_bound - lower_bound + 1;
    int *temp_array = (int*)malloc(sizeof(int) * n);
    int i = lower_bound;
    int j = mid + 1;

    for(k = 0; k < n; k++)
        if(i <= mid && (j > upper_bound || array[i] < array[j]))
            temp_array[k] = array[i++];
        else
            temp_array[k] = array[j++];

    for(k = 0; k < n; k++)
        array[k + lower_bound] = temp_array[k];

    free(temp_array);
}



void merge_sort(int array[], int lower_bound, int upper_bound) {
    if(lower_bound < upper_bound){
        int mid = (lower_bound + upper_bound) / 2;

        merge_sort(array, lower_bound, mid);
        merge_sort(array, mid + 1, upper_bound);

        merge(array, lower_bound, mid,  upper_bound);
    }
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);
    merge_sort(array, 0, n - 1);
    print_array(array, n);


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



