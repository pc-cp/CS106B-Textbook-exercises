
#ifndef _label_generator_h
#define _label_generator_h

/*
 * File: labelGenerator.h
 * ----------------------
 * This interface export LabelGenerator class, which is a
 * label generator that allows the client to define arbitrary
 * sequences of labels, each of which consists of a prefix string
 * ("Figure" or "P" ) coupled with an integer used as a sequence number.
*/

#include <iostream>
#include <string>

class LabelGenerator
{
public:
    /*
     * Constructor: LabelGenerator
     * Usage: LabelGenerator variable;
     *        LabelGenerator pointNumbers(str, n);
     * -------------------------------------------
     * Creates a LabelGenerator object. The default constructor sets the variable's
     * prefix string to "", and integer to 0; the second form sets the variable's
     * prefix string to str, and integer to n;
     */
    LabelGenerator();
    LabelGenerator(std::string prefix, int n);

    /*
     * Methods: getPrefixString, getInteger
     * Usage: string prefix = getPrefixString();
     *        int n = getInteger();
     * -----------------------------------------
     * Returns class's value.
     */
    std::string getPrefixString();

    int getInteger();
    /*
     * Method: toString
     * Usage: string str = variable.toString();
     * ----------------------------------------
     * Returns a string representation of the LabelGenerator in the form prefixString number.
     */
    std::string toString();

    /*
     * Method: nextLabel
     * Usage: cout << figureNumbers.nextLabel();
     * -----------------------------------------
     * Returns a new label in the sequence by calling nextLabel on the LabelGenerator.
     */
    LabelGenerator nextLabel();


    /* Declare the operator function as friends */
    // XXX
    /* private section */
private:
    std::string prefixString;
    int number;

};


/*
 * Operator: <<
 * Usage: cout << variable;
 * ------------------------
 * Overloads the << operator so that it is able to display LabelGenerator values.
 */
std::ostream & operator<< (std::ostream &os, LabelGenerator label);
#endif
