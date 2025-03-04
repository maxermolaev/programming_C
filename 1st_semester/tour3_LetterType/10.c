#include <stdio.h> 
long long gcd(long long a, long long b) 
{ 
    while ((a * b) != 0) 
    { 
        int c = a % b; 
        a = b; 
        b = c; 
    } 
    return a + b; 
} 
long long lcm(long long a, long long b) 
{ 
    return (a * b / gcd(a, b)); 
} 
int main() 
{ 
    int a, b, n; 
    scanf("%d", &n); 
    for(int i = 1; i <= n; i++) 
    { 
        scanf("%d%d", &a, &b); 
    printf("%lld\n", lcm(a, b)); 
    } 
    return 0; 
}

