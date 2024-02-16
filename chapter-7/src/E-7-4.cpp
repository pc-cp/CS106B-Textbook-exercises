/*
 * File: E-7-4.cpp
 * ---------------
 * Use Euclid’s insight to write a recursive function
 * gcd(x, y) that computes the greatest common divisor of x and y.
 */
#include <iostream>
#include <iomanip>
// #include "error.h"
// #include "vector.h"
using namespace std;

/* Function prototype */
int gcd(int x, int y);

int main(void)
{
    while(true)
    {
        int x, y;
        cout << "x (0 to quit): ";
        cin >> x;
        cout << "y (0 to quit): ";
        cin >> y;
        if(x == 0 || y == 0) break;
        cout << gcd(x, y) << endl;
    }
    return 0;
}

/*
 * Function: gcd
 * Usage: int result = gcd(x, y);
 * ------------------------------
 * Use Euclid's insight to write a recursive function gcd(x, y) that computes the
 * greatest common divisor of x and y.
 *  the gcd of x and y can always be computed as follows:
 *      - If x is evenly divisible by y, then y is the greatest common divisor.
 *      - Otherwise, the gcd of x and y is always equal to the gcd of y and the remainder of x
 *      divided by y.
 */

int gcd(int x, int y)
{
    if(x == 0 || y == 0)
    {
        return -1;
    }

    if(x%y == 0) return y;
    else return gcd(y, x%y);
}
