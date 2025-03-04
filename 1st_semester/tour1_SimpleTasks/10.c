#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int k;
    scanf("%d", &k);
    float s;
    s = (sqrt(8 * k - 7) - 1) / 2;
    if ((int)s == s) 
    {
        printf("1"); 
    }
    else 
    {
        printf("0");
    }
}
