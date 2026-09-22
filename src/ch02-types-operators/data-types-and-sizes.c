#include <stdio.h>
#include <limits.h>

int power(int base, int exponent);

int main() 
{
    printf("char ranges from:\t %d -> %d \n", power(-2, CHAR_BIT - 1), power(2, CHAR_BIT - 1) - 1);
    printf("int ranges from:\t %d -> %d \n", INT_MIN, INT_MAX);
    printf("short ranges from:\t %d -> %d \n", SHRT_MIN, SHRT_MAX);
    printf("long ranges from:\t %d -> %d \n", LONG_MIN, LONG_MAX);
    printf("\n\n");
    printf("unsigned char ranges from:\t %u -> %u \n", 0, UCHAR_MAX);
    printf("unsigned int ranges from:\t %u -> %u \n", 0, UINT_MAX);
    printf("unsigned short ranges from:\t %u -> %u \n", 0, USHRT_MAX);
    printf("unsigned long ranges from:\t %lu -> %lu \n", 0, ULONG_MAX);
    return 1;
}

int power(int base, int exponent) 
{
    int result = 1;
    while (exponent > 0) 
    {
        result = result * base;
        --exponent;
    }
    return result;
}