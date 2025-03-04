#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	char a,f;
	int b, c=0,v;
	for (int i = 0;i < 500;i++)
	{
		scanf("%c", &a);
		b = a - '0';
		c += b;
		if (a == '.')
			break;
		v = c;
		f = a;
	}
	if (f == '0' && v % 3 == 0 || f == '5' && v % 3 == 0)
		printf("YES");
	else
		printf("NO");
}
