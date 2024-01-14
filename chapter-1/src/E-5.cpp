/*
 * File: E-5.cpp
 * -------------
 * display the largest value in the list
 */
#include <iostream>
#include <climits>
using namespace std;

const int SENTINEL = 0;
int mmax = INT_MIN;

/* Main program */
int main(void)
{
    cout << "This program finds the largest integer in a list" << endl;
    cout << "Enter 0 to signal the end of the list." << endl;
    bool input = false;
    int x;
    while(true)
    {
        cout << "? ";
        cin >> x;
        if(x == SENTINEL)
            break;
        mmax = mmax >= x ? mmax : x;
        input = true;
    }
    
    if(!input)
        cout << "input Nothing" << endl;
    else
        cout << "The largest value was " << mmax << '.' << endl;
    return 0;
}
