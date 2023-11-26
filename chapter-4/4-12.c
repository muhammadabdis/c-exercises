/*
    Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
    that is, convert an integer into a string by calling a recursive routine.
*/

#include <stdio.h>

#define MAXLEN 1000

void itoa(char s[], int n);

int main()
{
    char s[MAXLEN];

    itoa(s, 9812);

    printf("itoa: %s\n", s);

    return 0;
}

void itoa(char s[], int n)
{
    static int i;

    if (n == 0) {
        i = 0;
        return;
    }

    itoa(s, n / 10);

    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
