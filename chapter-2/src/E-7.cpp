/*
 * File: E-7.cpp
 * Usage: double sqrt_num = generateSqrt(double num);
 *              ......
 * ----------------------------------------------
 * write your own implementation of the sqrt function.
 */

#include <iostream>
#include <climits>
#include "random.h"

using namespace std;

const int TEST_END = 10;
const double TEST_MAX = 100.0; // generateSqrt2 will have problems if this number is greater than 100.

/* Function prototype */
double generateSqrt(double num);
double generateSqrt2(double num);

/* Main program */
int main(void)
{
    double test;
    cin >> test;
    // for(int i = 1; i <= TEST_END; ++i)
    // {
        // double test = randomReal(0, TEST_MAX);
        cout << test << "\'s sqrt: " << generateSqrt(test) << endl;
        cout << test << "\'s sqrt: " << generateSqrt2(test) << endl;
    // }

    return 0;
}

double generateSqrt(double num)
{
    double g = num / 2;

    while(g - num/g >= 1e-4 || num/g - g >= 1e-4)
    {
        // cout << g << endl;
        g = (g + num/g) / 2;
    }
    return g;
}


double generateSqrt2(double num)
{
    double l = 0.0, r = TEST_MAX;
    while(r-l >= 1e-4)
    {
        double mid = (l + r) / 2;
        if(mid * mid >= num) r = mid;
        else l = mid;
    }
    return l;
}
