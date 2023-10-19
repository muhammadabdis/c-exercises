/*
    Exercise 1-20. Write a program detab that replaces tabs in the input with the
    proper number of blanks to space to the next tab stop. Assume a fixed set of
    tab stops, say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TAB 8

int main()
{
    int col = 0;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int tabstop = TAB - (col % TAB);

            for (int i = 0; i < tabstop; ++i)
            {
                putchar(' ');
                ++col;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
        }
        else
        {
            putchar(c);
            ++col;
        }
    }

    return 0;
}
