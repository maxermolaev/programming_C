#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int per(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return ch - 'a' + 10;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n=0, r = 0;
	char ch=0;
	scanf("%d\n", &n);
	scanf("%c", &ch);
	while (ch != '\n')
	{
		r *= n;
		r += per(ch);
		scanf("%c", &ch);
	}
	printf("%d", r);
}

