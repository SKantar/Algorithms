#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */
void push(Node **head, int data){
    Node *node = (Node*)malloc(sizeof(data));
    node->data = data;
    node->next = *head;

    *head = node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(Node **head, int data) {
    Node *current = *head;

    Node *node = (Node*)malloc(sizeof(data));
    node->data = data;
    node->next = NULL;


    if(current == NULL){
        *head = node;
        return;
    }

    while(current->next != NULL){
        current = current->next;
    }

    current->next = node;

}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, insert sorted into list  */
void insert(Node **head, int data) {

    Node *current = *head, *prev;
    Node *node = (Node*)malloc(sizeof(data));
    node->data = data;

    if (current == NULL || current->data > data){
        node->next = current;
        *head = node;
        return;
    }

    prev = current;
    current = current->next;

    while(current != NULL){
        if(current->data >= data){
            node->next = current;
            prev->next = node;
            return;
        }
        prev = current;
        current = current->next;
    }

    node->next = NULL;
    prev->next = node;

}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void remove(Node **head, int key){
    Node *current = *head, *prev;

    while(current->data == key){
        *head = current->next;
        free(current);
    }

    prev = current;
    current = current->next;

    while(current != NULL){
        if(current->data == key){
            prev->next = current->next;
            free(current);
        }
        else
            prev = current;
        current = prev->next;
    }

}

/* Counts no. of nodes in linked list */
int count(Node *head){
    int result = 0;
    while(head != NULL){
        head = head->next;
        result++;
    }
    return result;
}

/* Counts no. of nodes in linked list */
int recursive_count(Node *node){
    if(node == NULL)
        return 0;
    return recursive_count(node->next) + 1;
}

/* Checks whether the value x is present in linked list */
int search(Node *head, int x){
    while(head != NULL){
        if(head->data == x)
            return 1;
        head = head->next;
    }
    return 0;
}

/* Checks whether the value x is present in linked list */
int recursive_search(Node *head, int x){
    if(head == NULL)
        return 0;
    if(head->data == x)
        return 1;
    return recursive_search(head->next, x);
}

/* Function to reverse the linked list */
void reverse(Node **head){
    Node *prev = NULL, *current = *head, *next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/* Function to delete the entire linked list */
void clear(Node **node){
    Node *next;

    while ((*node)->next != NULL){
        next = (*node)->next;
        (*node)->data = next->data;
        (*node)->next = next->next;
        free(next);
    }

    free(*node);
    *node = NULL;
}

/* The function removes duplicates from a sorted list */
void remove_duplicates(Node *head){
    if(head == NULL)
        return;

    Node *next = head->next;
    while(next != NULL){
        if(next->data == head->data) {
            head->next = next->next;
            free(next);
        }
        else
            head = head->next;
        next = head->next;
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

//    push(&head, 5);
//    push(&head, 3);
//    push(&head, 1);
//
//    append(&head, 2);
//    append(&head, 4);
//    append(&head, 6);

    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 5);

    print(head);
    printf("\n");
    printf("%20s %d\n", "count iterative", count(head));
    printf("%20s %d\n", "count recursive", recursive_count(head));
    printf("%20s %d %s\n", "search iterative", 5,search(head, 5) ? "yes" : "no");
    printf("%20s %d %s\n", "search iterative", 10,search(head, 10) ? "yes" : "no");
    printf("%20s %d %s\n", "search iterative", 2,search(head, 2) ? "yes" : "no");
    printf("%20s %d %s\n", "search recursive", 5,recursive_search(head, 5) ? "yes" : "no");
    printf("%20s %d %s\n", "search recursive", 10,recursive_search(head, 10) ? "yes" : "no");
    printf("%20s %d %s\n", "search recursive", 2,recursive_search(head, 2) ? "yes" : "no");

    printf("\n");
    reverse(&head);
    print(head);

    printf("\n");
    remove_duplicates(head);
    print(head);

    printf("\n");
    clear(&head);
    print(head);



}