#include <stdio.h>
#include <stdlib.h>


int array[10];


int main() {
    int N;

    FILE* input;
    FILE* output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fscanf(input, "%d", &N);


    for (int i = 1; i != N + 1; i++) {
        array[i - 1] = i;
    }

    int* mask = (int*)calloc(N, sizeof(int));


    while (mask[N - 1] != 2) {
        mask[0]++;
        for (int i = 1; i != N; i++) {
            if (mask[i - 1] == 2) {
                mask[i]++;
                mask[i - 1] = 0;
            }
        }

        for (int i = 0; i != N; i++) {
            if (mask[i] == 1) {
                fprintf(output, "%d ", array[i]);
            }
        }
        fprintf(output, "\n");
    }



}
