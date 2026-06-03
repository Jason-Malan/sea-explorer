#include <stdio.h>

#define TABSTOP 8

int main()
{
    int c;
    int column = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int spaces = TABSTOP - (column % TABSTOP);

            for (int i = 0; i < spaces; ++i)
            {
                putchar(' ');
                ++column;
            }
        }
        else
        {
            putchar(c);

            if (c == '\n')
                column = 0;
            else
                ++column;
        }
    }

    return 0;
}

// 12 tab -> 4 spaces
// 8 - 4 = 4 spaces

// 3 tab -> 5 spaces
// ...