#include <stdio.h>
int main() {

    FILE* input = fopen("input.bin", "rb");
    FILE* output = fopen("output.bin", "wb");

    int A, B , ans;
    fread(&A, sizeof(int), 1, input);
    fread(&B, sizeof(int), 1, input);

    if (((long long int)A + B) % 2 == 0){
        ans = ((long long int)A + B) / 2;
    }
    else{
        ans = (((long long int)A + B) - 1) / 2;
    }
    fwrite(&ans, sizeof(int), 1, output);
    fclose(input);
    fclose(output);
    return 0;
}

