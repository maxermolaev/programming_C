#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *array;
    int capacity;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;
    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

void push(MinHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf(".\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int pop(MinHeap* heap) {
    if (heap->size <= 0)
        return 1000000;

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int root = heap->array[0];

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    heapify(heap, 0);

    return root;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int Q;
    scanf("%d", &Q);

    MinHeap* heap = createMinHeap(2 * Q);

    for (int i = 0; i < Q; i++) {
        char operation[5];
        scanf("%s", operation);

        if (strcmp(operation, "push") == 0) {
            int num;
            scanf("%d", &num);
            push(heap, num);
        } else if (strcmp(operation, "pop") == 0) {
            int min = pop(heap);
            if (min == 1000000) {
                printf("Heap is empty\n");
            } else {
                printf("%d\n", min);
            }
        }
    }

    free(heap->array);
    free(heap);

    return 0;
}

