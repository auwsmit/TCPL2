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

    /* error checking for invalid values */
    if (year < 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i <= month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    /* error checking for invalid values */
    if (year <= 0 || yearday <= 0 || yearday > 366)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (leap == 0 && yearday == 366)
        return -1;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;

    return 0;
}

/* print_num_end: prints the correct ending for num */
void print_num_end(int num)
{
    if (num == 11 || num == 12 || num == 13) {
        printf("th");
        return;
    }
    switch(num % 10) {
        case 1: printf("st");
                break;
        case 2: printf("nd");
                break;
        case 3: printf("rd");
                break;
        default: printf("th");
    }
}

/* print_month: prints the name of the month */
void print_month(int month)
{
    static char *names[13] = { "",
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };
    printf("%s", names[month]);
}

int main(void)
{
    int month, day, year, yearday, error;

    printf("Enter a date (MM/DD/YYYY): ");
    scanf(" %d / %d / %d", &month, &day, &year);

    yearday = day_of_year(year, month, day);
    if (yearday == -1) {
        printf("Invalid values!\n\n");
        return 1;
    }

    printf("That's the %d", yearday);
    print_num_end(yearday);
    printf(" day of that year!\n");

    printf("\nEnter a year: ");
    scanf(" %d", &year);
    printf("Enter a day out of that year (0-366): ");
    scanf(" %d", &yearday);

    error = month_day(year, yearday, &month, &day);
    if (error == -1) {
        printf("Invalid values!\n\n");
        return 1;
    }

    printf("That day is ");
    print_month(month);
    printf(" %d", day);
    print_num_end(day);
    printf("!\n\n");

    return 0;
}
