/*
    Exercise 1-19. Write a function reverse (s) that reverses the character
    string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINE 1000

int getlinechars(char line[], int maxline);
void reverse(char line[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getlinechars(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int getlinechars(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void reverse(char line[])
{
    int i, j;
    char temp;

    i = j = 0;
    while (line[j] != '\0')
    {
        ++j;
    }
    --j;

    if (line[j] == '\n')
    {
        --j;
    }

    while (i < j)
    {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        ++i;
        --j;
    }
}
