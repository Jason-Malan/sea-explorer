#include <stdio.h>

void squeeze(char s[], char sr[]);

int main() 
{
    char input[] = "Hi, how are you?";

    squeeze(input, "Not bad, thanks for asking!");

    printf("%s", input);

    return 0;
}

void squeeze(char s[], char sr[]) 
{
    int i = 0, j = 0;
    while (s[i] != '\0') 
    {
        int existInRight = 1;
        int k = 0;
        while (sr[k] != '\0')
        {
            if (s[i] == sr[k++])
            {
                existInRight = 0;
                break;
            }
        }

        if (existInRight == 1)
        {
            s[j++] = s[i];
        }

        ++i;
    }

    s[j] = '\0';
}