#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
typedef struct node { 
    char word[50]; 
    struct node *left; 
    struct node *right; 
} tree; 
 
typedef tree Node; 
 
Node* createNode(const char* word) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) { 
        exit(EXIT_FAILURE); 
    } 
    strcpy(newNode->word, word); 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
Node* insert(Node* root, const char* word) { 
    if (root == NULL) { 
        return createNode(word); 
    } 
 
    int cmp = strcmp(word, root->word); 
    if (cmp < 0) { 
        root->left = insert(root->left, word); 
    } else if (cmp > 0) { 
        root->right = insert(root->right, word); 
    } 
 
    return root; 
} 
 
void infix(Node* root) { 
    if (root != NULL) { 
        infix(root->left); 
        printf("%s\n", root->word); 
        infix(root->right); 
    } 
} 
 
int main() { 
    Node* root = NULL; 
    char word[50]; 
    while (scanf("%49s", word) == 1) { 
        root = insert(root, word); 
    } 
    infix(root); 
    return 0; 
}

