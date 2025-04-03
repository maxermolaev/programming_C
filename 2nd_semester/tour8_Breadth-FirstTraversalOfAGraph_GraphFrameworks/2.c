#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_M 100
#define MAX_N 100
#define INF 1000000000

typedef struct {
    int x;
    int y;
} Point;

Point queue[MAX_M * MAX_N];
char maze[MAX_M][MAX_N];
int distance[MAX_M][MAX_N];
int M, N;

void initialize() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            distance[i][j] = INF;
        }
    }
}

bool isValid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N && maze[x][y] != 'X';
}

void bfs(int startX, int startY, int endX, int endY) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    int front = 0, rear = 0;
    queue[rear++] = (Point){startX, startY};
    distance[startX][startY] = 0;

    while (front < rear) {
        Point current = queue[front++];
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            if (isValid(newX, newY) && distance[newX][newY] == INF) {
                distance[newX][newY] = distance[current.x][current.y] + 1;
                queue[rear++] = (Point){newX, newY};
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &M, &N);
    int startX, startY, endX, endY;

    for (int i = 0; i < M; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            } else if (maze[i][j] == 'F') {
                endX = i;
                endY = j;
            }
        }
    }

    initialize();
    bfs(startX, startY, endX, endY);

    if (distance[endX][endY] == INF)
        printf("-1\n");
    else
        printf("%d\n", distance[endX][endY]);

    return 0;
}

