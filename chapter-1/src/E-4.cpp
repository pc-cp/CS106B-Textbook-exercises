/*
 * File: E-4.cpp
 * -------------
 * compute the sum of the first N odd integers.
 */
#include <iostream>
using namespace std;

int n;

/* Main Program */
int main(void)
{
    cin >> n;
    int sum = 0, odd = 1;
    while(n--)
    {
        sum += odd;
        odd += 2;
    }
    cout << "the sum of the first "<< n << " odd integers: " << sum << endl;
    return 0;
}
