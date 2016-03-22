/*
 * Exercise: Experiment to find out what happens when printf's argument string
 * contains \c, where c is some character not listed above.
 *
 * Answer: The compiler gives a warning "expected ';' before '}' token" and
 * prints a c character where the \c would be.
 */

#include <stdio.h>

int main()
{
    printf("hello, \cworld\n");
}
