#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int prime(int n) {
	int f = 0;
	for (int s = 1; s <= n; s++) {
		if (n % s == 0) {
			f += 1;
		}
	}
		return f;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int a = prime(n);
	if (a == 2) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}
