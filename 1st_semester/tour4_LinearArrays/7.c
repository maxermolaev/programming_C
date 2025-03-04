#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#define m 10000000

int binsearch(int x, int l[], int L, int R)
{
	int i;
	if (L > R)
		return -1;
	i = (L + R) / 2;
	if (x == l[i])
		return i;
	if (x > l[i])
		return binsearch(x, l, i + 1, R);
	if (x < l[i])
		return binsearch(x, l,L, i - 1);
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l[m];
	int N, x;
	scanf("%d %d", &N, &x);
	for (int i = 0;i < N;i++)
		scanf("%d", &l[i]);
	printf("%d", binsearch(x, l, 0, N - 1));
	return 0;
}
