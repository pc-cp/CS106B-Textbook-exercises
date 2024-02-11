
/*
 * File: labelGenerator.cpp
 * ------------------------
 * This file implements the labelGenerator.cpp interface.
 */

#include <string>
#include "labelGenerator.h"
#include "strlib.h"

/*
 * Implementation notes: Constructors
 * ----------------------------------
 * ...
 */

LabelGenerator::LabelGenerator()
{
    prefixString = "";
    number = 1;
}

LabelGenerator::LabelGenerator(std::string prefix, int n)
{
    prefixString = prefix;
    number = n;
}

/*
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 */

std::string LabelGenerator::getPrefixString()
{
    return prefixString;
}

int LabelGenerator::getInteger()
{
    return number;
}

std::string LabelGenerator::toString()
{
    return prefixString + integerToString(number);
}

std::ostream & operator<< (std::ostream &os, LabelGenerator label)
{
    return os << label.toString();
}


LabelGenerator LabelGenerator::nextLabel()
{
    LabelGenerator temp(prefixString, number);
    number++;
    return temp;
}
