
/*
 * File: E-7-5.cpp
 * ---------------
 * Write an iterative implementation of the function fib(n).
 */
#include <iostream>
#include <iomanip>

using namespace std;

/* Function prototype */
int fib(int n);

int main(void)
{
    while(true)
    {
        int n;
        cout << "n (-1 to quit): ";
        cin >> n;
        if(n < 0) break;
        cout << fib(n) << endl;
    }
    return 0;
}

/*
 * Function: fib
 * -------------
 * Usage: int result = fib(n);
 * Write an iterative implementation of the function fib(n).
 */

int fib(int n)
{
    int result = 1;
    for(int i = 1; i <= n; ++i)
        result *= i;
    return result;
}
