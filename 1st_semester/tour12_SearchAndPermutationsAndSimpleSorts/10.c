#include <stdio.h> 
#include <stdlib.h> 
 
int BinSearch(int *a, int l, int r, int x) { 
    int result = -1; 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        if (a[m] == x) { 
            result = m; 
            l = m + 1;  
        } else if (a[m] < x) { 
            l = m + 1; 
        } else { 
            r = m - 1; 
        } 
    } 
    return result; 
} 
 
int main() { 
    FILE *fin = fopen("input.txt", "r"); 
    FILE *fout = fopen("output.txt", "w"); 
    setbuf(fout, NULL);  
    int n, q; 
    fscanf(fin, "%d", &n); 
    int *a = (int *) malloc(n * sizeof(int)); 
    if (a == NULL) { 
        printf("Ошибка выделеня памяти\n"); 
        exit(1); 
    } 
    for (int i = 0; i < n; i++) { 
        fscanf(fin, "%d", &a[i]); 
    } 
    fscanf(fin, "%d", &q); 
    int prev_ans = 0; 
    for (int i = 0; i < q; i++) { 
        int x; 
        fscanf(fin, "%d", &x); 
        int y = x + prev_ans; 
        int idx = BinSearch(a, 0, n - 1, y); 
        fprintf(fout, "%d\n", idx); 
        prev_ans = idx; 
    } 
 
    free(a); 
    fclose(fin); 
    fclose(fout); 
    return 0; 
}

