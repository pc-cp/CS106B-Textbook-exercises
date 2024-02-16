/*
 * File: E-7-2.cpp
 * ---------------
 * write a recursive implementation of a function that calculates n^k.
 *      int raiseToPower(int n, int k);
 */
#include <iostream>
using namespace std;
/* Function prototype */
int raiseToPower(int n, int k);

int main(void)
{
    while(true)
    {
        int n, k;
        cout << "input the n (0 to quit): ";
        cin >> n;
        if(n == 0) break;
        cout << "input the k: ";
        cin >> k;
        cout << raiseToPower(n, k) << endl;
    }
    return 0;
}

/*
 * Function: raiseToPower
 * Usage: int result = raiseToPower(n, k);
 * ---------------------------------------
 * Write a recursive implementation of a function
 * int raiseToPower(int n, int k) that calculates n^k,
 * solve this problem is the mathematical property that:
 *      raiseToPower(n, 0) = 1
 *      raiseToPower(n, k) = n * raiseToPower(n, k-1)
 */

int raiseToPower(int n, int k)
{
    if(k == 0) return 1;
    else
        return n * raiseToPower(n, k-1);
}
