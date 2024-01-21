/*
 * File: E-2.cpp
 * Usage: metersToFeetAndInches(double meters, double &inches, double &feet);
 * ----------------------------------------------
 * converts a distance in meters to the corresponding English distance in feet and inches.
 */

#include <iostream>

using namespace std;

/* Function prototype */
void metersToFeetAndInches(double meters, double &inches, double &feet);

/* Main program */
int main(void)
{
    double meters, inches, feet;
    cin >> meters;

    metersToFeetAndInches(meters, inches, feet);

    cout << "inch(es): " << inches << endl << "feet: " << feet << endl;
    return 0;
}

void metersToFeetAndInches(double meters, double &inches, double &feet)
{
    inches = meters / 0.0254;
    feet = inches / 12;
}
