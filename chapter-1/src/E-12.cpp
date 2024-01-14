/*
 * File: E-12.cpp
 * --------------
 * compute the area of the quarter circle by dividing it into 10,000 rectangles.
 */
#include <iostream>
#include <cmath>

using namespace std;

double r = 2, w = r/10000, h = 0;
double ans = 0;

/* Main program */
int main(void)
{
    double midpoint = w/2;
    for(int i = 1; i <= 10000; ++i)
    {
        h = sqrt(r*r-midpoint*midpoint);
        ans += h * w;
        midpoint += w;
    }
    cout << "the area of the quarter circle by dividing it into " << 10000 << " rectangles: " << ans << endl;
    return 0;
}
