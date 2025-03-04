#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;
	scanf("%d %d", &a, &b);
	int d, d1,d2,d3;
	if (a % b == 0)
	{
		if (a < 0)
		{
			d = a / b;
			d1 = a / b;
			d2 = a / b;
			d3 = 0;
		}
		else
		{
			d = a / b;
			d1 = a / b;
			d2 = a / b;
			d3 = 0;
		}
	}
	else
	{
		if (a < 0)
		{
			d = (a / b) - 1;
			d1 = (a / b);
			d2 = a / b;
			d3 = b - ((-a) % b);
		}
		else
		{
			d = a / b;
			d1 = (a / b) + 1;
			d2 = a / b;
			d3 = a % b;
		}
	}

	printf("%d %d %d %d", d,d1,d2,d3);

	return 0;
	
}
