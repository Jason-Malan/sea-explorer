#include <stdio.h>

int strend(char s[], char t[])
{
    int i = 0, j = 0;

    {
        while (s[i] != '\0')
            i++;
        
        while (t[j] != '\0')
            j++;
    }

    i--;
    j--;

    while (i >= 0 && j >= 0)
    {
        if (s[i] != t[j])
        {
            return 0;
        }

        i--;
        j--;
    }

    return j < 0;
}

int main(void)
{
    char op1[] = "Jason is here";
    char op2[] = "Jason is here";

    printf("%d", strend(op1, op2));

    return 0;
}