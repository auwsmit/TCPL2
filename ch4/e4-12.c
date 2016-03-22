/*
 * Exercise: Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLEN 256

void itoa(int n, char s[])
{
    int sign;
    static i = 0;

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

int main(void)
{
    int num = -891212;
    char string[MAXLEN];

    itoa(num, string);

    printf("\nRecursive itoa: %s\n\n", string);

    return 0;
}
