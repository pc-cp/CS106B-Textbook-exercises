
/*
 * File: E-7-1.cpp
 * ---------------
 * Write a recursive function cannonball that takes
 * as its argument the height of the pyramid and
 * returns the number of cannonballs it contains.
 */

#include <iostream>
using namespace std;

int cannonball(int height);

int main(void)
{
    while(true)
    {
        int height;
        cout << "input the height of the pyramid and returns the number of cannonballs it contains (0 to quit): ";
        cin >> height;
        if(height == 0) break;
        cout << cannonball(height) << endl;
    }
    return 0;
}

/*
 * Function: cannonball
 * Usage: int balls = cannonball(height);
 * --------------------------------------
 * Returns the number of cannonballs it contains using the
 * following recursive formulation:
 *      cannonball(1) = 1;
 *      cannonball(n) = n*n + cannonball(n-1);
 */

int cannonball(int height)
{
    if(height == 1) return height * height;
    else
        return height * height + cannonball(height-1);
}
