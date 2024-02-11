
/*
 * E-6.cpp
 * -------
 * exports a Date class.
 */

#include <iostream>
#include <cmath>
#include <string>
#include "calendar.h"

int main(void)
{
    Date electionDay(6, NOVEMBER, 2012);
    Date inaugurationDay(21, JANUARY, 2013);
    if(electionDay < inaugurationDay)
        std::cout << "electionDay < inaugurationDay" << std::endl;
    std::cout << inaugurationDay - electionDay << std::endl;
    for(Date d = electionDay; d <= inaugurationDay; d++)
    {
        std::cout << d << std::endl;
    }
    // Date dragonYear(FEBRUARY, 10, 2024);
    // std::cout << dragonYear << std::endl;
    // std::cout << dragonYear + 2 << std::endl;
    // std::cout << dragonYear - 50 << std::endl;

    // Date dragonYear2(JANUARY, 30, 2024);
    // std::cout << dragonYear - dragonYear2 << std::endl;
    // std::cout << dragonYear << std::endl;
    // dragonYear += 2;
    // std::cout << dragonYear << std::endl;
    // dragonYear -= 50;
    // std::cout << dragonYear << std::endl;

    // dragonYear ++;
    // std::cout << dragonYear << std::endl;
    // ++ dragonYear;
    // std::cout << dragonYear << std::endl;
    // dragonYear --;
    // std::cout << dragonYear << std::endl;
    // -- dragonYear;
    // std::cout << dragonYear << std::endl;
    return 0;
}
