/* see README */
/* from e3-5  */

#include <stdio.h>
#include <string.h>

#define MAXLEN 256

void reverse(char *s)
{
    int c;
    char *e = s + strlen(s)-1;

    for (; s < e; s++, e--) {
        c = *s;
        *s = *e;
        *e = c;
    }
}

void itob(int n, char *s, int base)
{
    int sign;
    char c;

    if ((sign = n) < 0)
        n = -n;
    do {
        c = n % base;
        if (c >= 10)
            *s++ = c - 10 + 'A';
        else
            *s++ = c + '0';
    } while ((n /= base) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
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
