/*
    Exercise 2-8. Write a function rightrot ( x, n) that returns the value of the
    integer x rotated to the right by n bit positions.
*/

#include <stdio.h>

int bitsize();
int rightrot(int x, int n);

int main()
{
    printf("right rotate result: %d", rightrot(1, 1));

    return 0;
}

int rightrot(int x, int n)
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