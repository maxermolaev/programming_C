#include <stdio.h> 
 
void Swap(int *a, int *b) { 
  int temp = *a; 
  *a = *b; 
  *b = temp; 
} 
 
void SelectSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        } 
        Swap(&arr[min_idx], &arr[i]); 
    } 
} 
 
int main() { 
    int n; 
    scanf("%d", &n); 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);   
    } 
    SelectSort(arr, n); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]);   
    }   
    return 0; 
}

