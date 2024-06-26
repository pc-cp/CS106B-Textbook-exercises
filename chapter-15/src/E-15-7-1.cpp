
/*
 * File: rational.cpp
 * ------------------
 * This file implements the Rational class.
 */

#include <iostream>
#include <cstdlib>
#include "error.h"
#include "rational.h"
#include "strlib.h"
using namespace std;

/* Function prototype */
int gcd(int x, int y);

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Rational class. The default
 * constructor creates a Rational with a zero value, the one-argument
 * form converts an integer to a Rational, and the two-argument form
 * allows you to specify a fraction. The constructors ensure that
 * the following invariants are maintained:
 *
 * 1. The fraction is always reduced to lowest terms.
 * 2. The denominator is always positive.
 * 3. Zero is always represented as 0/1.
 */

Rational::Rational()
{
    num = 0;
    den = 1;
}

Rational::Rational(int n)
{
    num = n;
    den = 1;
}

Rational::Rational(int x, int y)
{
    if(y == 0) error("Rational: Division by zero");
    if(x == 0)
    {
        num = 0;
        den = 1;
    }
    else
    {
        int g = gcd(abs(x), abs(y));
        num = x / g;
        den = abs(y) / g;
        if(y < 0) num = -num;
    }
}

/* Implementation of toString and the << operator */
string Rational::toString() const
{
    if(den == 1)
        return integerToString(num);
    else
        return integerToString(num) + "/" + integerToString(den);
}

ostream & operator<<(ostream & os, Rational rat)
{
    return os<< rat.toString();
}

/*
 * Implementation notes: arithmetic operators
 * ------------------------------------------
 * The implementation of the operators follows directly from the definitions.
 */
Rational operator+(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den, r1.den * r2.num);
}

bool operator==(Rational r1, Rational r2)
{
    return (r1.num == r2.num) && (r1.den == r2.den);
}
bool operator!=(Rational r1, Rational r2)
{
    return !(r1 == r2);
}
bool operator<(Rational r1, Rational r2)
{
    int lcm = r1.den * r2.den / (gcd(r1.den, r2.den));
    int timesR1 = lcm / r1.den, timesR2 = lcm/r2.den;

    return r1.num * timesR1 < r2.num * timesR2;
}
bool operator<=(Rational r1, Rational r2)
{
    return (r1 < r2) || (r1 == r2);
}
bool operator>(Rational r1, Rational r2)
{
    return !(r1 <= r2);
}
bool operator>=(Rational r1, Rational r2)
{
    return !(r1 < r2);
}


void operator+=(Rational & r1, Rational r2)
{
    r1 = r1 + r2;
}
void operator-=(Rational & r1, Rational r2)
{
    r1 = r1 - r2;
}
void operator*=(Rational & r1, Rational r2)
{
    r1 = r1 * r2;
}
void operator/=(Rational & r1, Rational r2)
{
    r1 = r1 / r2;
}

Rational operator++(Rational &r1)
{
    Rational one(1, 1);
    r1 += one;
    return r1;
}
Rational operator++(Rational &r1, int)
{
    Rational old = r1;

    Rational one(1, 1);
    r1 += one;

    return old;
}
Rational operator--(Rational &r1)
{
    Rational one(1, 1);
    r1 -= one;
    return r1;
}

Rational operator--(Rational &r1, int)
{
    Rational old = r1;

    Rational one(1, 1);
    r1 -= one;

    return old;
}


/*
 * Implementation notes: gcd
 * -------------------------
 * This implementation uses Euclid's algorithm to calculate the
 * greatest common divisor.
 */

int gcd(int x, int y)
{
    if(y == 0)
        return x;
    return gcd(y, x%y);
}
