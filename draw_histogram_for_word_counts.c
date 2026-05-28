#include <stdio.h>

#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'

int draw_histogram_for_word_counts()
{
    int c;
    int len = 0;
    int word[100];

    while ((c = getchar()) != EOF)
    {
        if (c == SPACE || c == TAB || c == NEWLINE)
        {
            if (len != 0)
            {
                for (int i = 0; i < len; i++)
                {
                    putchar(word[i]);
                }

                printf("%-15s", ": ");

                for (int i = 0; i < len; i++)
                {
                    putchar('=');
                }

                printf("\n");

                // reset word as well or i guess not since i just go for the length
                len = 0;
            }
        }
        else
        {
            if (len < 99)
            {
                word[len] = c;
                len++;
            }
        }
    }

    return 0;
}

int main()
{
    return draw_histogram_for_word_counts();
}