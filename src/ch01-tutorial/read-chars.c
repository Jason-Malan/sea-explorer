#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    int isNotEof = c != EOF;
    while (isNotEof)
    {
        putchar(c);
        printf("\n %d", isNotEof);
        c = getchar();
        isNotEof = c != EOF;
    }

    return 1;
}