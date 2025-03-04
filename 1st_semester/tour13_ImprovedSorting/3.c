#include <stdio.h>
#include <stdlib.h>

int cmp_func(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp_func);

    int k = 0;

    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] != arr[i-1]) {
            k++;
        }
    }

    printf("%d\n", k);

    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] != arr[i-1]) {
            printf("%d\n", arr[i]);
            k++;
        }
    }
    free(arr);
    return 0;
}
