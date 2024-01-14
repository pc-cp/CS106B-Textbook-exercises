/*
 * File: E-8.cpp
 * -------------
 * displays the number that has the same digits in the reverse order
 */

#include <iostream>
using namespace std;

/* Function prototypes */
int digitReverse(int n);

/* Main program */
int main(void)
{
    int x;
    cout << "This program reverses the digits in an integer." << endl
         << "Enter a positive integer: ";
    cin >> x;
    
    cout << "The reversed integer is " << digitReverse(x) << endl;
    return 0;
}

int digitReverse(int n)
{
    int ans = 0;
    while(n > 0)
    {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}
