#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    int *b = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);

    int *result = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (binary_search(b, 0, m - 1, a[i]) == -1) {
            if (count == 0 || result[count - 1] != a[i]) {
                result[count++] = a[i];
            }
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
