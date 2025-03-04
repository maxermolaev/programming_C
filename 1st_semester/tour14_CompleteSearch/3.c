#include <stdio.h> 

#include <stdlib.h> 

  

  

  

int main() { 

    long long int n, w, max=0, sum, weight, count=0; 

  

    FILE *input; 

    FILE *output; 

  

    input = fopen("input.txt", "r"); 

    output = fopen("output.txt", "w"); 

  

    fscanf(input, "%lld %lld", &n, &w); 

  

  

    long long int ** array = (long long int **) calloc(n, sizeof(long long int*)); 

  

    for (int i=0; i!=n; i++) { 

        array[i] = (long long int *) calloc(2, sizeof(long long int)); 

    } 

  

    for (int i=0; i!=n; i++) { 

        for (int j=0; j!=2; j++) { 

            fscanf(input, "%lld", &array[i][j]); 

        } 

    } 

  

    long long int * indx = (long long int *) calloc(n, sizeof(long long int)); 

    long long int * maska = (long long int *) calloc(n, sizeof(long long int)); 

  

    while (maska[n-1]!=2) { 

        sum=0; 

        weight=0; 

        for (int i=1; i!=n; i++) { 

            if (maska[i-1]==2) { 

                maska[i-1]=0; 

                maska[i]++; 

            } 

        } 

        for (int i=0; i!=n; i++) { 

            if (maska[i]==1) { 

                weight+=array[i][0]; 

                sum+=array[i][1]; 

            } 

        } 

        if (weight<=w) { 

            if (sum>max) { 

                max = sum; 

                for (int i=0; i!=n; i++) { 

                    indx[i] = maska[i]; 

                } 

            } 

        } 

        maska[0]++; 

    } 

  

    for (int i=0; i!=n; i++) { 

        if (indx[i]==1) { 

            count++; 

        } 

    } 

  

    fprintf(output, "%lld %lld\n", max, count); 

    for (int i=0; i!=n; i++) { 

        if (indx[i]!=0) { 

            fprintf(output, "%d ", i+1); 

        } 

    } 

  

  

  

} 

 
