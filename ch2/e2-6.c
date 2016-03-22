/*
 * Exercise: Write a function setbits(x,p,n,y) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged.
 */

#include <stdio.h>

void print_bits(unsigned x, size_t s)
{
    int i;
    unsigned check = 1 << (s*8-1);
    for (i = s*8-1; i >= 0; --i) {
        putchar(x & check ? '1' : '0');
        if (!(i % 4)) putchar(' ');
        check = check >> 1;
    }
    putchar('\n');
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned isolated_y = (y & ~(~0 << n)) << (p+1-n);
    unsigned mask = ~(~0 << n) << (p+1-n);
    return (x & ~mask) | isolated_y;
}

int main(void)
{
    int n = 4;
    int p = 6;
    unsigned x = 255;
    unsigned y = 234;

    printf("x before:        ");
    print_bits(x, sizeof(x));
    printf("y:               ");
    print_bits(y, sizeof(y));
    printf("x after setbits: ");
    print_bits(setbits(x, p, n, y), sizeof(x));

    return 0;
}
