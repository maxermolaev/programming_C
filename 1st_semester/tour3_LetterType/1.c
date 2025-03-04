#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char d,a,y;
	scanf("%c%c%c", &d,&a,&y);
	if (d=='M' && a=='o' && y=='n')
		printf("1");
	else if (d == 'T' && a == 'u' && y == 'e')
		printf("2");
	else if (d == 'W' && a == 'e' && y == 'd')
		printf("3");
	else if (d == 'T' && a == 'h' && y == 'u')
		printf("4");
	else if (d == 'F' && a == 'r' && y == 'i')
		printf("5");
	else if (d == 'S' && a == 'a' && y == 't')
		printf("6");
	else if (d == 'S' && a == 'u' && y == 'n')
		printf("7");
}
