#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y, z;
	int a;
	scanf("%d %d %d", &x, &y, &z);
	if (x <= 0)
		printf("-1");
	else if (y <= 0)
		printf("-2");
	else if (z <= 0)
		printf("-3");
	else
	{
		a = 2 * x * y + 2 * x * z + 2 * y * z;
		printf("%d", a);
	}
}
