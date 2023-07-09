/*
    Exercise 1-17. Write a program to print all input lines that are longer than 80
    characters.
*/

#include <stdio.h>

#define MAXCHARS 1000

int main()
{
    int len, c;
    char chars[MAXCHARS];

    len = 0;
    while ((c = getchar()) != EOF)
    {
        chars[len] = c;
        ++len;
    }

    chars[len] = '\0';

    if (len >= 80)
    {
        printf("\n%s", chars);
    }

    return 0;
}