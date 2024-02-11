

/* File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "calendar.h"
#include "strlib.h"
#include "error.h"

using namespace std;

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
