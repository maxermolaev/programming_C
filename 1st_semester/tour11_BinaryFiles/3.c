#include <stdio.h> 
#include <stdlib.h> 
 
int partition(int* a, int n, int pivot){ 
    int* b = (int*)malloc(sizeof(int) * n); 
    int* c = (int*)malloc(sizeof(int) * n); 
    int indexB = 0, indexC = 0, b1 = 0, c1 = 0; 
    for (int i = 0; i < n; ++i){ 
        if (a[i] < pivot){ 
            b[indexB++] = a[i]; 
        } 
        else if (a[i] > pivot){ 
            c[indexC++] = a[i]; 
        } 
        else{ 
            if (b1 <= c1){ 
                b[indexB++] = a[i], b1++; 
            } 
            else{ 
                c[indexC++] = a[i], c1++; 
            } 
        } 
    } 
    for (int i = 0; i < indexB; ++i){ 
        a[i] = b[i]; 
    } 
    for (int i = 0; i < indexC; ++i){ 
        a[indexB + i] = c[i]; 
    } 
    free(b); 
    free(c); 
    return indexB; 
} 
 
int main(){ 
    FILE* filein = fopen("input.bin", "rb"); 
    FILE* fileout = fopen("output.bin", "wb"); 
    int N, p; 
    fread(&N, sizeof(int), 1, filein); 
    fread(&p, sizeof(int), 1, filein); 
    int* mass = (int*)malloc(sizeof(int)*N); 
    for (int i = 0; i < N; ++i){ 
        fread(&mass[i], sizeof(int), 1, filein); 
    } 
    int need = partition(mass, N, p); 
    fwrite(&need, sizeof(int), 1, fileout); 
    for (int i = 0; i < N; i++){ 
        fwrite(&mass[i], sizeof(int), 1, fileout); 
    } 
    fclose(filein); 
    fclose(fileout); 
    return 0; 
}

