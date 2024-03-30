/*
 * File: E-12-4.cpp
 * Design and implement a class called IntArray
 */

#include <iostream>
#include <cassert>
#include "IntArray.h"

using namespace std;


int main() {
    IntArray arr(10);
    assert(arr.size() == 10);
    assert(arr.get(2) == 0);
    arr.put(1, 11);
    assert(arr.get(1) == 11);

    cout << "IntArray unit test succeeded" << endl;
    return 0;
}
