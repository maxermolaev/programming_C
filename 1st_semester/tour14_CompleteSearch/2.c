#include <stdio.h> 

#include <stdlib.h> 

  

  

int check(int i, int k, char** array, int m) { 

    for (int y=0; y<=i; y++) { 

        for (int x=0; x<m; x++) { 

            if (array[y][x]=='X') { 

                if (y==i||x==k) { 

                    return 0; 

                } 

                if (abs(y-i)==abs(x-k)) { 

                    return 0; 

                } 

            } 

        } 

    } 

    return 1; 

} 

  

int Try(int i, int m, char** array, int n, char** mask) { 

    int k, temp=0; 

    for (k=0; k!=m; k++) { 

        if (check(i, k, array, m)&&mask[i][k]!='.') { 

            array[i][k] = 'X'; 

            if (i + 1 < n) { 

                temp = Try(i + 1, m, array, n, mask); 

            } 

            if (temp == n || i + 1 == n) { 

                return n; 

            } 

            array[i][k] = '.'; 

        } 

    } 

    return 0; 

} 

  

  

int main() { 

    int n, m, res; 

  

    FILE *input; 

    FILE *output; 

  

    input = fopen("input.txt", "r"); 

    output = fopen("output.txt", "w"); 

  

    fscanf(input, "%d %d", &n, &m); 

  

    char ** field = (char **) malloc(sizeof(char**)*n); 

  

    for (int i=0; i!=n; i++) { 

        field[i] = (char*) calloc(m, sizeof(char*)); 

    } 

  

    for (int i=0; i!=n; i++) { 

        for (int j=0; j!=m; j++) { 

            field[i][j]='.'; 

        } 

    } 

  

    char ** mask = (char **) malloc(sizeof(char**)*n); 

  

    for (int i=0; i!=n; i++) { 

        mask[i] = (char*) calloc(m, sizeof(char*)); 

    } 

  

    for (int i=0; i!=n; i++) { 

        fscanf(input, "%s", mask[i]); 

    } 

  

    res = Try(0, m, field, n, mask); 

  

  

    if (res) { 

        fprintf(output, "YES\n"); 

        for (int i = 0; i != n; i++) { 

            fprintf(output, "%s", field[i]); 

            fprintf(output, "\n"); 

        } 

  

    } 

    else { 

        fprintf(output, "NO"); 

    } 

  

  

  

} 

 
