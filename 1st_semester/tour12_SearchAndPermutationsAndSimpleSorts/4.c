#include <stdio.h> 
 
void Swap(int* a, int* b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
void ShakerSort(int arr[], int n) { 
    int left = 0; 
    int right = n - 1; 
    while (left < right) { 
        for (int i = left; i < right; i++) { 
            if (arr[i] > arr[i + 1]) { 
                Swap(&arr[i], &arr[i + 1]); 
            } 
        } 
        right--; 
        for (int i = right; i > left; i--) { 
            if (arr[i] < arr[i - 1]) { 
                Swap(&arr[i], &arr[i - 1]); 
            } 
        } 
        left++; 
    } 
} 
 
int main() { 
    int n; 
    scanf("%d", &n); 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);   
    } 
    ShakerSort(arr, n); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]);   
    }   
    return 0; 
}

