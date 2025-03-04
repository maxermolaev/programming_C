#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int chislo, kol, a = 1;
	int ch[100000] = { 0 };

	scanf("%d\n", &kol);
	scanf("%d", &chislo);
	ch[0] = chislo;
	for (int i = 1;i < kol;i++)
	{
		scanf("%d", &chislo);
		int povtor = 0;
		ch[i] = chislo;
		for (int j = i - 1;j >=0;j--)
		{
			if (ch[i] != ch[j])
				povtor++;
			else
				break;
		}
		if (povtor == i)
			a++;
	}
	printf("%d", a);
	return 0;

}
