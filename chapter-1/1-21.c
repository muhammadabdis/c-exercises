/*
    Exercise 1-21. Write a program entab that replaces strings of blanks by the
    minimum number of tabs and blanks to achieve the same spacing. Use the
    same tab stops as for detab. When either a tab or a single blank would suffice
    to reach a tab stop, which should be given preference?
*/

#include <stdio.h>

#define TAB 4

int main() {
    int c;
    int ns, pos;
    ns = pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++ns;

            // convert space to tab
            int tabstop = TAB - (pos % TAB);
            if (ns == tabstop) {
                putchar('\t');
                pos = pos + tabstop;
                ns = 0;
            }
        } else {
            // print remaining space
            for (int i = 0; i < ns; ++i)  {
                putchar(' ');
            }
            pos = pos + ns;
            ns = 0;
            
            putchar(c);
            ++pos;
        }

        if (c == '\n') {
            pos = 0;
        }
    }

    return 0;
}