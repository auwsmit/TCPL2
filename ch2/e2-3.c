/*
 * Exercise: Write a function htoi(s), which converts a string of hexadecimal
 * digits (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 256 /* max size of user input */

int atoi_KR(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int htoi(char s[])
{
    int i, n;

    n = 0;
    if (s[0] == '0' && toupper(s[1]) == 'X')
        i = 2;
    else
        i = 0;
    for (; isalnum(s[i]); ++i) {
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F')
            n = 16 * n + (toupper(s[i]) - 'A') + 10;
        else
            n = 16 * n + (s[i] - '0');
    }
    return n;
}

int main(void)
{
    char input_string[BUFSIZE];

    printf("Enter a hex number: ");
    fgets(input_string, BUFSIZE, stdin);
    printf("Your number in decimal: %d\n\n", htoi(input_string));

    return 0;
}
