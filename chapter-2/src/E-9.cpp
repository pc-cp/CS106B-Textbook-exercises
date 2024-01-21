/*
 * File: E-9.cpp
 * Usage: int permu = permutations(int n, int k);
 *              ......
 * ----------------------------------------------
 * computes the number of permutations.
 */

#include <iostream>
#include <climits>
#include "random.h"

using namespace std;

const int TEST_END = 10;

/* Function prototype */
int permutations(int n, int k);
void error(string msg);

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

int permutations(int n, int k)
{
    long long ans = 1;
    for(int i = n; i >= n-k+1; i--)
        ans *= i;
    if(ans > INT_MAX)
        error("Overflow.");
    return int(ans);
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
