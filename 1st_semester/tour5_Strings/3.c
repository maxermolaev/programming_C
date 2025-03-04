#include <stdio.h>
#include <string.h>

int main() {
    char S[2][27], S2[27] = { 0 };
    char sp = '0';
    int count = 0, ind = 0;
    for (int i = 0; i < 2; i++) {
        scanf("%s", S[i]);
    }
    int a = strlen(S[0]);
    int b = strlen(S[1]);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (S[0][i] == S[1][j]) {
                count++;
            }
        }
        if (count == 0) {
            S2[ind] = S[0][i];
            ind++;
        }
        count = 0;
    }

    if (S2[0] == 0) {
        printf("Empty Set");
    }
    else {
        for (int i = 0; S2[i] != 0; i++)
            for (int j = 1; *(S2 + j) != 0; j++) {
                if (S2[j - 1] > S2[j]) {
                    sp = S2[j - 1];
                    S2[j - 1] = S2[j];
                    S2[j] = sp;
                }
            }
        printf("%s", S2);
    }

    return 0;
}
