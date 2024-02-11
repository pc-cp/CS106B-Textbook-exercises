
/*
 * E-8.cpp
 * -------
 * Expanding the rational.h file
 */

#include <iostream>
#include <cmath>
#include <string>
#include "rational.h"
using namespace std;

int main(void)
{
    Rational r1(2, 6);
    Rational r2(1, 5);
    cout << r1 + r2 << endl;
    r1 ++ ;
    cout << r1 << endl;
    r1 --; r1 --;
    cout << r1 << endl;
    r1 += r2;
    cout << r1 << endl;
    if(r1 < r2)
        cout << "r1 < r2" << endl;

    Rational r3(-1, 3);
    Rational r4(-1, 2);
    if(r3 > r4)
        cout << "r3 > r4" << endl;

    return 0;
}

