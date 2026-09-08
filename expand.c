#include <ctype.h>
#include <string.h>
#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "-0-9A-Za-b-ca-b";
    char s2[600];

    expand(s1, s2);

    printf("%s", s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    // dash with no pre or post [a-z or A-Z or 0-9] gets printed as is
    // char that is within [a-z or A-Z or 0-9] ranges and has char to right that is -, keeps reading until we find char that has non - to right or no more chars.
        // then we have the range and can simply write that range into s2.

    int s2i = 0;
    char start_range = '\0';
    char end_range = '\0';
    int len = strlen(s1);
    int write_literal_dash = 0;
    for (int i = 0; i < len; i++)
    {
        char c = s1[i];
        if ((c == '-' && i == 0) || (c == '-' && i == len - 1)) 
        {
            write_literal_dash = 1;
        }
        else 
        {
            if (c == '-')
            {
                continue;
            }

            if (start_range == '\0')
            {
                start_range = c;
            }
            else 
            {
                char cToRight = s1[i + 1];
                if ((i == (len - 1)) || cToRight != '-') 
                {
                    end_range = c;
                }
            }
        }

        if (start_range != '\0' && end_range != '\0')
        {
            while (start_range != end_range) {
                s2[s2i++] = start_range++;
                // s2[s2i++] = '-';
            }
            s2[s2i++] = end_range;
            start_range = '\0';
            end_range = '\0';
        }

        if (write_literal_dash == 1)
        {
            s2[s2i++] = '-';
            write_literal_dash = 0;
        }
    }
    s2[s2i] = '\0';
}