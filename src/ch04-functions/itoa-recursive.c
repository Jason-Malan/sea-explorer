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

void itoa(int n, char s[]) 
{
    int i, sign;
    
    sign = n;

    i = 0;
    do {
        int digit = n % 10;
        if (digit < 0) 
        {
            digit = -digit;
        }
        s[i++] = digit + '0';
    } while ((n /= 10) != 0);
    
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int itoa_recursive(int n, int s_pos, char s[])
{
    int digit = n % 10;
    int sign = n;

    if ((n /= 10) != 0) 
    {
        s_pos = itoa_recursive(n, s_pos, s);
    } 

    if (n == 0) 
    {
        if (sign < 0) 
        {
            s[s_pos++] = '-';
        }
    }

    if (digit < 0)
    {
        digit = -digit;
    }
    s[s_pos++] = digit + '0';
    s[s_pos] = '\0';

    return s_pos;
}

int main()
{
    char output[100];
    int input_num = -12345;

    // itoa(input_num, output);
    itoa_recursive(input_num, 0, output);

    printf("%s", output);

    return 0;
}