/* Exercise: Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main(void)
{
    long blanks_count, tabs_count, newline_count;
    int c;

    blanks_count = 0;
    tabs_count = 0;
    newline_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++blanks_count;
        else if (c == '\t')
            ++tabs_count;
        else if (c == '\n')
            ++newline_count;
    }

    printf("\nBlanks: %d", blanks_count);
    printf("\nTabs: %d", tabs_count);
    printf("\nNew lines: %d\n\n", newline_count);
}
