/* see README */
/* from a ch2 example */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 256 /* max size of user input */

int atoi_KR(char *s)
{
    int n;

    n = 0;
    for (; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');
    return n;
}

int main(void)
{
    char input[BUFSIZE];

    printf("Enter an integer: ");
    fgets(input, BUFSIZE, stdin);
    printf("Integer evaluated: %d\n\n", atoi_KR(input));

    return 0;
}
