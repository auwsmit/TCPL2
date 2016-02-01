/* Exercise: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab. When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TABSTOP 8   /* Width of spaces between tabs */

int main(void)
{
    int ch, i, space_count = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            ++space_count;
            if (space_count == TABSTOP) {
                putchar('\t');
                space_count = 0;
            }
        }
        else {
            for (i = 0; i < space_count; ++i)
                putchar(' ');
            space_count = 0;
            putchar(ch);
        }
    }
    for (i = 0; i < space_count; ++i)
        putchar(' ');

    return 0;
}
