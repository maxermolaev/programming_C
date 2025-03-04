#include <stdio.h> 
 
int InvtabToPermut(int b[], int a[], int n) { 
    int used[n]; 
    for (int i = 0; i < n; i++) { 
        a[i] = 0;   
        used[i] = 0;  
    } 
    for (int i = 0; i < n; i++) { 
        int pos = b[i]; 
        int j = 0; 
        while (j < n) { 
            if (a[j] == 0) {   
                if (pos == 0) {  
                    a[j] = i + 1; 
                    break; 
                } else { 
                    pos--;   
                } 
            } 
            j++; 
        } 
        if (j == n) {  
            return 0; 
        } 
    } 
    return 1; 
} 
 
int main() { 
    FILE *in = fopen("input.txt", "r"); 
    FILE *out = fopen("output.txt", "w"); 
    int n; 
    fscanf(in, "%d", &n); 
    int b[n], a[n]; 
 
    for (int i = 0; i < n; i++) { 
        fscanf(in, "%d", &b[i]); 
    } 
 
    if (InvtabToPermut(b, a, n)) { 
        for (int i = 0; i < n; i++) { 
            fprintf(out, "%d ", a[i]); 
        } 
    } else { 
        fprintf(out, "NO"); 
    } 
 
    fclose(in); 
    fclose(out); 
    return 0; 
}

