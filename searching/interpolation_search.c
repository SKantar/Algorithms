//
// C program for implementation of interpolation search
// Created by skantar on 17/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_sorted_array(int n);
void print_array(int *array, int n);

int interpolation_search(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lower_bound = 0, upper_bound = n - 1;

    while (lower_bound <= upper_bound && x >= arr[lower_bound] && x <= arr[upper_bound])
    {
        int pos = (int)(lower_bound + (((double)(upper_bound - lower_bound) / (arr[upper_bound]-arr[lower_bound])) * (x - arr[lower_bound])));

        if (arr[pos] == x)
            return (int)pos;

        if (arr[pos] < x)
            lower_bound = pos + 1;
        else
            upper_bound = pos - 1;
    }
    return -1;
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_sorted_array(n);
    print_array(array, n);

    printf("Searching for %d : %d\n", 12, interpolation_search(array, n, 12));
    printf("Searching for %d : %d\n", 23, interpolation_search(array, n, 23));
    printf("Searching for %d : %d\n", 25, interpolation_search(array, n, 25));
    printf("Searching for %d : %d\n", 34, interpolation_search(array, n, 34));
    printf("Searching for %d : %d\n", 11, interpolation_search(array, n, 11));
    printf("Searching for %d : %d\n", 44, interpolation_search(array, n, 44));
    printf("Searching for %d : %d\n", 46, interpolation_search(array, n, 46));
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



