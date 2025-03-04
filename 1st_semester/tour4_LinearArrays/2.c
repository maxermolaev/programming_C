#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, n, s = 0;
	scanf("%d", &N);
	int num[100000];
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &n);
		num[i] = n;
	}
	for (int a = 0;a < N;a++)
	{
		for (int b=a;b < N;b += a + 1)
			s += num[b];
		printf("%d\n", s);
		s = 0;
	}
}
