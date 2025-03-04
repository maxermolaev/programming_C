#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int h, m, s, k;
	scanf("%d %d %d %d", &h, &m, &s, &k);
	int hk, mk, sk;
	int hi, mi, si;
	hk = k / 3600;
	mk = (k - hk * 3600) / 60;
	sk = k - hk * 3600 - mk * 60;
	if (s + sk < 60)
		si = s + sk;
	else
	{
		m += (s + sk) / 60;
		si = (s + sk) % 60;
	}
	if (m + mk < 60)
		mi = m + mk;
	else
	{
		h += (m + mk) / 60;
		mi = (m + mk) % 60;
	}
	if (h + hk < 24)
		hi = h + hk;
	else
		hi = (h + hk) % 24;
	printf("%d %d %d", hi, mi, si);
}
