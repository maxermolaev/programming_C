#include <stdio.h>
#include <string.h>

int main() {
    char words[27][21];
    char let = 'a';
    int count = 0, player = 1;
    while (scanf("%s", words[count]) == 1) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        int next = 0;
        int a = strlen(words[i]);
        for (int j = 0; j < a; j++) {
            if (words[i][j] == let) {
                next = 1;
            }
        }
        if (next == 1) {
            player = 3 - player;
        }
        else {
            player = 3 - player;
            printf("PLAYER %d", player);
            return 0;
        }
        let++;
    }
    printf("NO WINNER");
    return 0;
}
