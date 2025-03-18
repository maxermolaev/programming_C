#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 1000000 
#define MAX_SIZE 1000000000 
 
typedef struct list { 
    int value; 
    struct list* next; 
} element; 
 
typedef struct List { 
    struct list* top; 
} place; 
 
void push(place* x, element* i, int a) { 
    element* A = (element*)malloc(sizeof(element)); 
    A->value = a; 
    A->next = NULL; 
    if (i != NULL) 
        i->next = A; 
    else { 
        element* p = x->top; 
        x->top = A; 
    } 
} 
 
place* mktab() { 
    place* tab = (place*)malloc(sizeof(place) * SIZE); 
    for (int i = 0; i < SIZE; i++) { 
        tab[i].top = NULL; 
    } 
    return tab; 
} 
 
void free_hash(place* tab) { 
    element* t, *p; 
    for (int i = 0; i < SIZE; i++) { 
        t = tab[i].top; 
        if (t != NULL) { 
            while (t != NULL) { 
                p = t; 
                t = t->next; 
                free(p); 
            } 
        } 
    } 
    free(tab); 
} 
 
int hash(int a) { 
    return (a + MAX_SIZE) % SIZE; 
} 
 
int main() { 
    FILE* input = fopen("input.bin", "rb"); 
    FILE* output = fopen("output.bin", "wb"); 
    int N; 
    fread(&N, sizeof(int), 1, input); 
    place* tab = mktab(); 
    int A[SIZE]; 
    int len = 0; 
    int a; 
    for (int i = 0; i < N; i++) { 
        fread(&a, sizeof(int), 1, input); 
 
        int ind = hash(a); 
 
        element* t = tab[ind].top; 
        element* p = NULL; 
        int flag = 0; 
        while (t != NULL) { 
            if (a == t->value) { 
                flag = 1; 
                break; 
            } 
            p = t; 
            t = t->next; 
        } 
        if (!flag) { 
            push(&tab[ind], p, a); 
            A[len] = a; 
            len += 1; 
        } 
    } 
    fwrite(&len, sizeof(int), 1, output); 
    for (int i = 0; i < len; i++) { 
        fwrite(&A[i], sizeof(int), 1, output); 
    } 
    free_hash(tab); 
    fclose(input); 
    fclose(output); 
    return 0; 
}

