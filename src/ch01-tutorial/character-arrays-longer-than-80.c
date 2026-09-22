#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    int lines_above_80_chars_index = 0;
    char lines_above_80_chars[MAXLINE][MAXLINE]; /* longest lines saved here */

    while ((len = getline2(line, MAXLINE)) > 0)
    {
        if (len >= 80)
        {
            int i;
            i = 0;
            while ((lines_above_80_chars[lines_above_80_chars_index][i] = line[i]) != '\0')
                ++i;
            ++lines_above_80_chars_index;
        }
    }

    for (int i = 0; i < lines_above_80_chars_index; i++)
    {
        printf("%s", lines_above_80_chars[i]);
    }
    // printf("%s", longest); // todo: what does %s do?

    return 0;
}

/* getline: read a line into s, return length */
int getline2(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    } // add back the new line

    s[i] = '\0'; // null terminating operator for char arrays.

    return i;
}