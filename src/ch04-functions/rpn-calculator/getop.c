#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    static int prev_char = EOF;

    if (prev_char != EOF)
    {
        c = prev_char;
        prev_char = EOF;
    }
    else 
    {
        c = getch();
    }

    while (c == ' ' || c == '\t')
    {
        c = getch();
    }

    s[0] = c;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;    /* not a number */
    i = 0;
    if (isdigit(c))  /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')    /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        prev_char = c;
    return NUMBER;
}


