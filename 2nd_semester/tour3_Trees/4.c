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
 
void count_at_level(Node* root, int level, int currentLevel, int* count) { 
    if (root == NULL) { 
        return; 
    } 
 
    if (currentLevel == level) { 
        (*count)++; 
        return; 
    } 
 
    count_at_level(root->left, level, currentLevel + 1, count); 
    count_at_level(root->right, level, currentLevel + 1, count); 
} 
 
int main() { 
    Node* root = NULL; 
    int level, value; 
    scanf("%d", &level); 
    while (scanf("%d", &value) == 1) { 
        root = insert(root, value); 
    } 
    int nodesCount = 0; 
    count_at_level(root, level, 0, &nodesCount); 
    printf("%d", nodesCount); 
    return 0; 
}

