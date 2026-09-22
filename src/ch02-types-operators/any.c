#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main()
{
    int index = any("jason is here", "here");
    if (index == -1)
    {
        printf("no chars were a match in s1 from s2...");
    }
    else
    {
        printf("matched on index: %d", index);
    }
}

int any(char s1[], char s2[])
{
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    for (size_t i = 0; i < s2Len; i++)
    {
        char s2Char = s2[i];
        for (size_t k = 0; k < s1Len; k++)
        {
            char s1Char = s1[k];
            if (s2Char == s1Char)
            {
                return k;
            }
        }
    }

    return -1;
}