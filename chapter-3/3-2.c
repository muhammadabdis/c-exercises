/*
    Exercise 3-2. Write a function escape ( s, t) that converts characters like
    newline and tab into visible escape sequences like \n and \ t as it copies the
    string t to s. Use a switch. Write a function for the other direction as well,
    converting escape sequences into the real characters.
*/

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);
void escape(char s[], char t[]);

int main()
{
    int len;
    char s[MAXLINE];
    char t[MAXLINE];

    while ((len = getlinechars(t, MAXLINE)) > 0)
    {
        escape(s, t);
        printf("%s", s);
    }

    return 0;
}

int getlinechars(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
    {
        line[i] = c;
    }

    line[i] = '\0';

    return i;
}

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; i != '\0'; i++) {
        switch (t[i])
        {
        case '\n':
            s[j] = '\\';
            j++;
            s[j] = 'n';
            break;
        case '\t':
            s[j] = '\\';
            j++;
            s[j] = 't';
            break;
        default:
            s[j] = t[i];
            break;
        }

        j++;
    }
}
