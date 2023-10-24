/*
    Exercise 2-2. Write a loop equivalent to the for loop above without using &&
    or ||.
*/

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getlinechars(line, MAXLINE)) > 0)
        printf("%s", line);

    return 0;
}

int getlinechars(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();

        if (c == EOF)
            break;

        if (c == '\n')
            break;

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
