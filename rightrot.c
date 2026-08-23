#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, unsigned n);

int main()
{
    unsigned input = 4; // 00000100
    unsigned result = rightrot(input, 3);
    unsigned expected = UINT_MAX; // 00100001
    printf("Result: %u \t Expected: %u", result, expected);
}

unsigned rightrot(unsigned x, unsigned n)
{
    unsigned rightmostmask = ~(~0 << n);
    return (x >> n) | ((rightmostmask & x) << ((sizeof(unsigned) * CHAR_BIT) - n));
}
