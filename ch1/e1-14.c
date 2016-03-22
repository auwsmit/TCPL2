/*
 * Exercise: Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>

int main(void)
{
    int c, i, j, nchars[256];

    for (i = 0; i < 256; ++i)
        nchars[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t')
            ++nchars[c];
    }

    for (i = 0; i < 256; ++i) {
        if (nchars[i] == 0) continue;
        printf("%c |", i);
        for (j = 0; j < nchars[i]; ++j)
            putchar('#');
        putchar('\n');
    }
}
