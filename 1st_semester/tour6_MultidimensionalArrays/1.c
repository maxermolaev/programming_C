#include <stdio.h>

int main() {
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        double coef = 1.0;
        for(int j = 1; j <= k; j++){
            coef *= (n - k + j);
            coef /= j;
        }
        printf("%0.10g\n", coef);
    }
    return 0;
}

