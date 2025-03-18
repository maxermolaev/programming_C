#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 
 
#define SIZE 9785021 
 
uint64_t M; 
uint64_t a, b, c; 
 
typedef struct list { 
    uint64_t a; 
    uint64_t i; 
    struct list* next; 
} element; 
 
typedef struct queue { 
    uint64_t len; 
    struct list* first; 
    struct list* end; 
} queue; 
 
void in_que(queue* S, uint64_t x, uint64_t ind) { 
    element* add = (element*)malloc(sizeof(element)); 
    add->a = x; 
    add->i = ind; 
    add->next = NULL; 
    if (!S->len) { 
        S->first = add; 
        S->end = add; 
    } else { 
        S->end->next = add; 
        S->end = add; 
    } 
    S->len++; 
} 
 
uint64_t out_que(queue* S) { 
    element* del = S->first; 
    S->first = del->next; 
    S->len--; 
    uint64_t a = del->a; 
    free(del); 
    return a; 
} 
 
queue* create() { 
    queue* S = (queue*)malloc(sizeof(queue) * SIZE); 
    for (int i = 0; i < SIZE; i++) { 
        S[i].len = 0; 
        S[i].first = NULL; 
        S[i].end = NULL; 
    } 
    return S; 
} 
 
void free_hash(queue* S) { 
    uint64_t length; 
    for (int i = 0; i < SIZE; i++) { 
        length = S[i].len; 
        for (uint64_t j = 0; j < length; j++) { 
            out_que(&S[i]); 
        } 
    } 
    free(S); 
} 
 
uint64_t func(uint64_t s) { 
    return (s * s * a + s * b + c) % M; 
} 
 
uint64_t Hash(uint64_t x) { 
    return x % SIZE; 
} 
 
int main() { 
    scanf("%" SCNu64 "\n", &M); 
    scanf("%" SCNu64 " %" SCNu64 " %" SCNu64, &a, &b, &c); 
    queue* tab = create(); 
    in_que(&tab[Hash(1)], 1, 0); 
    uint64_t l; 
    uint64_t r; 
    uint64_t state = func(1); 
    uint64_t hash = Hash(state); 
    uint64_t p = 1; 
    element* t; 
    int flag = 0; 
    while (1) { 
        t = tab[hash].first; 
        while (t != NULL) { 
            if (state == t->a) { 
                l = t->i; 
                r = p; 
                flag = 1; 
                break; 
            } 
            t = t->next; 
        } 
        if (flag == 1) { 
            break; 
        } 
        in_que(&tab[hash], state, p); 
        state = func(state); 
        hash = Hash(state); 
        p++; 
    } 
    printf("%" PRIu64 " %" PRIu64, l, r); 
    free_hash(tab); 
    return 0; 
}

