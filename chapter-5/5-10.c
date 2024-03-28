/*
 * Exercise 5-10. Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator or operand is a separate
 * argument. For example,
 *    expr 2 3 4 + *
 * evaluates 2 x (3+4).
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double num);
double pop();
void ungetstr(char *s);

int main(int argc, char *argv[])
{
    char s[MAXOP];
    int type;
    double op2;

    while (--argc > 0) {
        ungetstr(*++argv);
        switch (type = getop(s)) {
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
        default:
            printf("error: invalid character\n");
            break;
        }
    }
    printf("result: %.8g\n", pop());
    return 0;
}

#define BUFSIZE 100

int getch();
void ungetch(int c);

char buf[BUFSIZE];
int bufp = 0;

int getop(char s[])
{
    int c, i;

    while ((s[0] = c = getch()) && c == ' ' || c == '\t')
        ;
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
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("error: too many characters\n");
}

void ungetstr(char *s)
{
    ungetch(' ');
    while (*s != '\0')
        ungetch(*s++);
}

#define MAXVAL 100

double val[MAXVAL];
int sp = 0;

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
