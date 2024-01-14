/*
 * File: E-10.cpp
 * ---------------
 * generates the hailstone sequence from that point
 */
#include <iostream>
using namespace std;

const int SENTINEL = 1;

int x;
/* Main program */
int main(void)
{
    cout << "Enter a number: ";
    cin >> x;
    while(x != SENTINEL)
    {
        if(x % 2 == 0)
        {
            cout << x << " is even, so I divide it by 2 to get " << x / 2 << endl;
            x /= 2;
        }
        else 
        {
            cout << x << " is odd, so I multiply by 3 and add 1 to get " << x * 3 + 1 << endl;
            x = x * 3 + 1;
        }
    }
    return 0;
}
