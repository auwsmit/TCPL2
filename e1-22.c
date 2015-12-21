/* Exercise: Write a program to "fold" long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th column
 * of input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. */

#include <stdio.h>

#define TABSIZE 8   /* The length of a tab character */
#define MAXLEN  50  /* The maximum length that lines will be shortened to */

void print_buffer(char buffer[], int* i, int* len, int* tab);

int main(void)
{
    int ch, len, i, tab;
    char buf[MAXLEN+1];

    len = i = 0;
    tab = TABSIZE;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            print_buffer(buf, &i, &len, &tab);
            continue;
        }
        buf[i++] = ch;
        if (ch == '\t') {
            len = len + tab;
            tab = TABSIZE;
        }
        else {
            ++len;
            --tab;
        }
        if (len >= MAXLEN) {
            print_buffer(buf, &i, &len, &tab);
        }
        if (tab == 0)
            tab = TABSIZE;
    }
    print_buffer(buf, &i, &len, &tab);

    return 0;
}

void print_buffer(char buf[], int* i, int* len, int* tab)
{
    buf[*i] = '\0';
    printf("%s\n", buf);
    *len = *i = 0;
    *tab = TABSIZE;
}
