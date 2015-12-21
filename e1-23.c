/* Exercise: Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest. */

#include <stdio.h>

#define IN 1        /* inside a comment */
#define OUT 2       /* outside a comment */
#define LINE 3      /* in a comment which spans
                       to the end of the line */

int main(void)
{
    int ch, last_ch, state;

    state = OUT;
    last_ch = '\0';
    while ((ch = getchar()) != EOF) {
        if (state == OUT) {
            if (last_ch == '/' && ch == '*') {
                state = IN;
                continue;
            }
            if (last_ch == '/' && ch == '/') {
                state = LINE;
                continue;
            }
            if (last_ch != '\0')
                putchar(last_ch);
        }
        else if (state == IN) {
            if (last_ch == '*' && ch == '/') {
                state = OUT;
                last_ch = '\0';
                continue;
            }
        }
        else if (state == LINE)
            if (ch == '\n')
                state = OUT;
        last_ch = ch;
    }

    return 0;
}
