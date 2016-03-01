/* Exercise: In a two's compliment number system, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
 *  regardless of the machine on which it runs. */

/* Result: It doesn't handle the largest negative number, because that value
 * cannot be simply inverted without causing an overflow.
 *
 * The overflow occurs because of how binary numbers are stored. An unsigned
 * character, for example, can have 256 values, including zero. If the character
 * is signed, those possible values are split in half to represent the possible
 * range of positive and negative numbers. Because the unsigned value is even,
 * there ends up being two zeros; a positive and a negative. Having two zeros is
 * inefficient, so something has to change. Instead of having a negative zero,
 * the value that would be negative zero is added to the negative range and
 * represents the largest possible negative value.
 *
 * In summary:
 * 1. (unsigned char) range is: 0 through 255
 * 2. (signed char) range would be: -127 through 127, including -0 and +0
 * 3. negative zero is bad, so it needs to go
 * 4. -0 is added to the negative range as -128
 * 5. (signed char) range ends up as: -128 through 128
 *
 * So when the largest negative value becomes inverted, its behavior is
 * undefined, since there's no valid way to represent that number.
 *
 * The solution is to check for the largest negative value, add one to it so
 * that itoa works correctly, and then manually increase the value by one in the
 * string. Ta-da!
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

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

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void itoa_new(int n, char s[])
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
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (max_negative_value == 1)
        s[0]++;
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    int num = -pow(2, sizeof(int)*8-1);
    char stringA[MAXLEN];
    char stringB[MAXLEN];

    itoa(num, stringA);
    itoa_new(num, stringB);

    printf("\nLargest Negative Integer: %d\n", num);
    printf("Original itoa: %s\nNew itoa:      %s\n\n", stringA, stringB);

    return 0;
}
