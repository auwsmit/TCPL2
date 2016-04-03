/*
 * Exercise: Write the function itob(n,s,b) that converts the integer n into
 * a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer s.
 */

#include <stdio.h>
#include <string.h>

#define MAXLEN 256

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int base)
{
    int i, sign;
    char c;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        c = n % base;
        if (c >= 10)
            s[i++] = c - 10 + 'A';
        else
            s[i++] = c + '0';
    } while ((n /= base) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    int num, base;
    char string[MAXLEN];

    printf("\nEnter a number for conversion: ");
    scanf(" %d", &num);
    printf("Enter a base to convert to: ");
    scanf(" %d", &base);

    itob(num, string, base);
    printf("\nbase 10: %d\nbase %d:  %s\n\n", num, base, string);

    return 0;
}
