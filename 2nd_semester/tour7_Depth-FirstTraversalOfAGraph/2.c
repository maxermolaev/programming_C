#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "string.h"
#include "math.h"
#include "time.h"
#include "stdbool.h"

struct s_node;

#define DYN_LIST_TYPE struct s_node*

typedef struct {
    DYN_LIST_TYPE* arr;
    int capacity;
    int count;
} DynList;
DynList* dl_create(int capacity){
    DynList* l = calloc(1, sizeof(DynList));
    l->arr = calloc(capacity, sizeof(DYN_LIST_TYPE));
    l->capacity = capacity;
    l->count = 0;
    return l;
}
void dl_append(DynList* list, DYN_LIST_TYPE val){
    if(list->count >= list->capacity){
        if(list->capacity == 0){
            list->capacity = 1;
        }

        list->arr = realloc(list->arr, list->capacity * sizeof(DYN_LIST_TYPE) * 2); // NOLINT(*-suspicious-realloc-usage)
        list->capacity *= 2;

        if(list->arr == NULL){
            assert(0 && "realloc failed");
        }
    }
    list->arr[list->count] = val;
    list->count++;
}
void dl_clear(DynList* list){
    list->count = 0;
}
typedef struct s_node{
    int value;
    int color;
    DynList edges;
} Node;

DYN_LIST_TYPE dl_get(DynList* list, int index){
    if(index < 0 || index >= list->count){
        assert(0 && "index out of range");
    }
    return list->arr[index];
}

void graph_dfs(Node* node, int color){
    node->color = color;
    for (int i = 0; i < node->edges.count; ++i) {
        Node* next = dl_get(&node->edges, i);
        if(next->color == 0){
            graph_dfs(next, color);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    Node* nodes = calloc(n, sizeof(Node));
    for (int i = 0; i < n; ++i) {
        nodes[i].value = i;
    }

    int a, b;
    while (scanf("%d%d", &a, &b) != EOF){
        dl_append(&nodes[a - 1].edges, &nodes[b - 1]);
        dl_append(&nodes[b - 1].edges, &nodes[a - 1]);
    }

    int color = 0;
    for (int i = 0; i < n; ++i) {
        if(nodes[i].color == 0){
            graph_dfs(&nodes[i], ++color);
        }
    }

    printf("%d", color + 1);

    return 0;
}

#pragma clang diagnostic pop
