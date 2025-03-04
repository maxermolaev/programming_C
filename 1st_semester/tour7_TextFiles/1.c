#include <stdio.h>

int main() {
    FILE *ifile = fopen("input.txt", "r");
    int symb[1000] = {0};
    int number;
    while((number = fgetc(ifile)) != EOF){
        if (number >= 12){
            symb[number]++;
        }
    }
    fclose(ifile);

    FILE *ofile = fopen("output.txt", "w");
    for(int i = 12; i < 1000; i++){
        if(symb[i] > 0){
            fprintf(ofile, "%d : %c - %d\n", i, i, symb[i]);
        }
    }
    fclose(ofile);
    return 0;
}

