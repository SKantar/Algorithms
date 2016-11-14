//
// Created by skantar on 14/11/16.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node *next;
}Node;

void print(Node *node){
    while(node != NULL){
        printf("%d ", node->value);
        node = node->next;
    }
}

void insert_at_the_beginning(Node **node, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *node;

    *node = new_node;
}

void insert_at_the_end(Node **node, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if(*node == NULL){
        *node = new_node;
        return;
    }

    Node *tmp_node = *node;

    while(tmp_node->next != NULL)
        tmp_node = tmp_node->next;

    tmp_node->next = new_node;
}

void clear(Node **root){

    Node *tmp_node = *root, *del;

    while(tmp_node != NULL){
        del = tmp_node;
        tmp_node = tmp_node->next;
        printf("\nDelete: %d", del->value);
        free(del);
    }

    *root = NULL;
}


int main(){

    Node *root = NULL;
    insert_at_the_beginning(&root, 3);
    insert_at_the_beginning(&root, 5);
    insert_at_the_beginning(&root, 2);
    insert_at_the_end(&root, 4);
    insert_at_the_end(&root, 1);
    insert_at_the_end(&root, 2);
    insert_at_the_end(&root, 3);

    print(root);
    clear(&root);
    print(root);

    return 0;
}