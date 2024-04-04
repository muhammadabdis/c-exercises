/*
 * Exercise 5-12. Extend entab and detab to accept shorthand
 *      entab -m +n
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB 8

int main(int argc, char **argv)
{
    int c, ns, col, m, n, tab;

    ns = col = m = 0;
    tab = n = TAB;
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
    printf("m: %d, n: %d\n", m, n);
    while ((c = getchar()) != EOF) {
        if (col == m) {
            tab = n;
            col = ns = 0;
        }
        if (c == ' ') {
            ns++;
            if (ns == (tab - (col % tab))) {
                printf("%s", "<tab>");
                col += ns;
                ns = 0;
            }
        } else if (c == '\n') {
            ns = col = 0;
        } else {
            for (; ns > 0; ns--) {
                printf("%s", "<space>");
                col++;
            }
            printf("%c", c);
            col++;
        }
    }
    return 0;
}

