
/*
 * File: E-7-7.cpp
 * ---------------
 * Write a recursive function digitSum(n)
 * that takes a nonnegative integer and returns the sum of its digits.
 */
#include <iostream>
#include <iomanip>

using namespace std;

/* Function prototype */
int digitSum(int n);

int main(void)
{
    while(true)
    {
        int n;
        cout << "input n (negative number to quit): ";
        cin >> n;
        if(n < 0) break;
        cout << digitSum(n) << endl;
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
