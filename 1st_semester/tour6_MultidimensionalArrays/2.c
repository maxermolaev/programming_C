#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int crossword[11][11];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &crossword[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        int black = 0;
        for (int j = 0; j < M; j++) {
            if (crossword[i][j] == 1) {
                black++;
            }
            else if (black > 0) {
                printf("%d ", black);
                black = 0;
            }
        }
        if (black > 0) {
            printf("%d\n", black);
        }
        else {
            printf("\n");
        }
    }
    for (int i = 0; i < M; i++) {
        int black = 0;
        for (int j = 0; j < N; j++) {
            if (crossword[j][i] == 1) {
                black++;
            }
            else if (black > 0) {
                printf("%d ", black);
                black = 0;
            }
        }
        if (black > 0) {
            printf("%d\n", black);
        }
        else {
            printf("\n");
        }
    }
    return 0;
}

