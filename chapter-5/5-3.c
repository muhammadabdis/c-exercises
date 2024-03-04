/*
 * Exercise 5-3. Write a pointer version of the function strcat that we showed
 * in Chapter 2: strcat(s, t) copies the string t to the end of s.
 */

#include <stdio.h>

void stringcat(char *s, char *t);

int main()
{
    char s[] = "ah";
    char t[] = "san";

    stringcat(s, t);
    printf("strcat: %s\n", s);
    return 0;
}

void stringcat(char *s, char *t)
{
    for (; *s != '\0'; s++)
        ;
    while (*s++ = *t++)
        ;
}
