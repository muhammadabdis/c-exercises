/*
  Exercise 1-24. Write a program to check a C program for rudimentary syntax
  errors like unbalanced parentheses, brackets and braces. Don't forget about
  quotes, both single and double, escape sequences, and comments.
*/

#include <stdio.h>

int inbraces, inparenthesis, inbrackets;

int c;

void incomment(int type);
void inquote(int quote);
void checkincomplete(int c);

int main() {
  extern int inbraces, inparenthesis, inbrackets;

  extern int c;

  while ((c = getchar()) != EOF) {
    if (c == '/') {
      c = getchar();

      if (c == '*') incomment('m');
      if (c == '/') incomment('s');
    }

    if (c == '"' || c == '\'') {
      inquote(c);
    }

    checkincomplete(c);
  }

  if (inbraces != 0) {
    printf("error: Missing braces\n");
    inbraces = 0;
  }

  if (inparenthesis != 0) {
    printf("error: Missing parenthesis\n");
    inparenthesis = 0;
  }

  if (inbrackets != 0) {
    printf("error: Missing brackets\n");
    inbrackets = 0;
  }

  return 0;
}

void incomment(int type) {
  extern int c;

  if (type == 'm') {
    int b;

    b = getchar();
    c = getchar();

    while (b != '*' && c != '/') {
      b = c;
      c = getchar();
    }
  }

  if (type == 's') {
    while ((c = getchar()) != '\n') {}
  }
}

void inquote(int quote) {
  extern int c;

  while ((c = getchar()) != quote) {
    if (c == '\\') c = getchar();
  }
}

void checkincomplete(int c) {
  extern int inbraces, inparenthesis, inbrackets;

  if (c == '{') ++inbraces;
  if (c == '}') --inbraces;
  if (c == '(') ++inparenthesis;
  if (c == ')') --inparenthesis;
  if (c == '[') ++inbrackets;
  if (c == ']') --inbrackets;
}
