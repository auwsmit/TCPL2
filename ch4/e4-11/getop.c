#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;
    static int last = EOF;

    if (last != EOF)
        s[0] = c = last;
    else
        s[0] = c = getch();
    while (c == ' ' || c == '\t')
        s[0] = c = getch();
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    last = c;
    return NUMBER;
}
