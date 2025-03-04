#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N,n,s;
	scanf("%d", &N);
	s = 0;
	while (N >= 1) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			 s+= n;
			}
		    N -= 1;
	}
	printf("%d", s);
	return 0;
}
