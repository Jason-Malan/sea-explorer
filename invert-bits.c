
#include <stdio.h>

int invert_bits(int x, int p, int n);

int main()
{
    int input = 72; // 01001000

    int result = invert_bits(input, 3, 2);

    int expected_result = 68; // 01000100

    printf("%d, %d", expected_result, result);

    return 0;
}

/*
Exercise 2-7.
Write a function invert(x,p,n)
that returns x with the n bits that begin at position p inverted
(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

int invert_bits(int x, int p, int n)
{
    int mask = ~(~0 << n);
    int mask_shifted = mask << (p + 1 - n);
    return x ^ mask_shifted;
}