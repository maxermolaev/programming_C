#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k, x;;
	scanf("%d %d", &k, &x);
	if (0 <= x && x < k) printf("legal");
	else printf("out of bounds");

	return 0;
}
