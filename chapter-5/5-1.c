#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getint(int *);
int getch(void);
void ungetch(int);

int main()
{
    int n, array[SIZE], i;

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    for (i = 0; i < SIZE; i++)
        printf("index %d: %d\n", i, array[i]);

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    *pn = 0;

    while (isspace(c = getch()))
        ;

    if (c != EOF && c != '+' && c != '-' && !isdigit(c))
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
