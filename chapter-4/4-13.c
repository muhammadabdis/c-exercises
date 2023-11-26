/*
    Exercise 4-13. Write a recursive version of the function reverse(s), which
    reverses the string s in place.
*/

#include <stdio.h>

#define MAXLEN 1000

void reverse(char s[]);

int main()
{
    char s[MAXLEN] = "abdis salim";

    reverse(s);

    printf("reverse: %s", s);

    return 0;
}

void reverse(char s[])
{
    static int i, j;
    char temp;

    if (s[j] == '\0')
        return;

    j++;

    reverse(s);

    if (i < j)
    {
        temp = s[i];
        s[i++] = s[--j];
        s[j] = temp;
    }
}
