#define _CRT_SECURE_NO_WARNINGS 
 
#include <stdio.h> 
#include <stdlib.h> 
 
 
void build(int* tree, int* arr, int i, int l, int r) { 
    if (l > r) { 
        tree[i] = INT_MIN; 
        return; 
    } 
    if (l == r) { 
        tree[i] = arr[l]; 
        return; 
    } 
    int middle = (l + r) / 2; 
    build(tree, arr, 2 * i + 1, l, middle); 
    build(tree, arr, 2 * i + 2, middle + 1, r); 
    tree[i] = (tree[2 * i + 1] > tree[2 * i + 2]) ? tree[2 * i + 1] : tree[2 * i + 2]; 
} 
 
 
int get(int* tree, int i, int l, int r, int tl, int tr) { 
    if (l >= tl && r <= tr) { 
        return tree[i]; 
    } 
    if (r < tl || l > tr) { 
        return INT_MIN; 
    } 
    int middle = (l + r) / 2; 
    int a = get(tree, i * 2 + 1, l, middle, tl, tr); 
    int b = get(tree, i * 2 + 2, middle + 1, r, tl, tr); 
    return (a > b) ? a : b; 
} 
 
 
int main() { 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int n; 
    scanf("%d\n", &n); 
    int* arr = (int*)malloc(sizeof(int) * n); 
    int* tree = (int*)malloc(sizeof(int) * 4 * n); 
    for (int i = 0; i < n; ++i) 
        scanf("%d", &arr[i]); 
    char skip; 
    scanf("%c", &skip); 
    build(tree, arr, 0, 0, n - 1); 
    int l = 0, r = 0; 
    for (int i = 0; i < 2 * n - 1; ++i) { 
        char c; 
        scanf("%c", &c); 
        if (c == 'L') 
            l+=1; 
        else 
            r+=1; 
        printf("%d\n", get(tree, 0, 0, n - 1, l, r - 1)); 
    } 
    return 0; 
}
