#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	char a, b, c;
	for (int i = 0;i < 30;i++)
	{
		scanf("%c", &b);
		if (b == '.')
		{
			break;
		}
		c = a;
		a = b;
		if (i == 0)
		{
			continue;
		}
		else
		{
			printf("%c", c);
		}
	}
	if (a == 'r' && c == 'e')
	{
		printf("st");
	}
	else if (a == 'e')
	{
		printf("er");
	}
	else
	{
		printf("%cer", a);
	}
}
