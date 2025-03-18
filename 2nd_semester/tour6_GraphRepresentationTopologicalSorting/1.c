#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "string.h"
#include "math.h"
#include "time.h"

typedef struct s_adjacency_matrix{
   char* matrix;
   int n;
} AdjacencyMatrix;

AdjacencyMatrix* matrix_create(int n){
    AdjacencyMatrix* m = calloc(1, sizeof(AdjacencyMatrix));
    m->matrix = calloc(n*n, sizeof(char));
    m->n = n;
    return m;
}

void matrix_set(AdjacencyMatrix* mat, int x, int y, char val){
    mat->matrix[x + y * mat->n] = val;
}
char matrix_get(AdjacencyMatrix* mat, int x, int y){
    return mat->matrix[x + y * mat->n];
}

int matrix_get_free_columns(AdjacencyMatrix* mat, char* out){
    int index = 0;
    for (int x = 0; x < mat->n; ++x) {
        int is_free = 1;
        for (int y = 0; y < mat->n; ++y) {
            if(matrix_get(mat, x, y) == 1){
                is_free = 0;
                break;
            }
        }
        if(is_free){
            out[x] = 1;
            index++;
        }
    }
    return index;
}
int matrix_get_free_columns_in(AdjacencyMatrix* mat, char* xs, int xs_count, char* out){
    int index = 0;
    for (int x = 0; x < mat->n; ++x) {
        if(xs[x] == 0 || out[x] == 1){
            continue;
        }

        int is_free = 1;
        for (int y = 0; y < mat->n; ++y) {
            if(matrix_get(mat, x, y) == 1){
                is_free = 0;
                break;
            }
        }
        if(is_free){
            out[x] = 1;
            xs[x] = 0;
            index++;
        }
    }
    return index;
}

int matrix_clear_y(AdjacencyMatrix* mat, int y, char* out){
    int out_index = 0;
    for (int i = 0; i < mat->n; ++i) {
        if(mat->matrix[i + mat->n * y] == 1){
            out[i] = 1;
            out_index++;
            mat->matrix[i + mat->n * y] = 0;
        }
    }
    return out_index;
}
void matrix_print(AdjacencyMatrix* mat){
    for (int y = 0; y < mat->n; ++y) {
        for (int x = 0; x < mat->n; ++x) {
            printf("%d  ", matrix_get(mat, x, y));
        }
        printf("\n");
    }
    printf("---\n");
}

int main() {
    freopen("input.txt", "rb", stdin);
    freopen("output.txt", "wb", stdout);

    int n;
    int m;
    scanf("%d%d", &n, &m);

    AdjacencyMatrix* matrix = matrix_create(n);

    for (int i = 0; i < m; ++i) {
        int lower;
        int higher;
        scanf("%d%d", &lower, &higher);
        matrix_set(matrix,  higher - 1,lower - 1, 1);
    }
    int total_count = 0;

    char* free_columns = calloc(n, sizeof(char));
    char* cleared_columns = calloc(n, sizeof(char));
    int* result = calloc(n, sizeof(int));
    int free_columns_count = matrix_get_free_columns(matrix, free_columns);
    
    while (1){
        int next_column = -1;
        int no_one = 1;
        for (int i = 0; i < n; ++i) {
            if(free_columns[i]){
                result[total_count++] = i;
                free_columns[i] = 0;
                next_column = i;
                no_one = 0;
                break;
            }
        }

        if(next_column != -1){
            int cleared_columns_count = 0;
            cleared_columns_count = matrix_clear_y(
                    matrix,
                    next_column,
                    cleared_columns
            );


            free_columns_count =
                    matrix_get_free_columns_in(
                            matrix,
                            cleared_columns,
                            cleared_columns_count,
                            free_columns
                    );
        }


        if(total_count >= n){
            break;
        }

        if(free_columns_count == 0 && no_one){
            printf("bad course");
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i] + 1);
    }

    return 0;
}
