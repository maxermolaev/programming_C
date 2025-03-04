#include <stdio.h> 
 
int swap(int number) 
{ 
    return ((number >> 24) & 0x000000FF) | ((number << 24) & 0xFF000000) | ((number >> 8) & 0x0000FF00) | ((number << 8) & 0x00FF0000); 
} 
 
int main() 
{ 
    FILE* filein = fopen("input.bin", "rb"); 
    FILE* fileout = fopen("output.bin", "wb"); 
    int N, need, start=0, ans=0; 
    fread(&N, sizeof(int), 1, filein); 
    printf("%d", N); 
    if (N > 10000){ 
        start = 1; 
        N = swap(N); 
    } 
    for (int i = 0; i < N; i++){ 
        fread(&need, sizeof(int), 1, filein); 
 
        if (start == 1){ 
        need = swap(need); 
        } 
        ans += need; 
    } 
    if (start == 1){ 
        ans = swap(ans); 
    } 
    fclose(filein); 
    fwrite(&ans, sizeof(int), 1, fileout); 
    fclose(fileout); 
    return 0; 
}

