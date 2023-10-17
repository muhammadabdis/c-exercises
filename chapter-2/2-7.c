/*
    Exercise 2-7. Write a function invert(x,p,n) that returns x with then bits
    that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
    the others unchanged.
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
    printf("invert result: %d", invert(22, 5, 3));
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ ~(~0 << n) << (p + 1 -n);
}
