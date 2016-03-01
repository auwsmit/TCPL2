/* Exercise: Write a version of itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough. */

#include <stdio.h>
#include <math.h>
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

void itoa(int n, char s[], int w)
{
    int i, sign;
    int max_negative_value = -pow(2, sizeof(int)*8-1);

    if (n == max_negative_value) {
        max_negative_value = 1;
        n = n+1;
    }
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        if (n == 0)
            s[i++] = ' ';
        else
            s[i++] = n % 10 + '0';
    } while (((n /= 10) > 0) || i < w);
    if (max_negative_value == 1)
        s[0]++;
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    int num, width;
    char string[MAXLEN];

    printf("\nEnter a number for conversion: ");
    scanf(" %d", &num);
    printf("Enter a minimum field width: ");
    scanf(" %d", &width);

    itoa(num, string, width);
    printf("\n       Normal: %d\nMin Width %3d: %s\n\n", num, width, string);

    return 0;
}
