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

    int i = 0;
    c = getchar();
    while ((d = getchar()) != EOF && i < maxlen - 1) {
        // Check opening comment
        if (comment == OUT && c == '/' && d == '/') {
            comment = IN;
            commenttype = 'i';
        }

        if (comment == OUT && c == '/' && d == '*') {
            comment = IN;
            commenttype = 'm';
        }

        // Print non comment
        if (comment == OUT) {
            linechars[i] = c;
            ++i;
        }

        // Check closing comment
        if (comment == IN && commenttype == 'i' && c == '\n') {
            comment = OUT;
        }

        if (comment == IN && commenttype == 'm' && c == '*' && d == '/') {
            comment = OUT;
            d = getchar();
        }

        // Set previous value
        c = d;
    }

    linechars[i] = '\0';
    
    return i;
}