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
 
int height(Node* root) { 
    if (root == NULL) { 
        return -1; 
    } else { 
        int leftHeight = height(root->left); 
        int rightHeight = height(root->right); 
 
        if (leftHeight > rightHeight) { 
            return leftHeight + 1; 
        } else { 
            return rightHeight + 1; 
        } 
    } 
} 
 
int main() { 
    Node* root = NULL; 
    int value; 
    while (scanf("%d", &value) == 1) { 
        root = insert(root, value); 
    } 
    int treeHeight = height(root); 
    printf("%d", treeHeight); 
    return 0; 
}


