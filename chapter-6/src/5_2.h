

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


/*
 * Class: Date
 */

class Date
{
public:
    /*
     * Construcor: Date
     * Usage:   Date date
     *          Date date(JULY, 20, 1969);
     *          Date date(20, JULY, 1969);
     * -----------------------------------
     * Creates a Date object. The default construcor sets the date to
     * January 1, 1900; the second form sets the date to JULY 20, 1969;
     * the third form is an overloadad version of the second form.
     */

    Date();
    Date(Month cmonth, int cday, int cyear);
    Date(int cday, Month cmonth, int cyear);

    /*
     * Getters: getDay, getMonth, getYear
     * Usage: int day = getDay();
     *        Month month = getMonth();
     *        int year = getYear();
     * ----------------------------------
     * These getters return the day, month, and year of the date.
     */

    int getDay();
    Month getMonth();
    int getYear();

    /*
     * Method: toString
     * Usage: string str = date.toString();
     * ------------------------------------
     * Returns the date in the form dd-mmm-yyyy.
     */
    std::string toString();
    /* Instance variables */
private:
    int day;
    Month month;
    int year;
};

#endif // _calendar_h
