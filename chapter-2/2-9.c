/*
    Exercise 2-9. In a two's complement number system, x &.= ( x-1 ) deletes the
    rightmost 1-bit in x. Explain why. Use this observation to write a faster version
    of bitcount.
*/

#include <stdio.h>

int bitcount(int x);

int main()
{
    printf("bitcount result: %d", bitcount(15));

    return 0;
}

int bitcount(int x)
{
    int n;

    for (n = 0; x != 0; n++)
        x &= x - 1;

    return n;
}
