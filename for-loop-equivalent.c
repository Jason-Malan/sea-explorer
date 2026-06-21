#include <stdio.h>

#define MAXLINE 1000

int main(void)
{
    int i;
    int c;
    int lim;
    char s[MAXLINE];

    lim = MAXLINE;
    i = 0;

    while (i < lim - 1) {
        c = getchar();

        if (c == '\n')
            break;

        if (c == EOF)
            break;

        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    printf("%s\n", s);

    return 0;
}