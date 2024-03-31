/*
 * Exercise 5-11. Modify the programs entab and detab (written as exercises in
 * Chapter 1) to accept a list of tab stops as arguments. Use the default tab set-
 * tings if there are no arguments.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TABSTOP 1000

int tabstops[MAX_TABSTOP];
int tp;

int main(int argc, char *argv[])
{
    int col, c, i, j;

    col = 0;
    for (i = 0; --argc > 0; i++)
        tabstops[i] = atoi(*++argv);
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (j = 0; j < tabstops[tp] - col; ++j) {
                putchar(' ');
                ++col;
            }
            tp++;
        } else if (c == '\n') {
            putchar(c);
            tp = 0;
        } else {
            putchar(c);
            ++col;
        }
    }
    return 0;
}
