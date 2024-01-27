/*
    Exercise 5-4. Write the function strend(s, t), which returns 1 if the string
    t occurs at the end of the string s, and zero otherwise.
*/

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
    char s[] = "lorem";
    char t[] = "kuy";

    printf("does end match: %d\n", strend(s, t));

    return 0;
}

int strend(char *s, char *t)
{
    int len = strlen(t);

    while (*s != '\0')
        s++;
    while (*t != '\0')
        t++;

    while (len > 0)
    {
        if (*s == *t)
        {
            s--;
            t--;
            len--;
        }
        else
            return 0;
    }

    return 1;
}
