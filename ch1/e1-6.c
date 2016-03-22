/*
 * Exercise: Verify that the expression getchar() != EOF is 0 or 1.
 *
 * Answer: It's 1, unless the character returned is EOF
 */

#include <stdio.h>

int main(void)
{
    if ((getchar() != EOF) == 1)
        printf("\nis 1\n\n");
    else
        printf("\nis 0\n\n");
}
