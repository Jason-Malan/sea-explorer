#include <stdio.h>

#define MAXLINE 1000

int getline(char *input_line)
{
    int c;

    char *start = input_line;

    while ((c = getchar()) != EOF && c != '\n')
    {
        *input_line++ = c;    
    }

    *input_line = '\0';
    

    return input_line - start;
}

int main(void)
{
    char input_line[MAXLINE];

    while (getline(input_line) != 0)
    {
        printf("%s\n", input_line);
    }

    return 0;
}