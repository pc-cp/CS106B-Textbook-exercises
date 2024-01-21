
/* File: combinatorics.cpp
 * ------------------------
 * This file implements the combinatorics.h interface.
 */
#include <iostream> // cerr
#include <string>   // string
#include <climits>  // INT_MAX
#include "combinatorics.h"
using namespace std;

/* Private function */
int fact(int n);
void error(string msg);

/*
 * Implementation notes: combinations
 * ----------------------------------
 * Returns the mathematical combinations function C(n, k).
 */

int combinations(int n, int k)
{
    return fact(n) / (fact(k) * fact(n-k));
}

/*
 * Implemention notes: permutations
 * --------------------------------
 * Returns the mathematical combinations function P(n, k).
 */

int permutations(int n, int k)
{
    long long ans = 1;
    for(int i = n; i >= n-k+1; i--)
        ans *= i;
    if(ans > INT_MAX)
        error("Overflow.");
    return int(ans);
}

/*
 * Implementation notes: fact
 * --------------------------
 * Returns the factorial of n, which is the product of all the
 * integers between 1 and n, inclusive.
 */
int fact(int n)
{
    int result = 1;
    for(int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

/*
 * Implementation notes: error
 * ---------------------------
 * This function writes out the error message to the cerr stream and
 * then exits the program. The EXIT_FAILURE constant is defined in
 * <cstdlib> to represent a standard failure code.
 */

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
