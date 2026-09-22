#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main()
{
    int input = 8; // 00001000

    int result = setbits(input, 3, 2, 1);

    int expected_output = 4; // 00000100
    printf("Expected: %d and Actual: %d", expected_output, result);
}

/*
Exercise 2-6.
Write a function setbits(x,p,n,y)
that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.

Calc X with N bits that begin at POS p.
Calc rightmost bits of Y from N.

01101100
00001000
*/
unsigned setbits(unsigned x, int p, int n, int y)
{
    unsigned mask = ~(~0 << n);                  // if n is 2: 0000 -> 0011
    unsigned shifted_mask = mask << (p + 1 - n); // if p is 3: 0011 -> 1100
    x = x & ~shifted_mask;                       // if x is 1000 -> 0000
    int bits_to_or = (y & mask) << (p + 1 - n);
    return x | bits_to_or;
}