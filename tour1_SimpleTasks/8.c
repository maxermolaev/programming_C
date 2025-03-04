#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int a, b, c,k, s = 0;
	scanf("%d %d %d", &a, &b, &c);
	double k1, k2;
	if (a==0 && b==0 && c==0)
		printf("MANY");
	else if (a == 0 && b == 0 && c!=0)
		printf("ERROR");
	else if (a == 0 && b != 0)
	{
		k1 = (-c) / (double)b;
		s = 1;
		printf("%d\n%0.5lf", s,k1);
	}
	else
	{
		k = pow(b, 2) - 4 * a * c;
		if (k < 0)
			printf("NO");
		else if (k == 0)
		{
			k1 = (-b / (2 * (double)a));
			s = 1;
			printf("%d\n%0.5lf", s, k1);
		}
		else
		{
			s = 2;
			k1 = (-b + pow(k, 0.5)) / (2 * a);
			k2 = (-b - pow(k, 0.5)) / (2 * a);
			if (k1 >= k2)
				printf("%d\n%0.5lf %0.5lf", s, k2, k1);
			else
				printf("%d\n%0.5lf %0.5lf", s, k1, k2);
		}
	}
}
