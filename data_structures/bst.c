//
// Created by skantar on 17/11/16.
//

#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a < b? b:a;
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

void insert(Node **root, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL){
        *root = node;
        return;
    }

    if(data > (*root)->data)
        insert(&((*root)->right), data);
    else
        insert(&((*root)->left), data);
}

void clear(Node *root){
    if(root == NULL)
        return;
    clear(root->left);
    clear(root->right);
    free(root);
}

void print(Node *root){
    if(root == NULL)
        return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Node *min_node(Node *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

/* Given a non-empty binary search tree, return the node with maximum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Node *max_node(Node *root){
    while(root->right != NULL)
        root = root->right;
    return root;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
Node *remove(Node *root, int key) {

    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = remove(root->left, key);
    else if(key > root->data)
        root->right = remove(root->right, key);
    else {
        if(root->left != NULL) {
            root->data = max_node(root->left)->data;
            root->left = remove(root->left, root->data);
        }
        else if(root->right != NULL) {
            root->data = min_node(root->right)->data;
            root->right = remove(root->right, root->data);
        }
        else {
            free(root);
            return NULL;
        }
    }


}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node** pre, Node** suc, int key) {
    if (root == NULL)
        return;
    if (root->data == key) {
        if (root->left != NULL)
            *pre = max_node(root->left);
        if (root->right != NULL)
            *suc = min_node(root->right);
    } else if (root->data < key){
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else{
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

int isBST(Node* node)
{
    if (node == NULL)
        return 1;
    if (node->left != NULL && node->left->data > node->data)
        return 0;
    if (node->right != NULL && node->right->data < node->data)
        return 0;
    return isBST(node->left) && isBST(node->right);
}

/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
Node *lca(Node* root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data > n1 && root->data > n2)
            root = root->left;
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else break;
    }
    return root;
}

/*The second parameter is to store the height of tree.
   Initially, we need to pass a pointer to a location with value
   as 0. So, function should be used as follows:

   int height = 0;
   struct node *root = SomeFunctionToMakeTree();
   int diameter = diameterOpt(root, &height); */
int diameterOpt(Node *root, int* height){
    int lh = 0, rh = 0;

    int ldiameter = 0, rdiameter = 0;

    if(root == NULL)
    {
        *height = 0;
        return 0;
    }

    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int main(){
    Node *root = NULL, *pre = NULL, *suc = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 20);
    insert(&root, 1);
    insert(&root, 110);
    insert(&root, 40);
    insert(&root, 18);
    insert(&root, 2);

    print(root);
    findPreSuc(root, &pre, &suc, 40);
    if(pre != NULL)
        printf("\n Pre: %d ", pre->data);
    if(suc != NULL)
        printf("\n Suc: %d", suc->data);

    printf("\nis BST %d", isBST(root));


    printf("\nLCA %d", lca(root, 40, 18)->data);

//    root = remove(root, 18);
//    root = remove(root, 3);
//    root = remove(root, 5);
//    root = remove(root, 2);
//    remove(&root, 5);
//    remove(&root, 2);
//
//    printf("\n");
//    print(root);
//    clear(root);
//    root = NULL;
//    print(root);

//    printf("\n%d\n", min_node(root)->data);



    return 0;
}
