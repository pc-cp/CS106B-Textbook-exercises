/*
 * File: E-10.cpp
 * --------------
 * Write the files combinatorics.h and combinatorics.cpp
 * for a library that exports the functions permutations and combinations.
 */

#include <iostream>
#include <climits>
// #include "random.h"
#include "combinatorics.h"

using namespace std;

const int TEST_END = 10;

/* Main program */
int main(void)
{
    int n, k;
    cout << "? n: ";
    cin >> n;
    cout << "? k: ";
    cin >> k;

    cout << "permutations(int n, int k): " << permutations(n, k) << endl;
    return 0;
}
