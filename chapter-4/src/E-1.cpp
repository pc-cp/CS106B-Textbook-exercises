
/*
 * File: E-1.cpp
 * -------------
 * displays a table of trigonometric sines and cosines
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979323846;

/* Function prototypes */
void printTrigTable();

/* main function */
int main(void)
{
    printTrigTable();
    return 0;
}

/*
 * Function: printTrigTable
 * ------------------------
 * Generate a series of sin and cos values corresponding to the angles
 * Because the parameters received by the cos and sin functions in <cmath> are Value representing an angle expressed in radians.
 * So for an angle theta, it needs to be converted to radians radians: 180/PI * theta before calling the relevant formula.
 */
void printTrigTable()
{
    cout << " theta  |       sin(theta)      |       cos(theta)      |" << endl;
    cout << "--------+-----------------------+-----------------------+" << endl;
    for(int theta = -90; theta <= 90; theta += 15)
    {
        cout << right << setw(5) << setprecision(3) << theta << "   |";
        cout << fixed << setw(17) << setprecision(7) << sin(theta * PI / 180.0) << "      |";
        cout << fixed << setw(17) << setprecision(7) << cos(theta * PI / 180.0) << "      |" << endl;;
    }
}
