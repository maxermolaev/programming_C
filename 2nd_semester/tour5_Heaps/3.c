#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    FILE* input = fopen("input.bin", "rb");
    FILE* output = fopen("output.bin", "wb");
    if (input == NULL || output == NULL) {
        printf("Ошибка открытия файлов.\n");
        return 1;
    }
    int N;
    fread(&N, sizeof(int), 1, input);
    int heap[MAX];
    for (int i = 0; i < N; i++) {
        fread(&heap[i], sizeof(int), 1, input);
    }
    heapSort(heap, N);
    for (int i = 0; i < N; ++i) {
        fwrite(&heap[i], sizeof(int), 1, output);
    }
    fclose(input);
    fclose(output);
    return 0;
}

