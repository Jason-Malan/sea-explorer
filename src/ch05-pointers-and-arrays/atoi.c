#include <ctype.h>
#include <stdio.h>

int my_atoi(char *s)
{
    int i = 0, c, sign = 1;
    
    if (*s == '-')
    {
        sign = -1;
        s++;    
    }

    while (isdigit((c = *s)))
    {
        i = i * 10 + (c - '0');
        s++;
    }

    if (sign == -1)
    {
        i = i * sign;
    }

    return i;
}

int main(void)
{
    char input[] = "123";
    
    printf("%d", my_atoi(input));

    return 0;
}