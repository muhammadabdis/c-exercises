/*
 * Exercise 4-6. Add commands for handling variables. (It's easy to provide
 * twenty-six variables with single-letter names.) Add a variable for the most
 * recently printed value.
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
#define FUNC '1'
#define VAR '2'

int getop(char s[]);
int getch();
void ungetch(int c);
void push(double num);
double pop();
double top();
void clear();
void sfunc(char s[]);

char buf[BUFSIZE];
int bufp = 0;
double val[MAXVAL];
int sp = 0;
double store[26];

int main()
{
    char s[MAXOP];
    int type, var;
    double op2;

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case FUNC:
            sfunc(s);
            break;
        case VAR:
            push(store[s[0] - 'A']);
            var = s[0];
            break;
        case '=':
            pop();
            store[var - 'A'] = pop();
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
            printf("error: invalid operation\n");
            break;
        }
    }
    return 0;
}

int getop(char s[])
{
    int c, i;

    while ((s[0] = c = getch()) && c == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (c >= 'A' && c <= 'Z')
        return VAR;
    if (c >= 'a' && c <= 'z') {
        while ((s[++i] = c = getch()) >= 'a' && c <= 'z')
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return FUNC;
    }
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

double top()
{
    return val[sp];
}

void clear()
{
    while (sp > 0)
        val[--sp] = 0.0;
}

void sfunc(char s[])
{
    double op1, op2;

    if (strcmp(s, "c") == 0)
        clear();
    else if (strcmp(s, "top") == 0)
        printf("top: %.8g\n", top());
    else if (strcmp(s, "dup") == 0)
        op2 = pop(), push(op2), push(op2);
    else if (strcmp(s, "swa") == 0)
        op1 = pop(), op2 = pop(), push(op1), push(op2);
    else if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0)
        op2 = pop(), push(pow(pop(), op2));
    else
        printf("error: unknown function\n");
}
