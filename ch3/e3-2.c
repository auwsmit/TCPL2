/* Exercise: Write a function escape(s,t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies the string
 * t to s. Use a switch. Write a function for the other direction as well,
 * converting escape sequences into the real characters. */

#include <stdio.h>

#define MAXLEN 256

void escape(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; (s[i] != '\0') || (i > MAXLEN); ++i, ++j) {
        switch(s[i])
        {
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;

            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;

            default:
                t[j] = s[i];
                break;
        }
    }
    t[j] = '\0';
}

void epacse(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; (s[i] != '\0') || (i > MAXLEN); ++i, ++j) {
        if (s[i] == '\\') {
            switch(s[i+1])
            {
                case 't':
                    t[j] = '\t';
                    i++;
                    break;

                case 'n':
                    t[j] = '\n';
                    i++;
                    break;

                default:
                    t[j] = s[i];
                    break;
            }
        }
        else
            t[j] = s[i];
    }
    t[j] = '\0';
}

int main(void)
{
    char strA[MAXLEN] = "Here's a string!\t\tand some tabs!\t\nAnd\tnew\nLines!";
    char strB[MAXLEN];

    epacse(strB, strA);
    printf("Test: %s\n", strA);


    printf("Original:  %s\n", strA);
    escape(strA, strB);
    printf("Escaped:   %s\n", strB);
    epacse(strB, strA);
    printf("Unescaped: %s\n", strA);

    return 0;
}
