/*
 * File: E-7.cpp
 * -------------
 * reads in a list of integers representing exam scores and then prints out the average
 */

#include <iostream>
using namespace std;

const int SENTINEL = -1;

double average;

/* Main program */
int main(void)
{
    cout << "reads in a list of integers representing exam scores and then prints out the average" << endl;
    cout << "Enter -1 to signal the end of the list." << endl;
    bool input = false;
    int x;
    
    int times = 0;
    while(true)
    {
        cout << "? ";
        cin >> x;
        
        if(x == SENTINEL)
            break;
        
        input = true;
        
        average += x;
        times ++ ;
    }
    
    if(!input)
        cout << "input Nothing" << endl;
    else
    {
        cout << "The average value was " << average / times << '.' << endl;
    }
    return 0;
}
