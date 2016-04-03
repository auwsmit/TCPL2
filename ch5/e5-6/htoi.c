/* see README */
/* from e2-3  */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 256 /* max size of user input */

int htoi(char *s)
{
    int i, n;

    n = 0;
    if (*s == '0' && toupper(*s+1) == 'X')
        i = 2;
    else
        i = 0;
    for (; isalnum(*s); ++s) {
        if (toupper(*s) >= 'A' && toupper(*s) <= 'F')
            n = 16 * n + (toupper(*s) - 'A') + 10;
        else
            n = 16 * n + (*s - '0');
    }
    return n;
}

int main(void)
{
    char input[BUFSIZE];

    printf("Enter a hexadecimal integer: ");
    fgets(input, BUFSIZE, stdin);
    printf("Integer evaluated: %d\n\n", htoi(input));

    return 0;
}
