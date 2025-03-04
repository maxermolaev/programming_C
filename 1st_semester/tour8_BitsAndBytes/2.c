#include <stdio.h>

int main() {

    unsigned int N;
    scanf("%d",&N);
    int i = sizeof(int) * 8 - 1;
    for(i; i >= 0; i--){
        int bit = (N >> i) & 1;
        printf("%d", bit);
    }
    unsigned int upside_down = 0;
    for(int j = 0; j < sizeof(int) * 8; j++){
        upside_down = (upside_down << 1) | ((N >> j) & 1);
    }
    printf("\n");
    printf("%d",upside_down);
    printf("\n");
    for(int j = 0; j < sizeof(int) * 8; j++){
        int Bin = N & 1;
        printf("%d", Bin);
        N >>= 1;
    }
    return 0;
}

