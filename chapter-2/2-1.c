/*
    Exercise 2-1. Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate
    values from standard headers and by direct computation. Harder if you compute
    them: determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Range of char: %d -> %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of int: %d -> %d\n", INT_MIN, INT_MAX);
    printf("Range of short: %d -> %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of long: %ld -> %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of signed char: %d -> %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char: %u -> %u\n", 0, UCHAR_MAX);
    printf("Range of unsigned int: %u -> %u\n", 0, UINT_MAX);
    printf("Range of unsigned short: %u -> %u\n", 0, USHRT_MAX);
    printf("Range of unsigned long: %u -> %lu\n", 0, ULONG_MAX);
}
