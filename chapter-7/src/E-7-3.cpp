
/*
 * File: E-7-3.cpp
 * ---------------
 * write a recursive implementation of a function that calculates n^k.
 *      int raiseToPower(int n, int k);
 */
#include <iostream>
#include <iomanip>
using namespace std;

/* Function prototype */
int getTitiusBodeDistance(int k);

int main(void)
{
    for(int i = 1; i <= 8; ++i)
    {
        int distance = getTitiusBodeDistance(i);
        cout << right << fixed << setw(4) << setprecision(1) <<  (4.0 + distance) / 10 << " AU" << endl;
    }
    return 0;
}

/*
 * Function: getTitiusBodeDistance
 * Usage: int distance = getTitiusBodeDistance(k);
 * -----------------------------------------------
 * Write a recursive function getTitiusBodeDistance(k)
 * that calculates the expected distance between the sun and the k^{th} planet,
 * numbering outward from Mercury starting with 1.
 * each subsequent element in the sequence is twice the
 * preceding one.
 *  getTitiusBodeDistance(1) = 1
 *  getTitiusBodeDistance(2) = 3
 *  getTitiusBodeDistance(k) = 2 * getTitiusBodeDistance(k-1)
 */

int getTitiusBodeDistance(int k)
{
    if(k == 1) return 1;
    else if(k == 2) return 3;
    else
        return 2 * getTitiusBodeDistance(k-1);
}
