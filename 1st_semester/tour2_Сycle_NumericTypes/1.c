#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int i = 1;
	int s = 0;
	for (i; i <= n; i++)
	{
		s += i;
	}
	printf("%d\n", s);

	return 0;
}
