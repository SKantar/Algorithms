//
// Created by skantar on 15/11/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next, *prev;
}Node;

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */
void push(Node **head, int data){
    Node *node = (Node *)malloc(sizeof(Node));

    node->data = data;
    node->prev = NULL;
    node->next = *head;

    if(*head != NULL)
        (*head)->prev = node;

    *head = node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(Node **head, int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if(*head == NULL){
        node->prev = NULL;
        *head = node;
        return;
    }

    Node *current = *head;
    while(current->next != NULL)
        current = current->next;

    current->next = node;
    node->prev = current;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void remove(Node **head, int key){
    Node *current = *head, *del;

    while(current->data == key){
        *head = current->next;
        (*head)->prev = NULL;
        free(current);
    }

    current = current->next;

    while(current != NULL){
        if(current->data == key){
            if(current->prev != NULL)
                current->prev->next = current->next;
            if(current->next != NULL)
                current->next->prev = current->prev;
            del = current;
            current = current->next;
            free(del);
        }
        else
            current = current->next;
    }

}

// This function prints contents of linked list starting from head
void print(Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}


int main(){
    Node *head = NULL;

    push(&head, 5);
    push(&head, 3);
    push(&head, 1);

    append(&head, 2);
    append(&head, 4);
    append(&head, 6);

    remove(&head, 4);
    remove(&head, 1);
    remove(&head, 6);

    print(head);
}
