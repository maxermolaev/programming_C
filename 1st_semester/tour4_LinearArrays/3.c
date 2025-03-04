#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	scanf("%d\n", &N);
	int a[1000000], s[1000000] = { 0 };
	for (int i = 0;i < N;i++)
		scanf("%d", &a[i]);
	for (int i = 0;i < N;i++)
		s[a[i]] += 1;
	for (int i = 0;i < 1000000;i++)
	{
		if (s[i] != 0)
			printf("%d: %d\n", i, s[i]);
	}
	return 0;
}
