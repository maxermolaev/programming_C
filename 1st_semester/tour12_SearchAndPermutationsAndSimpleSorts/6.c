#include <stdio.h> 
 
void Swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
void Reverse(int a[], int start, int end) { 
    while (start < end) { 
        Swap(&a[start], &a[end]); 
        start++; 
        end--; 
    } 
} 
 
void NextPermut(int a[], int n) { 
    int i = n - 2; 
    while (i >= 0 && a[i] >= a[i + 1]) { 
        i--; 
    } 
    if (i >= 0) { 
        int j = n - 1; 
        while (a[j] <= a[i]) { 
            j--; 
        } 
        Swap(&a[i], &a[j]); 
    } 
    Reverse(a, i + 1, n - 1); 
} 
 
int main() { 
    int n; 
    scanf("%d", &n); 
    int a[1000]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
    } 
    NextPermut(a, n); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", a[i]); 
    } 
    return 0; 
}

