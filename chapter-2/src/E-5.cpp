/*
 * File: E-5.cpp
 * Usage: if(isPerfect(n))
 *              ......
 * ----------------------------------------------
 * takes an integer n and returns true if n is perfect, and false otherwise.
 */

#include <iostream>

using namespace std;

const int TEST_END = 9999;

/* Function prototype */
bool isPerfect(int n);

/* Main program */
int main(void)
{
    for(int i = 1; i <= TEST_END; ++i)
        if(isPerfect(i))
            cout << i << " is perfect." << endl;

    return 0;
}

bool isPerfect(int n)
{
    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        if(n % i == 0)
            ans += i;
    }
    return n == ans;
}
