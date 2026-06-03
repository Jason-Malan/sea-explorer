#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char input[] = "this is the voice";
    reverse(input);
    printf("%s", input);
}

void reverse(char s[])
{
    int index = 0;
    int length = strlen(s);
    for (int i = length - 1; index < i; --i)
    {
        char temp = s[index];
        s[index] = s[i];
        s[i] = temp;
        ++index;
    }
}