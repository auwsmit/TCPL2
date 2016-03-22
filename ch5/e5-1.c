/*
 * Exercise: As written, getint treats a + or - not followed by a digit as
 * a valid representation of zero. Fix it to push such a character back on the
 * input.
 */

#include <stdio.h>
#include <ctype.h>
#define BUFSIZE  100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void);
void ungetch(int c);

/* getint: get next integer from input into *pn */
int getint(int *pn);

int main(void)
{
    int number;

    printf("Enter an integer: ");
    if (getint(&number) != 0)
        printf("Valid integer found: %d\n\n", number);
    else
        printf("No valid integer found!\n\n");

    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else if (c != EOF)
        buf[bufp++] = c;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c)) {
        ungetch(c);     /* + or - without a digit is not a number */
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
