/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define TAB 8

int main()
{
    int c, ns, pos, i, tabstop;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++ns;
            tabstop = TAB - (pos % TAB);
            if (ns == tabstop) {
                putchar('\t');
                ns = 0;
                pos += tabstop;
            }
        } else {
            for (i = 0; i < ns; ++i)
                putchar(' ');
            pos += ns;
            putchar(c);
            ns = 0;
            pos++;
        }
        if (c == '\n')
            pos = 0;
    }
    return 0;
}
