#include <stdio.h>

int main() {
    FILE *input_file = fopen("input.bin", "rb");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка открытия файлов.\n");
        return 1;
    }
    int bytes[256] = {0};
    int byte;
    while ((byte = fgetc(input_file)) != EOF) {
        bytes[byte]++;
    }
    for (int i = 0; i < 256; i++) {
        if (bytes[i] > 0) {
            fprintf(output_file, "%d : %d\n", i, bytes[i]);
        }
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}

