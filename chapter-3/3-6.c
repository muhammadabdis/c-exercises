/*
 * Exercise 3-6. Write a version of itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itoa(int n, char s[], int w);
int abs(int n);
void reverse(char s[]);

int main()
{
    char s[MAXLINE];

    itoa(20, s, 4);
    printf("itoa: %s\n", s);
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n;
    i = 0;
    do
        s[i++] = abs(n % 10) + '0';
    while ((n = n / 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int abs(int n)
{
    return (n < 0) ? -n : n;
}

void reverse(char s[])
{
    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
