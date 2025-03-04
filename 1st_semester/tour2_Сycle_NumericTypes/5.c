#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int rev_int(int n) {
	int reverse=0, reverse1=0;
	while (n >= 1) {
		reverse = n % 10;
		reverse1 = reverse1 * 10 + reverse;
		n /= 10;
	}
	return reverse1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int a;
	scanf("%d", &n);
	a = rev_int(n);
	printf("%d", a);
}
