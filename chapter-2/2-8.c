/*
    Exercise 2-8. Write a function rightrot ( x, n) that returns the value of the
    integer x rotated to the right by n bit positions.
*/

#include <stdio.h>

int bitsize();
unsigned rightrot(unsigned x, int n);

int main()
{
    printf("right rotate result: %d", rightrot(2, 1));

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int rbit;

    rbit = x << (bitsize() - n);
    x = x >> n;
    x = x | rbit;

    return x;
}

int bitsize()
{
    int i;
    unsigned v = ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}