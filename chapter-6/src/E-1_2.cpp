
/*
 * File: dominos.cpp
 * -----------------
 * This file implements the dominos.cpp interface.
 */

#include <string>
#include "dominos.h"
#include "strlib.h"

using namespace std;

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variable leftDots and rightDots.
 * In the second form of the constructor, the parameter names are leftNumber, rightNumber
 * to avoid the problem of shadowing the instance variables.
 */

Dominos::Dominos()
{
    leftDots = 0;
    rightDots = 0;
}

Dominos::Dominos(int leftNumber, int rightNumber)
{
    leftDots = leftNumber;
    rightDots = rightNumber;
}

/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 * No setters are provided to ensure that Dominos objects are immutable.
 */

int Dominos::getLeftDots()
{
    return leftDots;
}

int Dominos::getRightDots()
{
    return rightDots;
}

/*
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */

string Dominos::toString()
{
    return integerToString(leftDots) + "-" + integerToString(rightDots);
}


ostream & operator<<(ostream &os, Dominos dots)
{
    return os << dots.toString();
}
