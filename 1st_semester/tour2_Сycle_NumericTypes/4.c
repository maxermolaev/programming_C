#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int prime(int n) {
	int f = 0;
        int K;
        K=sqrt(n);
	for (int i = 1;i <= K; i++) {
		if (n % i == 0 && i * i == n) {
			f += 1;
		}
		else if (n % i == 0) {
			f += 2;
		}
	}
	if (f == 2) return n;
	else return 0;
}



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n, a;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		a = prime(i);
		if (a != 0) printf("%d ", a);
	}
}
