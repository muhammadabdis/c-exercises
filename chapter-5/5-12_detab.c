/*
 * Exercise 5-12. Extend entab and detab to accept the shorthand
 *      entab -m +n
 * to mean tab stops every n columns, starting at column m. Choose convenient
 * (for the user) default behavior.
 */

#include <stdio.h>

#define TAB 8

int main(int argc, char **argv)
{
    int c, i, tab, col, m, n;

    tab = TAB;
    while (--argc > 0) {
        switch (**++argv) {
        case '-':
            m = *++*argv - '0';
            break;
        case '+':
            n = *++*argv - '0';
            break;
        default:
            printf("error: invalid argument\n");
            break;
        }
    } 
    while ((c = getchar()) != EOF) {
        if (col == m)
            tab = m;
        if (c == '\t') {
            for (i = 0; i < (tab - col % tab); i++)
                putchar(' '), col++;
        } else if (c == '\n') {
            col = 0;
        } else {
            putchar(c);
            col++;
        }
    }
    return 0;
}

