#include <stdio.h>

unsigned bitcount(unsigned x);

int main()
{
    unsigned input = 8 | 4 | 2 | 1;
    unsigned result = bitcount(input);
    printf("input: %u \t result: %u", input, result);
    return 0;
}

unsigned bitcount(unsigned x)
{
    unsigned b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 1)
        {
            b++;
        }
    }
    
    return b;
}