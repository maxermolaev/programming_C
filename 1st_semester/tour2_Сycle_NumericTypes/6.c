#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	double n, s,N;
	double p = 0;
	double o = 0;
	double nul = 0;
	scanf("%lf", &n);
	N = n;
	while (n >= 1) {
		scanf("%lf", &s);
		if (s > 0)
			p += 1;
		else if (s < 0)
			o += 1;
		else nul += 1;
		n-=1;
	}
	printf("%0.5lf %0.5lf %0.5lf", o/N, nul/N, p/N);
}

