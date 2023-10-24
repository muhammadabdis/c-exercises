/*
    Exercise 2-5. Write the function any ( s 1 , s2), which returns the first location
    in the string s 1 where any character from the string s2 occurs, or -1 if s 1
    contains no characters from s2. (The standard library function strpbrk does
    the same job but returns a pointer to the location.)
*/

#include <stdio.h>

#define MAXLINE 1000

void getlinechars(char line[], int maxline);
int any(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("s1: ");
    getlinechars(s1, MAXLINE);

    printf("s2: ");
    getlinechars(s2, MAXLINE);

    int num = any(s1, s2);

    printf("Contains any? %d", num);

    return 0;
}

void getlinechars(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\n'; ++i)
    {
        for (j = 0; s2[j] != '\n'; ++j)
        {
            if (s1[i] == s2[j])
                return i;
        }
    }

    return -1;
}
