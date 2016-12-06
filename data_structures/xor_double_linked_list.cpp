//
// Created by skantar on 06/12/16.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *npx;
}Node;

Node *XOR(Node* a, Node* b) {
    return (Node *) ((unsigned int) a ^ (unsigned int) b);
}

void insert(Node **head, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;

    node->npx = XOR(*head, NULL);
    if(*head){
        Node *next = XOR((*head)->npx, NULL);
        (*head)->npx = XOR(node, next);
    }

    *head = node;
}

void print(Node *head){
    Node *current = head, *prev = NULL, *next;
    printf ("Following are the nodes of Linked List: \n");
    while(current){
        printf ("%d ", current->data);
        next = XOR(prev, current->npx);

        prev = current;
        current = next;
    }
    printf("\n");
    current = prev;
    next = NULL;
    while(current){
        printf ("%d ", current->data);
        prev = XOR(current->npx, next);

        next = current;
        current = prev;
    }


}


int main(){

    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    print(head);


}
