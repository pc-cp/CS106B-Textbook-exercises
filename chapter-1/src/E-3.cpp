/*
 * File: E-3.cpp
 * -------------
 * compute the sum of the numbers between 1 and 100
 */
#include <iostream>
using namespace std;

/* Main program */
int main(void)
{
    int sum = 0;
    for(int i = 1; i <= 100; ++i)
        sum += i;
    cout << "the sum of the numbers between 1 and 100: " << sum << endl;
    return 0;
}
