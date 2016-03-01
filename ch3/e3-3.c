/* Exercise: Write a function expand(s1, s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally. */

#define MAXLEN 256
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[])
{
    int i, j, k, dash = FALSE, diff;
    char lastchar = FALSE;

    for (i = 0, j = 0; s1[i] != '\0'; ++i) {

        if (j == MAXLEN)
            break;

        if (dash == TRUE) {
            dash = FALSE;

            if ((isalpha(lastchar) && isalpha(s1[i])) ||
                (isdigit(lastchar) && isdigit(s1[i]))) {
                diff = tolower(s1[i]) - lastchar;
                s2[j-1] = lastchar;
                if (diff >= 0) {
                    for (k = 1; k <= diff; ++k) {
                        s2[j++] = lastchar+k;
                    }
                }
                else {
                    for (k = -1; k >= diff; --k) {
                        s2[j++] = lastchar+k;
                    }
                }
                lastchar = s2[j-1];
                continue;
            }
            else {
                s2[j++] = '-';
                s2[j++] = s1[i];
            }
            lastchar = FALSE;
            continue;
        }

        if (lastchar) {
            if (s1[i] == '-') {
                dash = TRUE;
                continue;
            }
            lastchar = FALSE;
        }

        if (isalnum(s1[i])) {
            lastchar = tolower(s1[i]);
        }
        s2[j++] = s1[i];
    }

    s2[j] = '\0';
}

int main(void)
{
    char input_string[MAXLEN];
    char new_string[MAXLEN];

    printf("Enter a string: ");
    fgets(input_string, MAXLEN, stdin);

    expand(input_string, new_string);

    printf("Unexpanded: %s", input_string);
    printf("Expanded: %s\n", new_string);

    return 0;
}
