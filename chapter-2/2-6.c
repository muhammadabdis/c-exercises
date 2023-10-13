#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
  printf("setbits result: %d", setbits(18, 3, 2, 22));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
}
