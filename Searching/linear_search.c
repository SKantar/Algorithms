//
// C program for implementation of linear search
// Created by skantar on 17/11/16.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int *generate_array(int n);
void print_array(int *array, int n);

int linear_search(int *array, int n, int key){
    int i;
    for(i = 0; i < n; i++)
        if(array[i] == key)
            return i;
    return -1;
}

int main()
{
    int n, i, *array;
    n = 10;

    array = generate_array(n);
    print_array(array, n);

    printf("Searching for %d : %d\n", 12, linear_search(array, n, 12));
    printf("Searching for %d : %d\n", 23, linear_search(array, n, 23));
    printf("Searching for %d : %d\n", 25, linear_search(array, n, 25));
    printf("Searching for %d : %d\n", 34, linear_search(array, n, 34));
    printf("Searching for %d : %d\n", 11, linear_search(array, n, 11));
    printf("Searching for %d : %d\n", 44, linear_search(array, n, 44));
    printf("Searching for %d : %d\n", 46, linear_search(array, n, 46));
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




