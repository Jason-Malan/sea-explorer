#include <stdio.h>

int main() 
{
    char input[] = {'1', '5', '0', '1'};

    int i, number;
    number = 0;
    for (i = 0; input[i] >= '0' && input[i] <= '9'; ++i)
    {
        number = 10 * number + (input[i] - '0');
    };

    printf("%d", number);

    return 0;
}