/*
 * Exercise 3-3. Write a function expand(s1 , s2) that expands shorthand notations
 * like a-z in the string s1 into the equivalent complete list abc...xyz in
 * s2. Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 * taken literally.
 */

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);
void expand(char s1[], char s2[]);

int main()
{
    int len;
    char s1[MAXLINE];
    char s2[MAXLINE];

    while ((len = getlinechars(s1, MAXLINE)) > 0)
    {
        expand(s1, s2);
        printf("%s", s2);
    }
    return 0;
}

int getlinechars(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

void expand(char s1[], char s2[])
{
    int i, j, c;

    i = j = 0;
    while ((c = s1[i++]) != '\0')
    {
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            i++;
            while (c < s1[i])
                s2[j++] = c++;
        }
        else
            s2[j++] = c;
    }
    s2[j] = '\0';
}
