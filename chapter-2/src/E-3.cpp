/*
 * File: E-3.cpp
 * Usage: double nearestInteger = roundToNearestInt(x);
 * ----------------------------------------------
 * rounds the floating-point number x to the nearest integer.
 */

#include <iostream>
#include "random.h"

using namespace std;

/* Function prototype */
int roundToNearestInt(double x);

/* Main program */
int main(void)
{
    for(int i = 0; i < 10; ++i)
    {
        double real = randomReal(-100, 100);
        cout << "floating-point: " << real << " , NearestInt: " << roundToNearestInt(real) << endl;
    }
    return 0;
}

int roundToNearestInt(double x)
{
    if(x > 0)
        return x + 0.5;
    else
        return x - 0.5;
}
