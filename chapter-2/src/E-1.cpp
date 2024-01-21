
/*
 * File: E-1.cpp
 * Usage: double f = celsiusConvertFahrenheit(c);
 * ----------------------------------------------
 * reads in a temperature in degrees Celsius and displays the corresponding temperature in degrees Fahrenheit.
 * use function to implement it.
 */

#include <iostream>

using namespace std;

/* Function prototype */
double celsiusConvertFahrenheit(double c);

/* Main program */
int main(void)
{
    double c;
    cin >> c;
    cout << "answer: " << celsiusConvertFahrenheit(c) << endl;
    return 0;
}

double celsiusConvertFahrenheit(double c)
{
    return 9/5.0 * c + 32;
}
