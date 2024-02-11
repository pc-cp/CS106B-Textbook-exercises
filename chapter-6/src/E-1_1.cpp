
/* File: dominos.h
 * ---------------
 * This interface exports a class for representing dominos.
 */

#ifndef _dominos_h
#define _dominos_h

#include <string>
#include <iostream>

class Dominos
{
public:
    /*
     * Constructor: Dominos
     * Usage: Dominos zero;
     *        Dominos dots(leftNumber, rightNumber);
     *-----------------------------------------
     * Creates a Domino object. The default constructor
     * creates the domino 0-0. The two-argument form
     * creates a domino number corresponding to the x-y.
     */
    Dominos();
    Dominos(int leftNumber, int rightNumber);

    /*
     * Method: toString();
     * Usage: string str = d.toString();
     * ---------------------------------
     * Returns the string representation of this domino number.
     */
    std::string toString();

    /*
     * Method: getLeftDots, getRightDots
     * Usage: int leftDots = getLeftDots();
     *        int rightDots = getRightDots();
     * --------------------------------------
     * These methods returns the leftDots and rightDots of the dominos.
     */
    int getLeftDots();
    int getRightDots();

    /* Instance variable */
private:
    int leftDots;
    int rightDots;
};


/*
 * Operator: <<
 * Usage: cout << dots
 * -------------------
 * Overloads the << operator so that it is able to display diminos values.
 */
std::ostream &operator<<(std::ostream &os, Dominos dots);

#endif _dominos_h
