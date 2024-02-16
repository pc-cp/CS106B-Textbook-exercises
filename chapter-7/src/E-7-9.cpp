/*
 * File: E-7-9.cpp
 * write a recursive implementation of the c(n, k)
 * function that uses no loops, no multiplication, and no calls to fact.
 */
#include <iostream>

using namespace std;

/* Function prototype */
int pascalTriangle(int n, int k);

int main(void)
{
    for(int n = 0; n <= 6; ++n)
    {
        for(int k = 0; k <= n; ++k)
        {
            cout << pascalTriangle(n, k) << ' ';
        }
        cout << endl;
    }
    return 0;
}
/*
 * Function: pascalTriangle
 * Usage: int result = pascalTriangle(n, k);
 * -----------------------------------------
 * Pascal's Triangle has the interesting  property that
 * every entry is the sum of the two entries above it,
 * except along the left and right edges, where the values
 * are always 1.
 */
int pascalTriangle(int n, int k)
{
    if(k == 0 || n == k) return 1;
    else
        return pascalTriangle(n-1, k-1) + pascalTriangle(n-1, k);
}
