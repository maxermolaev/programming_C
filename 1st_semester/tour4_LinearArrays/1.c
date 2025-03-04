#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, n, s = 0;
	scanf("%d", &N);
	int num[100];
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &n);
		num[i] = n;
	}
	for (int a = 0;a < N;a++)
	{
		for (int b = a+1;b < N;b++)
		{
			if (num[a] > num[b])
				s++;
		}
		printf("%d ", s);
		s = 0;
	}
	return 0;
}
