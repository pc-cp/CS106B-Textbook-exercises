/*
 * File: E-11.cpp
 * -----------------------------------------------------------------------
 * design and implement a calendar.h interface
 */

#include <iostream>
// #include "random.h"
#include "calendar.h"

using namespace std;

const int MONTHS = 12;

/* Main program */
int main(void)
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    for(int month = 1; month <= MONTHS; ++month)
    {
        cout << monthToString(Month(month)) << " has " << daysInMonth(Month(month), year) << " days." << endl;
    }
    return 0;
}
