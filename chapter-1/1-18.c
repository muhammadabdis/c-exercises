/*
    Exercise 1-18. Write a program to remove trailing blanks and tabs from each
    line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);
int removetrail(char line[]);

int main()
{
    int len, trimmedlen;
    char line[MAXLINE];

    while ((len = getlinechars(line, MAXLINE)) > 0)
    {
        if ((trimmedlen = removetrail(line)) > 0)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int getlinechars(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

int removetrail(char line[])
{
    int i;

    for (i = 0; line[i] != '\n'; ++i)
        ;
    --i;

    while (line[i] == ' ' || line[i] == '\t')
    {
        --i;
    }

    if (i >= 0) {
        ++i;
        line[i] = '\n';
        ++i;
        line[i] = '\0';
    }

    return i;
}