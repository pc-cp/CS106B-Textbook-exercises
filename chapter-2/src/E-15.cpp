/* File: E-15.cpp
 * --------------
 * Write a program that simulates flipping a coin repeatedly
 * and continues until three consecutive heads are tossed.
 */

#include <iostream>
#include "random.h"

using namespace std;

/* Prototype function */


/* Main function*/
int main(void)
{
    int totalNumbers = 0;
    int firstHead = 0, secondHead = 0, thirdHead = 0;

    while(firstHead+1 != secondHead || firstHead+2 != thirdHead)
    {
        totalNumbers++;

        if(randomChance(0.5))
        {
            if(firstHead == 0)
                firstHead = totalNumbers;
            else
            {
                if(secondHead == 0)
                    secondHead = totalNumbers;
                else
                    thirdHead = totalNumbers;
            }
            cout << "heads" << endl;
        }
        else
        {
            firstHead = secondHead = thirdHead = 0;
            cout << "tails" << endl;
        }
    }
    cout << "It look " << totalNumbers << " flip to get 3 consecutiove heads." << endl;

    return 0;
}
