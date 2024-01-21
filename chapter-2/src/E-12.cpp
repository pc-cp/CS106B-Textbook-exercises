/*
 * File: E-12.cpp
 * --------------
 * displays the average after a specified number of trials entered by the user.
 */

#include <iostream>
#include "random.h"
using namespace std;

/* Main function */

int main(void)
{
    int trials;
    cout << "number of trials: ";
    cin >> trials;
    double ans = 0;
    for(int i = 0; i < trials; ++i)
    {
        double number = randomReal(0, 1);
        cout << "random real number: " << number << endl;
        ans += number;
    }
    cout << "randomAverage: " << ans / trials << endl;
    return 0;
}
