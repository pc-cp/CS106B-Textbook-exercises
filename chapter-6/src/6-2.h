
/* File: calendar.h
 * ----------------
 * Write the files calendar.h and calendar.cpp to
 * asks the user to enter a year and then writes out
 * the number of days in each month of that year.
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>


/*
 * Constant
 */
extern const int UTC;
extern const int daysInLeapYear;

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
 * Function: operator++
 * Usage: ++month
 * --------------
 * overload prefix form.
 */

Month operator++(Month &month);

/*
 * Function: operator++
 * Usage: month++
 * --------------
 * overload suffix form.
 */

Month operator++(Month &month, int);

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

    /*
     * Method: dateToDay
     * Usage: int days = date.dateToDay();
     * -----------------------------------
     * Returns the number of days from UTC (1970.7.1) to date.
     */
    int dateToDay();


    /* Declare the operator functions as friends */
    friend bool operator==(Date d1, Date d2);
    friend bool operator!=(Date d1, Date d2);
    friend bool operator<(Date d1, Date d2);
    friend bool operator<=(Date d1, Date d2);
    friend bool operator>(Date d1, Date d2);
    friend bool operator>=(Date d1, Date d2);

    friend Date operator+(Date date, int n);
    friend Date operator-(Date date, int n);
    friend void dayToDate(Date &date, int n, char ch);

    friend int operator-(Date d1, Date d2);

    friend Date operator+=(Date &date, int n);
    friend Date operator-=(Date &date, int n);
    friend Date operator++(Date &date);
    friend Date operator++(Date &date, int);
    friend Date operator--(Date &date);
    friend Date operator--(Date &date, int);
    /* Private section */
private:
    /* Instance variables */
    int day;
    Month month;
    int year;

    /* Private function */
    // int dateToDay(Date date);
};

/*
 * Operator: <<
 * ------------
 * Overloads the << operator so that it is able to display Date values.
 */

std::ostream & operator<< (std::ostream & os, Date date);

/*
 * Operator: ==, !=, <, <=, >, >=
 * ------------------------------
 * Overloads the relational operators ==, !=, <, <=, >, >=.
 */

bool operator==(Date d1, Date d2);

bool operator!=(Date d1, Date d2);

bool operator<(Date d1, Date d2);

bool operator<=(Date d1, Date d2);

bool operator>(Date d1, Date d2);

bool operator>=(Date d1, Date d2);

/*
 * Operator: +
 * -----------
 * Overloads the + operator, which returns the date n days after date.
 */

Date operator+(Date date, int n);

/*
 * Operator: -
 * -----------
 * Overloads the - operator, which returns the date n days before date.
 */

Date operator-(Date date, int n);

/*
 * Operator: -
 * -----------
 * Overloads the - operator, which returns how many days separate d1 and d2.
 */
int operator-(Date d1, Date d2);

/*
 * Function: dayToDate
 * -----------------
 * Convert days to date format
 */

void dayToDate(Date &date, int n, char ch);

/*
 * Operator: +=, -=
 * ----------------
 * The shorthand assignment operators += and -= with an integer on the right
 */
Date operator+=(Date &date, int n);
Date operator-=(Date &date, int n);


/*
 * Operator: ++, --
 * ----------------
 * The ++ and -- operators in both their prefix and suffix form.
 */

Date operator++(Date &date);
Date operator++(Date &date, int);
Date operator--(Date &date);
Date operator--(Date &date, int);
#endif // _calendar_h
