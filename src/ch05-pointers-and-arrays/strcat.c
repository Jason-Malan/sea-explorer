#include <stdio.h>

char* strcat(char* s, char* t)
{
    int i = 0, j = 0;

    while (s[i] != '\0')
        i++;

    while ((s[i++] = t[j++]) != '\0')
        ;

    return s;
}

int main(void)
{
    char op1[100] = "Jason";
    char op2[] = " Malan";

    printf("%s", strcat(op1, op2));
    
    return 0;
}