#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	//if (-100<=a <= 100 && -100<=b <= 100 && -100<=c <= 100)
		if (a <= b && a <= c) printf("%d", a);
		else if (b <= a && b <= c) printf("%d", b);
		else printf("%d", c);

	return 0;
}

