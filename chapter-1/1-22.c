/*
    Exercise 1-22. Write a program to "fold" long input lines into two or more
    shorter lines after the last non-blank character that occurs before the n-th
    column of input. Make sure your program does something intelligent with very
    long lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define MAXLEN 1000
#define MAXLENCHARS 16
#define TAB 8

int getlinechars(char linechars[], int maxlen);

int main() {
    int len;
    char linechars[MAXLEN];

    while((len = getlinechars(linechars, MAXLEN)) > 0) {
        printf("%s", linechars);
    }
}

int getlinechars(char linechars[], int maxlen) {
    int i, c;

    int ls = 0;
    int pos = 0;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        linechars[i] = c;

        if (c == '\t') {
            pos = pos + TAB - (pos % TAB);
        } else {
            ++pos;
        }

        if (c == ' ') {
            // Update last space
            ls = i;
        }

        if (pos > MAXLENCHARS) {
            if (linechars[ls] == ' ') {
                // Replace prev space to newline
                linechars[ls] = '\n';

                // Reset position
                pos = i - ls;
            } else {
                // Add new line before character
                linechars[i] = '\n';
                ++i;
                linechars[i] = c;

                // Reset position
                pos = pos - MAXLENCHARS;
            }

            // Reset last space
            ls = i;
        }
    }

    if (c == '\n') {
        linechars[i] = c;
        ++i;
    }

    linechars[i] = '\0';

    return i;
}