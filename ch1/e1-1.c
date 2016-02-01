/* Exercise: Run the "hello, world" program on your system. Experiment with
 * leaving out parts of the program, to see what error messages you get. */

/* Results:
 *  Using GCC:
 *  - removing "include <stdio.h>" gives a warning:
 *    "implicit declaration of function 'printf'", but the program still
 *    compiles and outputs fine.  I assume the compiler is doing extra work and
 *    fixing would-be errors during compile time.
 *
 *  - removing "int main()" gives an error:
 *    "expected identifier or '(' before '{' token" and doesn't compile.
 *
 *  - removing the top bracket for main gives an error:
 *    "expected declaration specifiers before 'printf'" and doesn't compile.
 *
 *  - misspelling main gives an error:
 *    "x:/windows/mingw/bin/../lib/gcc/mingw32/4.8.1/../../../libmingw32.a(main.o):(.text.startup+0xa7): undefined reference to `WinMain@16'"
 *
 *  - misspelling printf gives a warning:
 *    "incompatible implicit declaration of built-in function 'rintf'"
 *    and error:
 *    "incompatible type for argument 1 of 'rintf'"
 *    The compiler warns me that rintf doesn't exist as a built-in function, and
 *    then (because it has no information on 'rintf') it gives an error for an
 *    incompatible argument type. Doesn't compile.
 *
 *  - removing the semicolon gives an error:
 *    "expected ';' before '}' token" and doesn't compile.
 */

#include <stdio.h>

int main()
{
    printf("hello, world\n");
}
