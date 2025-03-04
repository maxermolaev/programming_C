#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#define m 10000000


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l[m];
	int N, L, R, sum, next, nextsum;
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &l[i]);
	}
	sum = l[0];
	nextsum = l[0];
	for (int i = 1;i < N;i++)
	{
		if (nextsum + l[i] < l[i])
		{
			nextsum = l[i];
			next = i;
		}
		else
			nextsum += l[i];
		if (sum < nextsum || (sum == nextsum && (i - next < R - L)))
		{
			sum = nextsum;
			L = next;
			R = i;
		}
	}
	printf("%d %d %d", L, R, sum);
	return 0;
}
