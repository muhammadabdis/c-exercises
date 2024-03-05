/*
 * Exercise 3-5. Write the function itob(n, s, b) that converts the integer n
 * into a base b character representation in the string s. In particular,
 * itob(n, s, 16) formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itob(int n, char s[], int b);
int abs(int n);
void reverse(char s[]);

int main()
{
    char s[MAXLINE];
    int n, base;

    n = 27;
    base = 16;
    itob(n, s, base);
    printf("%d to base %d string: %s\n", n, base, s);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i, digit, sign;

    sign = n;
    i = 0;
    do {
        digit = abs(n % b);
        if (digit > 9)
            s[i++] = digit - 10 + 'A';
        else
            s[i++] = digit + '0';
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
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

    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
