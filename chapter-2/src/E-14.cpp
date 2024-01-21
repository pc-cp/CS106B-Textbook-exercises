/* File: E-14.cpp
 * --------------
 * Write a program that simulates throwing 10,000 darts
 * and then uses the simulation technique described in
 * this exercise to generate and display an approximate value of pi.
 */

#include <iostream>
#include "random.h"

using namespace std;

const int DARTS_NUMBERS = 10000;

/* Prototype function */
void generateCartesianCoordinate(double &x, double &y);

/* Main function*/
int main(void)
{
    int dartsInCircle = 0, dartsInSquare = 0;

    for(int i = 1; i <= DARTS_NUMBERS; ++i)
    {
        double x, y;
        generateCartesianCoordinate(x, y);
        if(x*x + y*y < 1)   dartsInCircle++;
        dartsInSquare++;
    }
    cout << 4.0 * dartsInCircle / dartsInSquare << endl;
    return 0;
}

void generateCartesianCoordinate(double &x, double &y)
{
    x = randomReal(-1, 1);
    y = randomReal(-1, 1);
}
