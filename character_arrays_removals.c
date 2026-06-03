#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int main()
{
    // read lines into cache if not empty

    int trailing_blank_buffer = 0;
    int line_index = 0;
    char lines[MAXLINE][MAXLINE];
    int buffer_index = 0;
    char buffer[MAXLINE];
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            continue;
        }

        if (c == 32)
        {
            ++trailing_blank_buffer;
            continue;
        }

        if (c == '\n' && buffer_index > 0)
        {
            buffer[buffer_index] = '\n';
            buffer[++buffer_index] = '\0';

            int temp_index = 0;
            while ((lines[line_index][temp_index] = buffer[temp_index]) != '\0')
            {
                ++temp_index;
            }

            ++line_index;
            buffer_index = 0;
            trailing_blank_buffer = 0;
            continue;
        }
        else if (c == '\n')
        {
            continue;
        }

        for (int i = 0; i < trailing_blank_buffer; ++i)
        {
            buffer[buffer_index] = 32;
            ++buffer_index;
        }

        trailing_blank_buffer = 0;
        buffer[buffer_index] = c;
        ++buffer_index;
    }

    for (int i = 0; i < line_index; ++i)
    {
        printf("%s", lines[i]);
    }

    return 0;
}
