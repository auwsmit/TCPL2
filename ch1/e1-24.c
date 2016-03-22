/*
 * Exercise: Write a program to check a C program for rudimentary syntax errors
 * like unbalanced parentheses, brackets, and braces. Don't forget about quotes,
 * both single and double, escape sequences, and comments. (This program is hard
 * if you do it in full generality.)
 */

#include <stdio.h>

#define SINGLE 1
#define DOUBLE 2
#define FALSE 0
#define TRUE 41

int main(void)
{
    int in_quote, in_comment, escape;
    int parens, bracks, braces;
    int ch, last_ch = '\0';

    in_quote = in_comment = escape = FALSE;
    parens = bracks = braces = 0;
    while ((ch = getchar()) != EOF) {

        if (in_quote == FALSE && in_comment == FALSE) {
            switch(ch) {
                case '(': ++parens;
                          break;
                case ')': --parens;
                          break;
                case '[': ++bracks;
                          break;
                case ']': --bracks;
                          break;
                case '{': ++braces;
                          break;
                case '}': --braces;
                          break;
            }
        }

        if (escape == TRUE) {
            escape = FALSE;
            continue;
        }

        if (in_comment == FALSE) {
            if (ch == '\\')
                if (escape == FALSE)
                    escape = TRUE;

            if (last_ch == '/' && ch == '*')
                in_comment = TRUE;
            if (ch == '\"' || ch == '\'') {
                if (in_quote == FALSE)
                    in_quote = (ch == '\'' ? SINGLE : DOUBLE);
                else if ((in_quote == SINGLE && ch == '\'') ||
                        (in_quote == DOUBLE && ch == '\"'))
                    in_quote = FALSE;
            }
        }
        else { /* if in_comment == true */
            if (last_ch == '*' && ch == '/')
                in_comment = FALSE;
        }

        last_ch = ch;
    }

    printf("Results for C program:\n");

    printf("%salanced parentheses!\n", parens     != 0     ? "Unb" : "B");
    printf("%salanced brackets!\n",    bracks     != 0     ? "Unb" : "B");
    printf("%salanced braces!\n",      braces     != 0     ? "Unb" : "B");
    printf("%salanced quotes!\n",      in_quote   != FALSE ? "Unb" : "B");
    printf("%salanced comments!\n\n",  in_comment != FALSE ? "Unb" : "B");

    return 0;
}
