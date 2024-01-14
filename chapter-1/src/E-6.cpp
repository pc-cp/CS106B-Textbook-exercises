/*
 * File: E-6.cpp
 * -------------
 * finds both the largest and the second-largest number in a list
 */

#include <iostream>
#include <climits>
using namespace std;

const int SENTINEL = 0;

int firstMax = INT_MIN;
int secondMax = INT_MIN;

/* Main program */
int main(void)
{
    cout << "This program finds the largest integer in a list" << endl;
    cout << "Enter 0 to signal the end of the list." << endl;
    bool input = false;
    int x;
    
    for(int i = 1; ; ++i)
    {
        cout << "? ";
        cin >> x;
        
        if(x == SENTINEL)
            break;
        
        input = true;
        
        if(i >= 2)
            secondMax = secondMax >= (firstMax >= x ? x : firstMax) ? secondMax : (firstMax >= x ? x : firstMax);
        
        firstMax = firstMax >= x ? firstMax : x;
    }
    
    if(!input)
        cout << "input Nothing" << endl;
    else
    {
        cout << "The largest value was " << firstMax << '.' << endl;
        cout << "The second largest value was " << secondMax << '.' << endl;
    }
    return 0;
}
