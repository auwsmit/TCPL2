/*
 * Exercise: There is no error checking in day_of_year or month_day.
 * Remedy this defect.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
        return -1; /* invalid dates */

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (leap == 0 && month == 2 && day == 29)
        return -1; /* Feb. 29 in a non-leap year */
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (year <= 0 || yearday <= 0 || yearday > 366)
        return -1; /* invalid values */

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (leap == 0 && yearday == 366)
        return -1;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;

    return 0;
}

/* num_end: returns the correct ending for num */
char *num_end(int num)
{
    if (num == 11 || num == 12 || num == 13) {
        return "th";
    }
    switch(num % 10) {
        case 1: return "st";
                break;
        case 2: return "nd";
                break;
        case 3: return "rd";
                break;
        default: return "th";
                 break;
    }
}

/* month_name: return the name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(void)
{
    int month, day, year, yearday, error;

    printf("\nEnter a date (MM/DD/YYYY): ");
    scanf(" %d / %d / %d", &month, &day, &year);

    yearday = day_of_year(year, month, day);
    if (yearday == -1) {
        printf("Invalid values!\n\n");
        return 1;
    }

    printf("That's the %d%s day of that year!\n",
           yearday, num_end(yearday));

    printf("\nEnter a year: ");
    scanf(" %d", &year);
    printf("Enter a day out of that year (0-366): ");
    scanf(" %d", &yearday);

    error = month_day(year, yearday, &month, &day);
    if (error == -1) {
        printf("Invalid values!\n\n");
        return 1;
    }

    printf("That day is %s %d%s!\n\n",
           month_name(month), day, num_end(day));

    return 0;
}
