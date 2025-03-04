#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int chislo;
        scanf("%d", &chislo);
        int k = 0;
        while (chislo % 2 == 0) {
            chislo /= 2;
            k++;
        }
        printf("%d\n", 1 << k);
    }
    return 0;
}

