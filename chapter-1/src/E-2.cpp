/*
 * File: E-2.cpp
 * -------------
 * converts a distance in meters 
 * to the corresponding English distance in feet and inches.
 */
#include <iostream>
using namespace std;

double meters;

/* Main program */
int main(void)
{
    cin >> meters;
    cout << "feet: " << 12 * meters << endl;
    cout << "inches: " << 0.0254 * meters << endl;
    return 0;
}
