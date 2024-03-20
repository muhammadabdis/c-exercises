/*
 * Exercise 4-10. An alternate organization uses getline to read an entire input
 * line; this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define BUFSIZE 100
#define MAXVAL 100
#define MAXLINE 1000
#define NUMBER '0'
#define FUNC '1'
#define VAR '2'

int getop(char s[]);
void push(double num);
double pop();
double top();
void clear();
void sfunc(char s[]);
int getline(char s[], int lim);

double val[MAXVAL];
int vp = 0;
char line[MAXLINE];
int lp = 0;

int main()
{
    char op[MAXOP];
    double varval[26];
    int optype, var;
    double val2;

    while ((optype = getop(op)) != EOF) {
        switch (optype) {
        case NUMBER:
            push(atof(op));
            break;
        case FUNC:
            sfunc(op);
            break;
        case VAR:
            push(varval[op[0] - 'A']);
            var = op[0];
            break;
        case '=':
            pop();
            varval[var - 'A'] = pop();
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            val2 = pop();
            push(pop() - val2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            val2 = pop();
            if (val2 != 0.0)
                push(pop() / val2);
            else
                printf("error: division by zero\n");
            break;
        case '%':
            val2 = pop();
            if (val2 != 0.0)
                push(fmod(pop(), val2));
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

int getop(char op[])
{
    int c, i;

    if (line[lp] == '\0') {
        if (getline(line, MAXLINE) == 0)
            return EOF;
        else
            lp = 0;
    }
    while ((op[0] = c = line[lp++]) && c == ' ' || c == '\t')
        ;
    op[1] = '\0';
    i = 0;
    if (c >= 'A' && c <= 'Z')
        return VAR;
    if (c >= 'a' && c <= 'z') {
        while ((op[++i] = c = line[lp++]) >= 'a' && c <= 'z')
            ;
        op[i] = '\0';
        lp--;
        return FUNC;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-' || isdigit(c))
        while (isdigit(op[++i] = c = line[lp++]))
            ;
    if (c == '.')
        while (isdigit(op[++i] = c = line[lp++]))
            ;
    op[i] = '\0';
    lp--;
    if (strcmp(op, "-") == 0)
        return '-';
    return NUMBER;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

void push(double f)
{
    if (vp < MAXVAL)
        val[vp++] = f;
    else
        printf("error: stack full\n");
}

double pop()
{
    if (vp > 0)
        return val[--vp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top()
{
    return val[vp];
}

void clear()
{
    while (vp > 0)
        val[--vp] = 0.0;
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
