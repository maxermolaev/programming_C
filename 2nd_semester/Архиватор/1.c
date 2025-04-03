#include <stdio.h>
#include <wchar.h>

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Ошибка открытия файлов.\n");
        return 1;
    }
    int characters[65536] = {0}; 
    wchar_t ch;
    while ((ch = fgetwc(input_file)) != WEOF) {
        characters[ch]++;
    }
    for (int i = 0; i < 65536; i++) {
        if (characters[i] > 0) {
            fprintf(output_file, "%d : %d\n", i, characters[i]);
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}

