#include <stdio.h>

static void reverse(char s[])
{
    int i = 0;
    int j = 0;
    char temp;

    while (s[j] != '\0') {
        ++j;
    }

    for (--j; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[], int min_width) 
{
    int i, sign;
    sign = n;

    int width_to_fill = min_width;

    i = 0;
    do {
        int digit = n % 10;
        if (digit < 0) 
        {
            digit = -digit;
        }
        s[i++] = digit + '0';
        width_to_fill--;
    } while ((n /= 10) != 0);
    
    if (width_to_fill > 0)
    {
        for (int j = 0; j < width_to_fill; j++)
        {
            s[i++] = '0';
        }
    }

    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char output[100];
    int input_num = 1234;

    itoa(input_num, output, 5);

    printf("%s", output);

    return 0;
}