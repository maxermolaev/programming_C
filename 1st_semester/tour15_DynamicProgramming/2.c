#include <stdio.h>
#include <stdlib.h>

int array[10001][101];
int num[10001];

int main() {
    int n, k, plus, minus, f=0;

    FILE *input;
    FILE *output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fscanf(input, "%d %d", &n, &k);

    for (int i=0; i!=n; i++) {
        fscanf(input, "%d ", &num[i]);
    }

    if (num[0]%k>=0) {
        array[0][num[0]%k] = 1;
    }
    else {
        array[0][num[0]%k+k] = 1 ;
    }

    if (array[0][0]==1&&n==1) {
        f=1;
    }

    for (int i=1; i!=n; i++) {
        for (int j=0; j!=k; j++) {
            if (array[i-1][j]==1) {
                if (num[i]%k>=0) {
                    plus = j+num[i]%k;
                    minus = j-num[i]%k;
                }
                if (num[i]%k<0) {
                    plus = j+num[i]%k+k;
                    minus = j-num[i]%k+k;
                }
                if (plus%k>=0) {
                    array[i][plus%k] = 1;
                }
                else {
                    array[i][plus%k+k] = 1;
                }
                if (minus%k>=0) {
                    array[i][minus%k] = 1;
                }
                else {
                    array[i][minus%k+k] = 1;
                }
            }
        }
    }

    if (array[n-1][0]==1) {
        f=1;
    }


    if (f) {
        fprintf(output, "Divisible");
    }
    else {
        fprintf(output, "Not divisible");
    }

    return 0;
}

