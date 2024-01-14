/*
 * File: E-1.cpp
 * -------------
 * reads in a temperature in degrees Celsius 
 * and displays the corresponding temperature 
 * in degrees Fahrenheit.
 */
#include <iostream>
using namespace std;

double c;

/* Main program */
int main(void)
{
    cin >> c;
    cout << 9.0/5 * c + 32 << endl;
    return 0;
}
