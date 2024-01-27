/*
    Exercise 5-5. Write versions of the library functions strncpy, strncat, and
    strncmp; which operate on at most the first n characters of their argument
    strings. For example, strncpy(s, t, n) copies at most n characters of t to s.
    Full descriptions are in Appendix B.
*/

#include <stdio.h>
#include <string.h>

void stringncpy(char *s, char *t, int n);
void stringncat(char *s, char *t, int n);
int stringncmp(char *s, char *t, int n);

int main()
{
    char s[] = "kutuku";
    char t[] = "ayamlucu";

    char u[] = "ci";
    char v[] = "kutik";

    char w[] = "tkw";
    char x[] = "tkww";

    stringncpy(s, t, 4);
    printf("strncpy: %s\n", s);

    stringncat(u, v, 2);
    printf("strncat: %s\n", u);

    printf("strncmp: %d\n", stringncmp(w, x, 4));

    return 0;
}

void stringncpy(char *s, char *t, int n)
{
    int remain = strlen(s) - n;

    while (*t && n-- > 0)
        *s++ = *t++;

    while (remain-- > 0)
        *s++;

    *s = '\0';
}

void stringncat(char *s, char *t, int n)
{
    while (*s != '\0')
        s++;

    while (*t && n-- > 0)
        *s++ = *t++;

    *s = '\0';
}

int stringncmp(char *s, char *t, int n)
{
    while (n-- > 0)
    {
        if (*s != *t)
            return *s - *t;
        if (*s == '\0')
            return 0;
        s++, t++;
    }

    return 0;
}
