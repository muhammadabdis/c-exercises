/*
 * Exercise 5-11. Modify the programs entab and detab (written as exercises in
 * Chapter 1) to accept a list of tab stops as arguments. Use the default tab set-
 * (for the user) default behaviour.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TABSTOP 1000

int tabstops[MAX_TABSTOP];
int tp;

int main(int argc, char *argv[])
{
    int c, ns, pos, i, j;

    while (--argc > 0)
        tabstops[j++] = atoi(*++argv);
    while ((c = getchar()) != EOF) {
        if (pos >= tabstops[tp])
            ++tp;
        if (c == ' ') {
            ++ns;
            if (ns == tabstops[tp] - pos) {
                putchar('\t');
                pos += ns;
                ns = 0;
            }
        } else {
            for (i = 0; i < ns; ++i)
                putchar(' ');
            pos += ns;
            putchar(c);
            pos++;
            ns = 0;
        }
        if (c == '\n') {
            pos = 0;
            tp = 0;
        }
    }
    return 0;
}
