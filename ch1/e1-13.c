/* Exercise: Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging. */

#include <stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */
#define MAX 80   /* maximum length of a word */

int main(void)
{
    int c, i, j, state;
    int word_len, histo[MAX], longest;

    for (i = 0; i < MAX; ++i)
        histo[i] = 0;

    state = OUT;
    word_len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN && word_len <= MAX) {
                ++histo[word_len-1];
            }
            state = OUT;
            word_len = 0;
        }
        else {
            ++word_len;
            if (state == OUT) {
                state = IN;
            }
        }
    }

    /* horizontal histogram */
    putchar('\n');
    for (i = 0; i < MAX; ++i) {
        if (histo[i] == 0) continue;
        printf("%3d |", i+1);
        for (j = 0; j < histo[i]; ++j)
            putchar('#');
        putchar('\n');
    }
    printf("\n");

    /* vertical histogram */
    longest = 0;
    for (i = 0; i < MAX; ++i)
        if (histo[i] > longest)
            longest = histo[i];
    for (i = longest-1; i >= 0; --i) {
        for (j = 0; j < MAX; ++j) {
            if (histo[j] == 0) continue;
            if (histo[j] > i)
                printf(" # ");
            else
                printf("   ");
        }
        putchar('\n');
    }
    for (i = 0; i < MAX; ++i) {
        if (histo[i] == 0) continue;
        printf("---");
    }
    putchar('\n');
    for (i = 0; i < MAX; ++i) {
        if (histo[i] == 0) continue;
        printf("%2d ", i+1);
    }
    printf("\n\n");
}
