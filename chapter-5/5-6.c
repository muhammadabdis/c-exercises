/*
 * Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include getline
 * (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getlinechars(char *s);
int atoi(char *s);
void itoa(char *s, int n);
void reverse(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int main()
{
    char line[100];
    int len;
    char atoistr[] = "20189";
    char itoastr[100];
    char reversestr[] = "lesgo";
    char strtest[] = "lorem ipsum dolor sit amet";
    char strpattern[] = "ipsum";
    char numberopstr[100];

    len = getlinechars(line);
    printf("getline chars: %s\n", line);
    printf("getline return: %d\n", len);
    printf("atoi return: %d\n", atoi(atoistr));
    reverse(reversestr);
    printf("reverse return: %s\n", reversestr);
    itoa(itoastr, 29019);
    printf("itoa return: %s\n", itoastr);
    printf("strindex return: %d\n", strindex(strtest, strpattern));
    printf("getop return: %c\n", getop(numberopstr));
    printf("getop number: %s\n", numberopstr);
    return 0;
}

int getlinechars(char *s)
{
    char *p = s;
    int c;

    while ((c = getchar()) != EOF && c != '\n')
        *p++ = c;
    if (c == '\n')
        p++;
    *p = '\0';
    return p - s;
}

int atoi(char *s)
{
    int n = 0;

    for (; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');
    return n;
}

void itoa(char *s, int n)
{
    for (; n > 0; n /= 10)
        *s++ = n % 10 + '0';
    *s = '\0';
    reverse(s);
}

void reverse(char *s)
{
    char c;
    char *p = s;

    while (*p != '\0')
        p++;
    p--;
    while (s < p)
    {
        c = *p;
        *p-- = *s;
        *s++ = c;
    }
}

int strindex(char *s, char *t)
{
    char *p = s, *u, *q;

    for (; *p != '\0'; p++)
    {
        q = p;
        for (u = t; *u != '\0' && *u == *q; u++, q++)
            ;
        if (*u == '\0')
            return (p - s) + (u - t) - 1;
    }
    return -1;
}

int getop(char *s)
{
    int c;

    while ((*s = c = getc(stdin)) == ' ' || c == '\t')
        ;
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while (isdigit(*s++ = c = getc(stdin)))
            ;
    if (c == '.')
        while (isdigit(*s++ = c = getc(stdin)))
            ;
    *s = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}

