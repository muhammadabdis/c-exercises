/*
 * Exercise 4-1. Write the function strrindex(s, t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>

#define MAXLINE 1000

int strindex(char s[], char t[]);

int main()
{
    char line[] = "Ah Love! could you and I with Fate conspire, Re-mould it nearer to the Heart's Desire!";
    char pattern[] = "ould";

    printf("rightmost strindex: %d\n", strindex(line, pattern));
    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k, found;

    found = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            found = i;
    }
    return found;
}
