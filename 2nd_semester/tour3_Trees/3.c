#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct node { 
    int value; 
    struct node *left; 
    struct node *right; 
} tree; 
 
typedef tree Node; 
 
Node* createNode(int value) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) { 
        exit(EXIT_FAILURE); 
    } 
    newNode->value = value; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
 
Node* insert(Node* root, int value) { 
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
 
int leaves(Node* root) { 
    if (root == NULL) { 
        return 0; 
    } else if (root->left == NULL && root->right == NULL) { 
        return 1; 
    } else { 
        int leftLeaves = leaves(root->left); 
        int rightLeaves = leaves(root->right); 
        return leftLeaves + rightLeaves; 
    } 
} 
 
int main() { 
    Node* root = NULL; 
    int value; 
    while (scanf("%d", &value) == 1) { 
        root = insert(root, value); 
    } 
    int count = leaves(root); 
    printf("%d", count); 
    return 0; 
}

