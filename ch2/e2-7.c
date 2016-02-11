/* Exercise: Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
 * the others unchanged. */

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

unsigned invert(unsigned x, int p, int n)
{
    unsigned inv_x = (~x >> (p+1-n)) & ~(~0 << n);
    inv_x = inv_x << (p+1-n);
    unsigned mask = ~(~0 << n) << (p+1-n);
    return (x & ~mask) | inv_x;
}

int main(void)
{
    int n = 7;
    int p = 16;
    unsigned x = ~0;

    printf("x before:       ");
    print_bits(x, sizeof(x));
    printf("x after invert: ");
    print_bits(invert(x, p, n), sizeof(x));

    return 0;
}
