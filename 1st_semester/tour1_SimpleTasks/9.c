#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, p, k, l;
	scanf("%d %d %d %d %d", &n, &m, &p, &k, &l);
	int kolvokv, kolvokv1, pod, etazh;
	kolvokv = p * l - (l - k);
	kolvokv1 = ceil((float)m / kolvokv);
	pod = ceil((float)n / kolvokv1 / l);
	etazh = ceil((float)n / kolvokv1) - l * (pod - 1);
	printf("%d %d", pod, etazh);
}
