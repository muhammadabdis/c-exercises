/*
 * Exercise 2-3. Write the function htoi ( s), which converts a string of hexadecimal
 * digits (including an optional Ox or ox) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);
int htoi(char s[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getlinechars(line, MAXLINE)) > 0)
        printf("%d\n", htoi(line));
    return 0;
}

int getlinechars(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int htoi(char s[])
{
    int i, n, hexdigit;
    int inhex = 1;

    i = 0;
    if (s[i] == '0')
    {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;
    hexdigit = 0;
    for (; inhex == 1; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            inhex = 0;
        if (inhex) 
            n = 16 * n + hexdigit;
    }
    return n;
}
