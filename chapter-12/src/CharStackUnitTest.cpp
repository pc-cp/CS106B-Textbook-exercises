
/*
 * File: CharStackUnitTest.cpp
 * ---------------------------
 * This file contains a unit test of the CharStack class that uses the C++ assert macro
 * to test that each operation performs as it should.
 */

#include <iostream>
#include <cassert>
#include "charstack.h"

using namespace std;

int main() {
    CharStack cstk;                 // Declare an empty CharStack
    assert(cstk.size() == 0);       // Make sure its size is 0
    assert(cstk.isEmpty());         // And that isEmpty is true
    cstk.push('A');                 // Push the character 'A'
    assert(!cstk.isEmpty());        // The stack is now not empty
    
    cout << "CharStack unit test succeeded." << endl;

    return 0;

}
