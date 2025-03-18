#define _CRT_SECURE_NO_WARNINGS 
 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
 
typedef struct Node { 
    int key, count; 
    struct Node *left, *right; 
} node; 
 
 
node* createNode(int key) { 
    node* newNode = (node*)malloc(sizeof(node)); 
    newNode->key = key; 
    newNode->count = 1; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
 
 
node* insert(node* root, int key) { 
    if (root == NULL) 
        return createNode(key); 
    if (key == root->key) 
        root->count++; 
    else if (key < root->key) 
        root->left = insert(root->left, key); 
    else 
        root->right = insert(root->right, key); 
    return root; 
} 
 
 
int* sort(node* root, int* buf) { 
    if (root != NULL) { 
        buf = sort(root->left, buf); 
        for (int i = 0; i < root->count; i++) 
            buf[i] = root->key; 
        return sort(root->right, (buf+root->count)); 
    } 
    return buf; 
} 
 
 
node* build(node* tree, int* arr, int n) { 
    if (n == 0) 
        return tree; 
 
    int idx = rand() % n; 
    if (tree == NULL) 
        tree = createNode(arr[idx]); 
    else 
        insert(tree, arr[idx]); 
 
    build(tree, arr, idx); 
    build(tree, arr + idx + 1, n - idx - 1); 
    return tree; 
} 
 
 
int main() { 
    FILE* filein = fopen("input.bin", "rb"); 
    FILE* fileout = fopen("output.bin", "wb"); 
 
    int N; 
    srand((unsigned int)time(NULL)); 
 
    fread(&N, sizeof(int), 1, filein); 
 
    int* arr = (int*)malloc(sizeof(int) * N); 
    int* sorted_arr = (int*)malloc(sizeof(int) * N); 
 
    fread(arr, sizeof(int), N, filein); 
    node* tree = build(NULL, arr, N); 
    sort(tree, sorted_arr); 
    fwrite(sorted_arr, sizeof(int), N, fileout); 
 
    fclose(filein); 
    fclose(fileout); 
    return 0; 
}
