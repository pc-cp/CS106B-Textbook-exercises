
/*
 * E-14-3.cpp
 */
#include <iostream>
#include <cassert>
#include "pair.h"

using namespace std;

int main() {
    Pair<int, double> p1;
    assert(p1.first() == 0);

    Pair<int, char> p2(10, 'A');
    assert(p2.first() == 10);
    assert(p2.second() == 'A');
    return 0;
}
