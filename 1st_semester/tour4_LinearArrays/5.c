#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#define m 1000000


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, K = 0, min = 0;
	int prime[m] = { 0 };
	scanf("%d", &N);
	N--;
	for (int i = 0;i < N;i++){
		prime[i] = i + 2;
	}
	do {
		K = min;
		for (int i = K + prime[K];i < N;i += prime[K]){
			prime[i] = 0;
		}
		for (int i = K;i < N;i++){
			if (prime[i] > prime[K])
			{
				min = i;
				break;
			}
		}
	} while(K < min);
	for (int i = 0;i < N;i++){
		if (prime[i] != 0) {
			printf("%d\t", prime[i]);
		}
	}
	return 0;
}
