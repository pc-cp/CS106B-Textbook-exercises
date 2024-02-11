
/*
 * E-5.cpp
 * -------
 * exports a Date class.
 */

#include <iostream>
#include <string>
#include "calendar.h"

int main(void)
{
    Date moonLanding(JULY, 20, 1969);
    std::cout << moonLanding.toString() << std::endl;
    Date defau;
    std::cout << defau.toString() << std::endl;
    return 0;
}
