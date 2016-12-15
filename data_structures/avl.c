//
// Created by skantar on 13/12/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
    int height;
}Node;


int max_n(int a, int b){
    return a < b ? b : a;
}

int height(Node *node)
{
    return node ? node->height : 0;
}

int get_balance(Node *node){
    return node ? height(node->left) - height(node->right) : 0;
}

void right_rotation(Node **y){

    Node *x = (*y)->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = (*y);
    (*y)->left = T2;

    //  Update heights
    (*y)->height = max_n(height((*y)->left), height((*y)->right))+1;
    x->height = max_n(height(x->left), height(x->right)) + 1;

    *y = x;
}

void left_rotation(Node **x){
    Node *y = (*x)->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = (*x);
    (*x)->right = T2;

    //  Update heights
    (*x)->height = max_n(height((*x)->left), height((*x)->right))+1;
    y->height = max_n(height(y->left), height(y->right))+1;

    *x = y;
}


void insert(Node **root, int data){

    if(*root == NULL){
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;

        *root = node;
        return;
    }

    if(data < (*root)->data)
        insert(&(*root)->left, data);
    else
        insert(&(*root)->right, data);

    (*root)->height = max_n(height((*root)->left), height((*root)->right)) + 1;

    int balance = get_balance(*root);

    if (balance > 1 && get_balance((*root)->left) >= 0)
        right_rotation(&(*root));
    else if (balance < -1 && get_balance((*root)->right) <= 0)
        left_rotation(&(*root));
    else if (balance > 1 && get_balance((*root)->left) < 0){
        left_rotation(&(*root)->left);
        right_rotation(&(*root));
    }
    else if (balance < -1 && get_balance((*root)->right) > 0){
        right_rotation(&(*root)->right);
        left_rotation(&(*root));
    }
}

int min(Node *root){
    if(root->left == NULL)
        return root->data;
    return min(root->left);
}

int max(Node *root){
    if(root->right == NULL)
        return root->data;
    return max(root->right);
}


void remove(Node **root, int data){
    if(*root == NULL)
        return;
    if(data < (*root)->data)
        remove(&(*root)->left, data);
    else if(data > (*root)->data)
        remove(&(*root)->right, data);
    else
    {
        if((*root)->left != NULL){
            data = max((*root)->left);
            (*root)->data = data;
            remove(&(*root)->left, data);
        }
        else if((*root)->right != NULL){
            data = min((*root)->right);
            (*root)->data = data;
            remove(&(*root)->right, data);
        }
        else{
            free(*root);
            *root = NULL;
            return;
        }
    }


    (*root)->height = max_n(height((*root)->left), height((*root)->right)) + 1;

    int balance = get_balance(*root);

    if (balance > 1 && get_balance((*root)->left) >= 0)
        right_rotation(&(*root));
    else if (balance < -1 && get_balance((*root)->right) <= 0)
        left_rotation(&(*root));
    else if (balance > 1 && get_balance((*root)->left) < 0){
        left_rotation(&(*root)->left);
        right_rotation(&(*root));
    }
    else if (balance < -1 && get_balance((*root)->right) > 0){
        right_rotation(&(*root)->right);
        left_rotation(&(*root));
    }
}





void print(Node *root){
    if(! root)
        return;
    print(root->left);
    printf("%d ", root->data, root->height);
    if(root->left)
        printf("Left: %d", root->left->data);
    if(root->right)
        printf(" Right: %d", root->right->data);
    printf("\n");
//    printf("%d ", root->data);
    print(root->right);
}

int main(){
    Node *root = NULL;
    insert(&root, 50);
    insert(&root, 51);
    insert(&root, 23);
    insert(&root, 24);
    insert(&root, 25);
    insert(&root, 22);
    insert(&root, 1);
    insert(&root, 102);
    insert(&root, 32);

    print(root);
    printf("\n");
//    printf("%d\n", min(root));
//    printf("%d\n", max(root));
//    printf("Balance: %d", get_balance(root));

    remove(&root, 22);
    remove(&root, 23);
    remove(&root, 24);
    remove(&root, 102);
    printf("\n");
    printf("\n");
    print(root);
    printf("\n");

    return 0;
}


