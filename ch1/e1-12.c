/* Exercise: Write a program that prints its input one word per line. */

#include <stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */

int main(void)
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else {
            putchar(c);
            if (state == OUT)
                state = IN;
        }
    }
    printf("\n\n");
}
