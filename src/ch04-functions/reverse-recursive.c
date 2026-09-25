#include <stdio.h>

void reverse(char s[], int i, int slen)
{
    int temp;

    if (i < slen)
    {
        temp = s[i];
        s[i++] = s[slen];
        s[slen--] = temp;
        reverse(s, i, slen);
    }
}

int main(void)
{
    char input_string[] = "reverse me";
    int slen = 0;
    while (input_string[slen] != '\0') 
    {
        slen++;
    }
    reverse(input_string, 0, slen - 1);
    printf("%s", input_string);
}