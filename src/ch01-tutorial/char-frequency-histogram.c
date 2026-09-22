#include <stdio.h>

#define MAX_CHARACTERS 128

int main()
{
    int c;
    int char_counter[MAX_CHARACTERS] = {0};

    while ((c = getchar()) != EOF && c < MAX_CHARACTERS)
    {
        char_counter[c]++;
    }

    for (int i = 0; i < MAX_CHARACTERS; i++)
    {
        printf("%3d: %d \n", i, char_counter[i]);
    }

    return 0;
}