/*
    Exercise 1-16. Revise the main routine of the longest-line program so it will
    correctly print the length of arbitrarily long input lines, and as much as possible
    of the text.
*/

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getlinechars(line, MAXLINE)) > 0)
        printf("%d\n", len);

    return 0;
}

int getlinechars(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}
