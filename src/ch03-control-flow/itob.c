#include <stdio.h>

static void reverse(char s[])
{
    int i = 0;
    int j = 0;
    char temp;

    while (s[j] != '\0') {
        ++j;
    }

    for (--j; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b);

int main(void)
{
    int n, b;
    char output[10000];

    n = -1991;
    b = 16;

    itob(n, output, b);

    printf("%s", output);

    return 0;
}

void itob(int n, char s[], int b)
{
    int si = 0;

    int sign = n;

    do {
        int digit = n % b;
        if (digit < 0)
            digit = -digit;
        s[si++] = digit > 9 ? (digit - 10) + 'A' : digit + '0';
    } while ((n /= b) != 0);

    if (sign < 0)
    {
        s[si++] = '-';
    }
    s[si] = '\0';

    reverse(s);
}