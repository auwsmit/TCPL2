/* Write the function any(s1,s2), which returns the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library function strpbrk does the same job
 * but returns a pointer to the location.) */

#include <stdio.h>

#define BUFSIZE 256 /* max size of user input */

int any(char s1[], char s2[])
{
    int c, i, pos = -1;
    for (c = 0; s2[c] != '\n'; ++c)
        for (i = 0; s1[i] != '\n'; ++i)
            if (s1[i] == s2[c] && (pos == -1 || i < pos))
                pos = i;
    return pos;
}

int main(void)
{
    char input_string[BUFSIZE];
    char chars[BUFSIZE];
    int ret;

    printf("Enter some text: ");
    fgets(input_string, BUFSIZE, stdin);
    printf("Enter one or more characters: ");
    fgets(chars, BUFSIZE, stdin);

    ret = any(input_string, chars);
    if (ret != -1)
        printf("The first of any characters was "
                "found at position: %d\n\n", ret);
    else
        printf("No characters found.\n\n");

    return 0;
}
