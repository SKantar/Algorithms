#include <cstdio>
#include <cstdlib>
#include <cstring>

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_leaf;
}TrieNode;

TrieNode *make_node(){
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_leaf = false;

    for(int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(TrieNode *root, char *word){
    int length = strlen(word);

    TrieNode *tmp = root;

    for(int i = 0; i < length; i++){
        if(tmp->children[CHAR_TO_INDEX(word[i])] == NULL)
            tmp->children[CHAR_TO_INDEX(word[i])] = make_node();
        tmp = tmp->children[CHAR_TO_INDEX(word[i])];
    }

    tmp->is_leaf = true;
}

bool search(TrieNode *root, char *word){
    int length = strlen(word);
    TrieNode *tmp = root;

    for(int i = 0; i < length; i++){
        if(tmp->children[CHAR_TO_INDEX(word[i])] == NULL)
            return false;
        tmp = tmp->children[CHAR_TO_INDEX(word[i])];
    }

    return (tmp && tmp->is_leaf);
}



int main(){

    char output[][32] = {
        "Not present in trie",
        "Present in trie"
    };

    char keys[][8] = {
        "the",
        "a",
        "there",
        "answer",
        "any",
        "by",
        "bye",
        "their"
    };

    TrieNode *root = make_node();

    for (int i = 0; i < ARRAY_SIZE(keys); i++)
        insert(root, keys[i]);
    search(root, "the");
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, (char*) "the")] );
    printf("%s --- %s\n", "these", output[search(root, (char*) "these")] );
    printf("%s --- %s\n", "their", output[search(root, (char*) "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, (char*) "thaw")] );

    return 0;
}
