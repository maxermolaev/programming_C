#include <stdio.h>
#include <stdlib.h>



int main() {
    int n;

    FILE *input;
    FILE *output;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fscanf(input, "%d", &n);


    int * array = (int *) malloc(sizeof(int)*n);

    array[0] = 2;
    array[1] = 3;

    for (int i=2; i<n; i++) {
        array[i] = array[i-1]+array[i-2];
    }


    fprintf(output, "%d", array[n-1]);

}
