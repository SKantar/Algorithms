//
// C program for implementation of binary search
// Created by skantar on 17/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_sorted_array(int n);
void print_array(int *array, int n);

int binary_search(int *array, int lower_bound, int upper_bound, int key){
    int mid = (lower_bound + upper_bound) / 2;
    if(lower_bound > upper_bound)
        return -1;
    if(array[mid] == key)
        return mid;
    else if(array[mid] < key)
        return binary_search(array, mid + 1, upper_bound, key);
    else if(array[mid] > key)
        return binary_search(array, lower_bound, mid - 1, key);
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_sorted_array(n);
    print_array(array, n);

    printf("Searching for %d : %d\n", 12, binary_search(array, 0, n - 1, 12));
    printf("Searching for %d : %d\n", 23, binary_search(array, 0, n - 1, 23));
    printf("Searching for %d : %d\n", 25, binary_search(array, 0, n - 1, 25));
    printf("Searching for %d : %d\n", 34, binary_search(array, 0, n - 1, 34));
    printf("Searching for %d : %d\n", 11, binary_search(array, 0, n - 1, 11));
    printf("Searching for %d : %d\n", 44, binary_search(array, 0, n - 1, 44));
    printf("Searching for %d : %d\n", 46, binary_search(array, 0, n - 1, 46));
}

void print_array(int *array, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int *generate_sorted_array(int n){
    time_t t;
    int *array = (int*)malloc(sizeof(int) * n);
    int i;

    /* Intializes random number generator */
    srand((unsigned) time(&t));
    array[0] = rand() % 10;

    for(i = 1; i < n; i++)
        array[i] = array[i - 1] + rand() % 10 + 1;

    return  array;
}



