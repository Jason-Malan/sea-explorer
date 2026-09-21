#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[])
{
    int i, c;
    int s_len = strlen(s);

    for (i = s_len; i >= 0; i--)
    {
        int j, k;
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (t[k] == '\0')
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int result = strindex(" mark is wanting to be jason", "mark");

    printf("%d",result);
}