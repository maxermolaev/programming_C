#include <stdio.h> 
int gcd(int a, int b) 
{ 
    while ((a * b) != 0) 
    { 
        int c = a % b; 
        a = b; 
        b = c; 
    } 
    return a + b; 
} 
int main () 
{ 
    int a, b; 
    scanf("%d%d", &a, &b); 
    printf("%d", gcd(a,b)); 
    return 0; 
}

