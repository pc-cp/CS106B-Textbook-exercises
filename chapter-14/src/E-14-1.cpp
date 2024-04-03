
/*
 * E-14-1.cpp
 * Write and test your own implementation of the swap function.
 */
#include <iostream>
#include <cassert>
using namespace std;

template <typename ValueType>
void sswap(ValueType &a, ValueType &b) {
    ValueType tmp = a;
    a = b;
    b = tmp;
}

int main() {

    int a = 1, b = 2;
    assert(a == 1);

    sswap(a, b);
    assert(a == 2);

    char ca = 'A', cb = 'B';
    assert(ca == 'A');
    sswap(ca, cb);
    assert(ca == 'B');
    return 0;
}
