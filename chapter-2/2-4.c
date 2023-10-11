/*
    Exercise 2-4. Write an alternate version of squeeze ( s 1, s2) that deletes
    each character in s 1 that matches any character in the string s2.
*/

#include <stdio.h>

#define MAXLINE 1000

void getlinechars(char line[], int maxline);
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[MAXLINE];
    char s2[MAXLINE];
    
    printf("s1: ");
    getlinechars(s1, MAXLINE);

    printf("s2: ");
    getlinechars(s2, MAXLINE);

    squeeze(s1, s2);

    printf("Squeezed: %s", s1);

    return 0;
}

void getlinechars(char s[], int lim)
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
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; ++i) {
        for (k = 0; (s1[i] != s2[k]) && (s2[k] != '\0'); ++k);
        if (s2[k] == '\0') {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}
