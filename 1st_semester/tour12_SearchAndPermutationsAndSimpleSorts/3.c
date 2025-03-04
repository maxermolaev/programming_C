#include <stdio.h> 
 
void InsertionSort(int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
    int key = arr[i]; 
    int j = i - 1; 
    while (key < arr[j] && j >= 0) { 
      arr[j + 1] = arr[j]; 
      --j; 
    } 
    arr[j + 1] = key; 
    }    
} 
 
int main() { 
    int n; 
    scanf("%d", &n); 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);   
    } 
    InsertionSort(arr, n); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]);   
    }   
    return 0; 
}

