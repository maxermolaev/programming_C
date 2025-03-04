#include <stdio.h>
#include <string.h>

int main() {
    char color_cans[2][27];
    int R, Y, B;
    for (int i = 0; i < 2; i++) {
        scanf("%s", color_cans[i]);
    }
    int a = strlen(color_cans[1]);
    for (int i = 0; i < a; i++) {
        if (color_cans[1][i] == 'Y') {
            Y = i + 1;
        }
        else if (color_cans[1][i] == 'R') {
            R = i + 1;
        }
        else if (color_cans[1][i] == 'B') {
            B = i + 1;
        }
    }
    if (strcmp(color_cans[0], "purple") == 0) {
        if (R < B) {
            printf("%d %d", R, B);
        }
        else {
            printf("%d %d", B, R);
        }
    }
    else if (strcmp(color_cans[0], "orange") == 0) {
        if (R < Y) {
            printf("%d %d", R, Y);
        }
        else {
            printf("%d %d", Y, R);
        }
    }
    else if (strcmp(color_cans[0], "green") == 0) {
        if (B < Y) {
            printf("%d %d", B, Y);
        }
        else {
            printf("%d %d", Y, B);
        }
    }
    return 0;
}

