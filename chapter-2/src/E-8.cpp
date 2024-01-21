/*
 * File: E-8.cpp
 * Usage: double sqrt_num = generateSqrt(double num);
 *              ......
 * ----------------------------------------------
 * write your own implementation of the sqrt function.
 * The result of this calculation of the date is wrong, but the aim is to realize the process itself
 */

#include <iostream>
#include <climits>
#include "random.h"

using namespace std;

enum Month {January = 1, February, March, April, May, June, July, August, September, October, November, December};

const int TEST_END = 10;
const double TEST_MAX = 100.0; // generateSqrt2 will have problems if this number is in [0, 1)

/* Function prototype */
void findEaster(int year, string & month, int & day);
string monthToString(MONTH month);
void error(string msg);

/* Main program */
int main(void)
{
    string month;
    int day;

    // for(int i = 1; i <= TEST_END; ++i)
    // {
        // int year = randomInteger(1700, 1899);
        int year = 2019;
        findEaster(year, month, day);
        cout << year << ", " << month << ", " << day << endl;
    // }

    return 0;
}

void findEaster(int year, string & month, int & day)
{
    int a = year % 19, b = year % 4, c = year % 7;
    int k = year / 100;
    int p = k / 3, q = (k+8) / 25;
    int m = (15 - q + k - p) % 30;
    int n = (4 + k - p) % 7;

    int d = (19 * a + m) % 30;
    int e = (2 * b + 4 * c + 6 * d + n) % 7;
    // cout << a <<' ' <<  b <<' ' << c <<' ' << k <<' ' << p <<' ' << q << ' ' << m <<' ' << n <<' ' << d <<' ' << e << endl;
    if(d == 29 && e == 6)
    {
        month = monthToString((Month)4);
        day = 18;
    }
    else if(d + e < 10)
    {
        month = monthToString((Month)3);
        day = 22 + d + e;
    }
    else
    {
        month = monthToString((Month)4);
        day = d + e - 9;
        if(day == 26)
            day = 19;
    }
}

string monthToString(Month month)
{
    switch(month)
    {
        case January: return "January";
        case February: return "February";
        case March: return "March";
        case April: return "April";
        case May: return "May";
        case June: return "June";
        case July: return "July";
        case August: return "August";
        case September: return "September";
        case October: return "October";
        case November: return "November";
        case December: return "December";
        default: error("Not exist this month. ");
    }
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
