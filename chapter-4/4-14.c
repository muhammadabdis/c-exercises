/*
 * Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments
 * of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) t z = x; \
    x = y; \
    y = z;

#define dprint(exp) printf(#exp " = %c\n", exp);

int main() {
    char a = 'a';
    char b = 'b';

    swap(char, a, b);
    dprint(a);
    dprint(b);
    return 0;
}
