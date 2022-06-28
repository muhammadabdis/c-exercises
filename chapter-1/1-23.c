/*
    Exercise 1-23. Write a program to remove all comments from a C program.
    Don't forget to handle quoted strings and character constants properly. C comments do not nest.
*/

#include <stdio.h>

#define MAXLEN 1000

#define OUT 0
#define IN 1

int getlinechars(char linechars[], int maxlen);

int main() {
    int len;
    char linechars[MAXLEN];

    while((len = getlinechars(linechars, MAXLEN)) > 0) {
        printf("%s", linechars);
    }
}

int getlinechars(char linechars[], int maxlen) {
    int c, d;

    int comment = OUT;
    char commenttype = '\0';

    c = getchar();

    int quote = OUT;
    char quotetype = '\0';

    if (c == '"') {
        quote = IN;
        quotetype = 'd';
    }

    if (c == '\'') {
        quote = IN;
        quotetype = 's';
    }

    int i = 0;
    while ((d = getchar()) != EOF && i < maxlen - 1) {
        // Check quote
        if (
            comment == OUT &&
            c != '\\' && d == '"'
        ) {
            if (quote == IN && quotetype == 'd') {
                quote = OUT;
            } else if (quote == OUT) {
                quote = IN;
                quotetype = 'd';
            }
        }

        if (
            comment == OUT &&
            c != '\\' && d == '\''
        ) {
            if (quote == IN && quotetype == 's') {
                quote = OUT;
            } else if (quote == OUT) {
                quote = IN;
                quotetype = 's';
            }
        }

        // Check opening comment
        if (
            comment == OUT && quote == OUT &&
            c == '/' && d == '/'
        ) {
            comment = IN;
            commenttype = 'i';
        }

        if (
            comment == OUT && quote == OUT &&
            c == '/' && d == '*'
        ) {
            comment = IN;
            commenttype = 'm';
        }

        // Print non comment
        if (comment == OUT) {
            linechars[i] = c;
            ++i;
        }

        // Check closing comment
        if (comment == IN && commenttype == 'i' && d == '\n') {
            comment = OUT;
        }

        if (comment == IN && commenttype == 'm' && c == '*' && d == '/') {
            comment = OUT;
            d = getchar();
        }

        // Set previous value
        c = d;
    }

    linechars[i] = c;
    linechars[i+1] = '\0';
    
    return i;
}