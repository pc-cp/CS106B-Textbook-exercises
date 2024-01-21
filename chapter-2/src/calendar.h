
/* File: calendar.h
 * ----------------
 * Write the files calendar.h and calendar.cpp to
 * asks the user to enter a year and then writes out
 * the number of days in each month of that year.
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>

/* Type: Month
 * -----------
 * This enumerated type is used to represent the 12 months.
 */
enum Month {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

/*
 * Function: daysInMonth
 * Usage int days = int daysInMonth(month, year);
 * ----------------------------------------------
 * returns the number of days for a given month and year
 */
int daysInMonth(Month month, int year);

/*
 * Function: isLeapYear
 * Usage: if(isLeapYear(year))
 *          ...
 * ---------------------------
 * tests whether year is a leap year
 *
 */
bool isLeapYear(int year);

/*
 * Function: monthToString
 * Usage: string month = monthToString(month);
 * -------------------------------------------
 * converts a Month value to a string.
 */
std::string monthToString(Month month);

#endif // _calendar_h
