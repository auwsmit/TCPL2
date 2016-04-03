/* see README */
/* from e3-4  */

#include <stdio.h>
#include <string.h>
#include <math.h>

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

void itoa(int n, char *s)
{
    char *orig = s;
    int sign;
    int max_negative_value = -pow(2, sizeof(int)*8-1);

    if (n == max_negative_value) {
        max_negative_value = 1;
        n = n+1;
    }
    if ((sign = n) < 0)
        n = -n;
    s = orig;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (max_negative_value == 1)
        (*orig)++;
    if (sign < 0) {
        *s++ = '-';
    }
    *s = '\0';
    reverse(orig);
}

int main(void)
{
    char string[MAXLEN];
    int num;

    printf("Enter an integer: ");
    scanf(" %d", &num);
    itoa(num, string);
    printf("Converted to string: %s\n\n", string);

    return 0;
}
