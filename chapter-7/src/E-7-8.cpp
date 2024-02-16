
/*
 * File: E-7-8.cpp
 * ---------------
 * summing the digits repeatedly until only a single digit remains.
 */
#include <iostream>
#include <iomanip>

using namespace std;

/* Function prototype */
int digitSum(int n);
int digitalRoot(int n);

int main(void)
{
    while(true)
    {
        int n;
        cout << "input n (negative number to quit): ";
        cin >> n;
        if(n < 0) break;
        cout << digitalRoot(n) << endl;
    }
    return 0;
}

/*
 * Function: digitSum
 * Usage: int result = digitSum(n);
 * --------------------------------
 * It is easy to break an integer down into two components using
 * division by 10.
 */
int digitSum(int n)
{
    if(n < 10)
        return n;
    else
        return n%10 + digitSum(n/10);
}

/*
 * Function: digitalRoot
 * Usage: int result = digitalRoot(n);
 * -----------------------------------
 * The digital root of an integer n is defined as the result
 * of summing the digits repeatedly until only a single digit remains.
 * For example, the digital root of 1729 can be
 * calculated using the following steps:
 *      Step 1: 1 + 7 + 2 + 9   -> 19
 *      Step 2: 1 + 9           -> 10
 *      Step 3: 1 + 0           -> 1
 */
int digitalRoot(int n)
{
    int digitS = digitSum(n);
    if(digitS < 10)
        return digitS;
    else
        return digitalRoot(digitS);
}
