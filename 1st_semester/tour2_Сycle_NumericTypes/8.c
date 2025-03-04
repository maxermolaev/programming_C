#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n;
	double s;
	double num = 1;
	int ch = 1;
	int ch1 = 1;
	scanf("%d", &n);
	while (n >= 1) {
		scanf("%lf", &s);
		if (s > 0) {
			while (s >= 1) {
				s -= 1;
			}
		}
		else if (s < 0) {
			while (s < 0) {
				s += 1;
			}
		}
		if (s < num || (1 - s) < num) {
			if (s < 1 - s) 
				num = s;
			else 
				num = 1 - s;
			ch1 = ch;
			
		}
		//printf("%lf ", s);
		n -= 1;
		ch += 1;
	}
	printf("%d", ch1);
}
