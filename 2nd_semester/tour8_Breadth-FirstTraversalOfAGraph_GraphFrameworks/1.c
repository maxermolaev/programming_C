#include <stdio.h>
#include <stdbool.h>

#define MAX_N 200000
#define MAX_M 200000

typedef struct {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_N + 1];
int distance[MAX_N + 1];
bool visited[MAX_N + 1];

void initialize(int n) {
    for (int i = 1; i <= n; i++) {
        adjList[i] = NULL;
        distance[i] = -1;
        visited[i] = false;
    }
}

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void bfs(int start, int n) {
    visited[start] = true;
    distance[start] = 0;

    int queue[MAX_N + 1];
    int front = 0, rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        Node* temp = adjList[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    scanf("%d %d", &N, &M);

    initialize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    bfs(1, N);

    for (int i = 1; i <= N; i++) {
        if (distance[i] == -1)
            printf("-1\n");
        else
            printf("%d\n", distance[i]);
    }

    return 0;
}

