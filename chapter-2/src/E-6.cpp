/*
 * File: E-6.cpp
 * Usage: if(isPrime(n))
 *              ......
 * ----------------------------------------------
 * returns true if the integer n is prime, and false otherwise.
 */

#include <iostream>

using namespace std;

const int TEST_END = 100;

/* Function prototype */
bool isPrime(int n);

/* Main program */
int main(void)
{
    for(int i = 1; i <= TEST_END; ++i)
        if(isPrime(i))
            cout << i << " is prime." << endl;

    return 0;
}

bool isPrime(int n)
{
    if(n == 1) return false;

    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
