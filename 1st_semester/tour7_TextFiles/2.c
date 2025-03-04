#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    int word[100] = {0};

    char word1[100];
    int w;

    while (fscanf(inputFile, "%s", word1) == 1) {
        w = strlen(word1);
        word[w]++;
    }

    for (int i = 1; i < 100; i++) {
        if (word[i] > 0) {
            fprintf(outputFile, "%d - %d\n", i, word[i]);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
