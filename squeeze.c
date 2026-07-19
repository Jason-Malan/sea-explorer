#include <stdio.h>

int main() 
{
    char input[] = "Hi, how are you?";

    char unwantedCharValue = 'o';

    int i, j;

    for (i = j = 0; input[i] != '\0'; ++i) 
    {
        if (input[i] != unwantedCharValue) 
        {
            input[j++] = input[i];
        }
    }

    input[j] = '\0';

    printf("%s", input);

    return 0;
}