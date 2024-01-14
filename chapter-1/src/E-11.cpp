/*
 * File: E-11.cpp
 * --------------
 * calculates an approximation of ! consisting of the first 10,000 terms in Leibniz’s series
 */
#include <iostream>
using namespace std;

int times;
double ans;

/* Main program */
int main(void)
{
    cout << "Enter a number: ";
    cin >> times;
    
    int terms = 1;
    for(int i = 1; i <= times; ++i)
    {
        if(i % 2 == 0) 
            ans += -1.0/terms;
        else
            ans += 1.0/terms;
        
        terms += 2;
    }
    cout << "the first " << times << " terms in Leibniz’s series: " << ans << endl;
    return 0;
}
