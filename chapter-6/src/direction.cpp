
/*
 * File: direction.cpp
 * --------------------
 * This file implements the direction.h interface.
 */
#include <string>
#include <iostream>
#include "direction.h"
using namespace std;

/*
 * Implementation notes: leftFrom, rightFrom
 * ------------------------------------------
 * These functions use the remainder operator to cycle through the
 * internal values of the enumeration type. Note that the leftFrom
 * function cannot substract 1 from the direction bacause the result
 * might then be negative; adding 3 achieves the same effect but
 * ensures that the values remain positive.
 */
Direction leftFrom(Direction dir)
{
    return Direction((dir + 3) % 4);
}

Direction rightFrom(Direction dir)
{
    return Direction((dir + 1) % 4);
}

/*
 * Implementation notes: directionToString
 * ---------------------------------------
 * Most C++ compilers require the default clause to make sure that this
 * function always return a string, even if the direction is not one
 * of the legal values;
 */

string directionToString(Direction dir)
{
    switch(dir)
    {
    case NORTH: return "NORTH";
    case EAST: return "EAST";
    case SOUTH: return "SOUTH";
    case WEST: return "WEST";
    default: return "???";
    }
}

ostream & operator<<(ostream &os, Direction dir)
{
    return os << directionToString(dir);
}

/*
 * prefix ++
 */
Direction operator ++(Direction &dir)
{
    dir = Direction(dir + 1);
    return dir;
}


/*
 * suffix ++
 */

Direction operator++(Direction &dir, int)
{
    Direction old = dir;
    dir = Direction(dir + 1);
    return old;
}

