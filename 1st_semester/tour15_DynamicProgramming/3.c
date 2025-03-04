#include <stdio.h> 

#include <stdlib.h> 

  

long long int array[210][60000]; 

long long int num[210][2]; 

long long int answer[201]; 

  

int main() { 

    long long int n, w, count=0, weight=0, c; 

    FILE *input; 

    FILE *output; 

  

    input = fopen("input.txt", "r"); 

    output = fopen("output.txt", "w"); 

  

    fscanf(input, "%lld %lld", &n, &w); 

  

  

    for (int i=1; i!=n+1; i++) { 

        fscanf(input, "%lld %lld", &num[i][0], &num[i][1]); 

    } 

  

  

    for (int i=1; i!=n+1; i++) { 

        for (int j=1; j!=w+1; j++) { 

            if (j<num[i][0]) { 

                array[i][j] = array[i-1][j]; 

            } 

            else { 

                if (array[i-1][j] >= array[i-1][j-num[i][0]] + num[i][1]) 

                    array[i][j] = array[i-1][j]; 

                else { 

                    array[i][j] = array[i-1][j-num[i][0]] + num[i][1]; 

                } 

            } 

        } 

    } 

  

  

    c = array[n][w]; 

  

    long long int i=n, j=w, d=0; 

  

    while (array[i][j]!=0) { 

        if (array[i][j]==array[i-1][j]) { 

            i--; 

        } 

        else { 

            count++; 

            weight+=num[i][0]; 

            j-=num[i][0]; 

            answer[d] = i; 

            d++; 

            i--; 

        } 

    } 

  

  

    fprintf(output, "%lld %lld %lld\n", count, weight, c); 

  

  

    for (long long int v=d-1; v!=-1; v--) { 

        fprintf(output, "%lld ", answer[v]); 

    } 

  

    return 0; 

} 

  
