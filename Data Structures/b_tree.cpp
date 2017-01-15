#include <cstdio>
#include <cstdlib>
#define MAXN 100
using namespace std;

typedef struct BNode{
    int keys[MAXN];             // An array of keys
    int t;                      // Minimum degree (defines the range for number of keys)
    int n;                      // Current number of keys
    bool leaf;                  // Is true when node is leaf. Otherwise false
    BNode *childs[MAXN + 1];    // An array of child pointers
}BNode;

void insert_ordered(int array[], int k){

}


void insert(BNode **root, int key){
    if(*root == NULL){
        BNode *node = (BNode*)malloc(sizeof(BNode));
        node->n = 1;
        node->keys[0] = key;
        node->leaf = true;
    }else{
        if((*root)->n == 2 * t - 1){


        }else{

        }
    }


}


int main(){
    BNode *root = NULL;

}
