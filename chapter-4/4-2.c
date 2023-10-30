/*
    Exercise 4-2. Extend atof to handle scientific notation of the form
    123.45e-6
    where a floating-point number may be followed by e or E and an optionally
    signed exponent.
*/

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
    printf("atof result: %.8f\n", atof("123.45e-6"));

    return 0;
}

double atof(char s[])
{
    int i, sign, power, esign, epow, e;
    double val;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;

    for (epow = 0; isdigit(s[i]); i++)
        epow = 10 * epow + (s[i] - '0');

    for (e = 1; epow > 0; epow--, e *= 10)
        ;

    if (esign < 0)
        return sign * val / power / e;
    else
        return sign * val / power * e;
}
