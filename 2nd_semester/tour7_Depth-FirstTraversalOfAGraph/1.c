#include <stdio.h>
#include <stdbool.h>

#define MAX_N 50
#define MAX_M 100
#define MAX_S 10

int graph[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1];

void dfs(int node, int n) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, S;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    scanf("%d", &S);

    int shaman_positions[MAX_S];
    for (int i = 0; i < S; i++) {
        scanf("%d", &shaman_positions[i]);
    }

    bool connected = true;
    for (int i = 0; i < S - 1; i++) {
        int start = shaman_positions[i];
        int end = shaman_positions[i + 1];
        if (!visited[start]) {
            dfs(start, N);
        }
        if (!visited[end]) {
            connected = false;
            break;
        }
    }

    if (connected) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}

