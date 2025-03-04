#include <stdio.h>
#include <stdlib.h>
#define lim 1000000
char* str[lim];

int main() {
    int N, t, l, i = 0, ans = 0;
    char *let;
    char letter;
    scanf("%d", &N);
    while (scanf("%d %d", &t, &l) != -1){
        if (t == 0){
            let = (char*) malloc(l+10);
            str[i] = let;
            scanf("%s", let);
            i++;
        }
        if (t == 1){
            free(str[l]);
            str[l] = NULL;
        }
        if (t == 2){
            printf("%s\n", str[l]);
        }
        if (t == 3){
            scanf(" %c", &letter);
            for (int j = 0; str[l][j] != 0; j++){
                if (str[l][j] == letter){
                    ans += 1;
                }
            }
            printf("%d\n", ans);
            ans = 0;
        }
    }

    for (int j = 0; j < lim; j++){
        if (str[j] != NULL){
            free(str[j]);
        }
     }

    return 0;
}

