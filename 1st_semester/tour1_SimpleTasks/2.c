#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	float a, b, c;;
	scanf("%f %f %f", &a, &b, &c);
	printf("%f\n", a *b *c);


	return 0;
}
