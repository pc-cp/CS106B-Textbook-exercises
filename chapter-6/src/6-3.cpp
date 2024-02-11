
/* File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include "calendar.h"
#include "strlib.h"
#include "error.h"

using namespace std;


extern const int UTC = 1970;
extern const int DAYS_IN_LEAP_YEAR = 366;

/* Private Function prototype */
// void error(string msg);

/*
 * Implementation notes: daysInMonth
 * ---------------------------------
 * returns the number of days for a given month and year
 */
int daysInMonth(Month month, int year)
{

    switch (month)
    {
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        return 30;
    case FEBRUARY:
        return (isLeapYear(year)) ? 29 : 28;
    default:
        return 31;
    }
}

/*
 * Implementation notes: isLeapYear
 * --------------------------------
 * tests whether year is a leap year
 */
bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || ( year % 400 == 0);
}

/*
 * Implementation notes: monthToString
 * -----------------------------------
 * converts a Month value to a string.
 */
string monthToString(Month month)
{
    switch(month)
    {
    case JANUARY: return "JANUARY";
    case FEBRUARY: return "FEBRUARY";
    case MARCH: return "MARCH";
    case APRIL: return "APRIL";
    case MAY: return "MAY";
    case JUNE: return "JUNE";
    case JULY: return "JULY";
    case AUGUST: return "AUGUST";
    case SEPTEMBER: return "SEPTEMBER";
    case OCTOBER: return "OCTOBER";
    case NOVEMBER: return "NOVEMBER";
    case DECEMBER: return "DECEMBER";
    default: error("Not exist this month. ");
    }
}

/*
 * Implementation notes: error
 * ---------------------------
 * This function writes out the error message to the cerr stream and
 * then exits the program. The EXIT_FAILURE constant is defined in
 * <cstdlib> to represent a standard failure code.
 */
// void error(string msg)
// {
//     cerr << msg << endl;
//     exit(EXIT_FAILURE);
// }


/*
 * Implementation notes: operator++(prefix)
 * ----------------------------------------
 * ...
 */

Month operator++(Month &month)
{
    month = Month(month + 1);
    return month;
}

/*
 * Implementation notes: operator++(suffix)
 * ----------------------------------------
 * ...
 */
Month operator++(Month &month, int)
{
    Month old = month;
    month = Month(month + 1);
    return old;
}

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variable day, month and year.
 */

Date::Date()
{
    day = 1;
    month = JANUARY;
    year = 1900;
}

Date::Date(Month cmonth, int cday, int cyear)
{
    day = cday;
    month = cmonth;
    year = cyear;
}

Date::Date(int cday, Month cmonth, int cyear)
{
    day = cday;
    month = cmonth;
    year = cyear;
}

/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 */
int Date::getDay()
{
    return day;
}

Month Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

/*
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString (the strlib.h interface) and monthToString
 * function.
 */
string Date::toString()
{
    if(day < 10)
        return "0" + integerToString(day) + "-" + monthToString(month).substr(0, 3) + "-" + integerToString(year);
    else
        return integerToString(day) + "-" + monthToString(month).substr(0, 3) + "-" + integerToString(year);
}


/*
 * Implementation notes: dateToDay
 * -------------------------------
 * dateToDay to make date converts the days begin UTC(1970.1.1)
 */
int Date::dateToDay()
{
    if(year < UTC)
        error("Make date.year >= UTC.");

    int yearToDays = 0, monthToDay = 0;
    for(int y = UTC; y < year; ++y)
    {
        if(isLeapYear(y))
            yearToDays += DAYS_IN_LEAP_YEAR;
        else
            yearToDays += DAYS_IN_LEAP_YEAR-1;
    }

    for(Month m = JANUARY; m < month; m++)
    {
        monthToDay += daysInMonth(m, year);
    }

    return yearToDays + monthToDay + day;
}

/*
 * Implementation notes: dayToDate
 * Usage: dayToDate(date, n);
 * -------------------------------
 * Convert the date expressed in days to the date format.
 */
void dayToDate(Date &date, int n, char ch)
{
    int sumOfDays = date.dateToDay();
    if(ch == '+')
        sumOfDays += n;
    else if(ch == '-')
        sumOfDays -= n;

    int dyear = UTC;
    while((isLeapYear(dyear) && sumOfDays > DAYS_IN_LEAP_YEAR) || (!isLeapYear(dyear) && sumOfDays > DAYS_IN_LEAP_YEAR-1))
    {
        if(isLeapYear(dyear)) sumOfDays -= DAYS_IN_LEAP_YEAR;
        else sumOfDays -= DAYS_IN_LEAP_YEAR - 1;

        dyear++;
    }

    Month dmonth = JANUARY;
    while(sumOfDays > daysInMonth(dmonth, dyear))
    {
        sumOfDays -= daysInMonth(dmonth, dyear);
        dmonth++;
    }

    date.year = dyear;
    date.month = dmonth;
    date.day = sumOfDays;
}

std::ostream & operator<< (std::ostream & os, Date date)
{
    return os << date.toString();
}

/*
 * Implementation notes: relational operators
 * ------------------------------------------
 * THe implementation of the operators.
 */
bool operator==(Date d1, Date d2)
{
    return ((d1.day == d2.day) && (d1.month == d2.month) && (d1.year == d2.year));
}

bool operator!=(Date d1, Date d2)
{
    return !(d1 == d2);
}

bool operator<(Date d1, Date d2)
{
    int sumOfDays1 = d1.dateToDay();
    int sumOfDays2 = d2.dateToDay();
    return sumOfDays1 < sumOfDays2;
    // if(d1.year != d2.year)
    //     return d1.year < d2.year;
    // else if(d1.month != d2.month)
    //     return d1.month < d2.month;
    // else if(d1.day != d2.day)
    //     return d1.day < d2.day;
    // return false;   // d1 == d2
}

bool operator<=(Date d1, Date d2)
{
    return ((d1 < d2) || (d1 == d2));
}

bool operator>(Date d1, Date d2)
{
    return !(d1 <= d2);
}

bool operator>=(Date d1, Date d2)
{
    return !(d1 < d2);
}

Date operator+(Date date, int n)
{
    Date dateCopy = date;
    // std::cout << date.dateToDay() << std::endl;
    dayToDate(dateCopy, n, '+');
    // std::cout << date.dateToDay() << std::endl;
    return dateCopy;
}


Date operator-(Date date, int n)
{
    Date dateCopy = date;
    dayToDate(dateCopy, n, '-');
    return dateCopy;
}

int operator-(Date d1, Date d2)
{
    int sumOfDays1 = d1.dateToDay();
    int sumOfDays2 = d2.dateToDay();
    return sumOfDays1 >= sumOfDays2 ? sumOfDays1 - sumOfDays2 : sumOfDays2 - sumOfDays1;
}

Date operator+=(Date &date, int n)
{
    date = date + n;
    return date;
}
Date operator-=(Date &date, int n)
{
    date = date - n;
    return date;
}

Date operator++(Date &date)
{
    date += 1;
    return date;
}
Date operator++(Date &date, int)
{
    Date old = date;
    date += 1;
    return old;
}
Date operator--(Date &date)
{
    date -= 1;
    return date;
}
Date operator--(Date &date, int)
{
    Date old = date;
    date -= 1;
    return old;
}
