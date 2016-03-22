/*
 * Exercise: Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main(void)
{
    int c, last_c;

    for (last_c = EOF; (c = getchar()) != EOF; last_c = c) {
        if (c == ' ' && last_c != ' ')
            putchar(c);
        else if (c != ' ')
            putchar(c);
    }

    printf("\n\n");
}
