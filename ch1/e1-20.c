/*
 * Exercise: Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?
 */

#include <stdio.h>

#define TABSTOP 8   /* Width of spaces between tabs */

int main(void)
{
    int ch, i;

    for (i = TABSTOP; (ch = getchar()) != EOF; --i) {
        if (i == 0)
            i = TABSTOP;
        if (ch == '\t') {
            for (; i > 0; --i)
                putchar(' ');
            i = TABSTOP+1;
        }
        else {
            putchar(ch);
            if (ch == '\n')
                i = TABSTOP+1;
        }
    }
    return 0;
}
