/*
 * Exercise: In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount.
 *
 * Answer: The statement deletes the rightmost bit because the rightmost 1-bit
 * is changed when any number is subtracted by 1.
 */

#include <stdio.h>

int bitcount_original(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int bitcount_new(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1), ++b);

    return b;
}

int main(void)
{
    unsigned x = 12124;

    printf("Number if 1 bits in %d: %d\n\n", x, bitcount_new(x));

    return 0;
}
