/*
 * chapter-6
 * File: E-3.cpp
 * reference: https://github.com/heavy3/programming-abstractions/blob/master/06-class-design/readerEx.06.03/main.cpp
 */

#include "GRectangle.h"

const std::string HEADER = "CS106B Programming Abstractions in C++: Ex 6.3";
const std::string DETAIL = "Implement a simple GRectangle Class from gtypes.h";

int main(void)
{
    std::cout << HEADER << std::endl;
    std::cout << DETAIL << std::endl << std::endl;

    double x = 10.0;
    double y = 15.0;
    double width = 500;
    double height = 300;

    std::cout << GRectangle(x, y, width, height) << std::endl;
    return 0;
}
