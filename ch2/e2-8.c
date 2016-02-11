/* Exercise: Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n bit positions. */

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

/* recursive! */
unsigned rightrot(unsigned x, int n)
{
    if (n == 0)
        return x;
    else
        rightrot((((01 & x) << sizeof(x)*8-1) | (x >> 1)), --n);
}

int main(void)
{
    unsigned x = 138;
    int rotation_amt = 5;

    printf("x before: ");
    print_bits(x, sizeof(x));
    printf("x after:  ");
    print_bits(rightrot(x, rotation_amt), sizeof(x));

    return 0;
}
