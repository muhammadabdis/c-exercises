/*
 * Exercise 5-9. Rewrite the routines day_of_year and month_day with
 * pointers instead of indexing.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int month, day;

    printf("%d/%d/%d = %d days\n", 2, 2, 2024, day_of_year(2024, 2, 2));
    month_day(2024, 366, &month, &day);
    printf("%d days = %d/%d/%d", 366, day, month, 2024);
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (year < 1 || month < 1 || day < 1 || month > 12 || day > *(*(daytab + leap) + month))
        return -1;
    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}
