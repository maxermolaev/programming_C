#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	char a;
	int c = 0;
	for (int i = 0;i < 10001; i++)
	{
		scanf("%c\n", &a);
		if (a != '.')
		{
			for (i + 1;i < 10001;i++)
			{
				scanf("%c\n", &a);
				if (a == '.')
					break;
				else
					continue;
			}
			c += 1;
		}
		else
			continue;
	}
	printf("%d", c);
	return 0;
}
