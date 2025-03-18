#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct node { 
    int value; 
    struct node *left; 
    struct node *right; 
} tree; 
 
tree* createNode(int value) { 
    tree* newNode = (tree*)malloc(sizeof(tree)); 
    if (newNode == NULL) { 
        exit(EXIT_FAILURE); 
    } 
    newNode->value = value; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
tree* insert(tree* root, int value) { 
    if (root == NULL) { 
        return createNode(value); 
    } 
 
    if (value < root->value) { 
        root->left = insert(root->left, value); 
    } else if (value > root->value) { 
        root->right = insert(root->right, value); 
    } 
 
    return root; 
} 
 
void pref(tree* t) { 
    if (t != NULL) { 
        printf("%d ", t->value); 
        pref(t->left); 
        pref(t->right); 
    } 
} 
 
void reverse(tree* t) { 
    if (t != NULL) { 
        reverse(t->left); 
        reverse(t->right); 
        printf("%d ", t->value); 
    } 
} 
 
int main() { 
    tree* root = NULL; 
    int value; 
    while (scanf("%d", &value) == 1) { 
        root = insert(root, value); 
    } 
    pref(root); 
    printf("\n"); 
    reverse(root); 
 
    return 0; 
}

