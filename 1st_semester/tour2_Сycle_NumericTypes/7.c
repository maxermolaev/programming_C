#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, N, ch, s, max, min, maxcher, mincher;
	scanf("%d", &n);
	max = -1000;
	min = 100000;
	mincher = 1;
	maxcher = 1;
	N = n;
	ch = 1;
	while (n >= 1) {
		scanf("%d", &s);
		if (s > max) {
			max = s;
			maxcher = ch;
		}
		if (s<min) {
			min = s;
			mincher = ch;
		}
		n -= 1;
		ch += 1;
	}
	printf("%d %d %d %d", min, mincher, max, maxcher);
}
