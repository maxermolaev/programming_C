#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 20000
#define MAX_M 200000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX_N];
bool visited[MAX_N];
int components[MAX_N];

void addEdge(int a, int b) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = b;
    newNode->next = graph[a];
    graph[a] = newNode;
}

void dfs(int v, int component) {
    visited[v] = true;
    components[v] = component;
    Node* curr = graph[v];
    while (curr != NULL) {
        if (!visited[curr->vertex]) {
            dfs(curr->vertex, component);
        }
        curr = curr->next;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        graph[i] = NULL;
        visited[i] = false;
        components[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a - 1, b - 1);
        addEdge(b - 1, a - 1);
    }

    int component_count = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            component_count++;
            dfs(i, component_count);
        }
    }

    printf("%d\n", component_count);
    for (int i = 0; i < N; i++) {
        printf("%d ", components[i]);
    }
    printf("\n");

    return 0;
}

