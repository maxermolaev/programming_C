#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double a1, a2, b1, b2, c1, c2;
	double a,b,c,P,p, s;
	scanf("%lf %lf %lf %lf %lf %lf", &a1, &a2, &b1, &b2, &c1, &c2);
	a = pow(pow(b1 - a1, 2) + pow(b2 - a2, 2), 0.5);
	b = pow(pow(c1 - b1, 2) + pow(c2 - b2, 2), 0.5);
	c = pow(pow(a1 - c1, 2) + pow(a2 - c2, 2), 0.5);
	P = a + b + c;
	p = P / 2;
	s = pow(p * (p - a) * (p - b) * (p - c), 0.5);
	printf("%0.3lf\n%0.3lf", P,s);


}
