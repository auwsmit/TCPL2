/* Exercise: Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2. */

#include <stdio.h>

#define BUFSIZE 256 /* max size of user input */

void squeeze_original(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void new_squeeze(char s1[], char s2[])
{
    int h, i, j;

    for (h = 0; s2[h] != '\0'; h++) {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] != s2[h]) {
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}

int main(void)
{
    char input_string[BUFSIZE];
    char chars[BUFSIZE];

    printf("Enter some text: ");
    fgets(input_string, BUFSIZE, stdin);
    printf("Enter characters to be removed: ");
    fgets(chars, BUFSIZE, stdin);

    new_squeeze(input_string, chars);
    printf("Result: %s\n\n", input_string);

    return 0;
}
