#include <stdio.h>

int main() {

    unsigned int N;
    scanf("%d",&N);
    int count = 0, max = 0;
    while(N > 0){
        int bit = N & 1;
        if (bit == 1){
            count += 1;
            if(count > max){
                max = count;
            }
        }
        else{
            count = 0;
        }
        N >>= 1;
    }
    printf("%d", max);
    return 0;
}

