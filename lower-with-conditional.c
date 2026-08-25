#include <stdio.h>
#include <string.h>

void lower(char s[]);

int main()
{
    char input[] = "I LOVE pizza!";
    lower(input);
    printf("Result: %s", input);
    return 0;
}

void lower(char s[])
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
           s[i] = (s[i] >= 'A' && s[i] <= 'Z')
            ? s[i] + ('a' - 'A')
            : s[i];
        }
    }
    
}