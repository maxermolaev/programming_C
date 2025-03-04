#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, bite = 0, step = 0, len = 0;
	char bit;
	scanf("%d\n", &N);
	while (len != N) {
		scanf("%c", &bit);
		len++;
		step++;
		if (step < 8)
			bite += (bit - '0') * pow(2, step - 1);
		else if (step == 8) {
			bite += (bit - '0') * pow(2, step - 1);
			printf("%d ", bite);
			bite = 0;
			step = 0;
		}
	}
	if (step > 0)
		printf("%d", bite);
	return 0;
}
