#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    char a, b;
    long long ch = 0;
    long long ch1 = 0;

    while (scanf("%c", &a) == 1)
    {
        if (a >= '0' && a <= '9')
        {
            ch1 += a - '0';
            scanf("%c", &b);
            while (b >= '0' && b <= '9')
            {
                if (b >= '0' && b <= '9')
                {
                    ch1 = ch1 * 10 + b - '0';
                }
                scanf("%c", &b);
            }
        }
        ch += ch1;
        ch1 = 0;

    }

    printf("%lld", ch);

    return 0;
}
