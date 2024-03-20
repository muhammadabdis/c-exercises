/*
 * Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint:
 * use an internal static variable.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define BUFSIZE 100
#define MAXVAL 100
#define NUMBER '0'

int getop(char s[]);
int getch();
void ungetch(int c);
void push(double num);
double pop();

char buf[BUFSIZE];
int bufp = 0;
double val[MAXVAL];
int sp = 0;

int main()
{
    char s[MAXOP];
    int type;
    double op2;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: division by zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: division by zero\n");
            break;
        case '\n':
            printf("= %.8g\n", pop());
            break;
        default:
            printf("error: invalid character\n");
            break;
        }
    }
    return 0;
}

int getop(char s[])
{
    int c, i;
    static int lastchar = 0;

    if (lastchar != 0) {
        c = lastchar;
        lastchar = 0;
    } else
        c = getch();
    while ((s[0] = c) && c == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-' || isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastchar = c;
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
