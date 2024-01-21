/* File: E-13.cpp
 * --------------
 * show the number of atoms remaining at the end of each year.
 */

#include <iostream>
#include "random.h"

using namespace std;

const int INITIALIZER_NUMBERS = 10000;

int main(void)
{
    int numbers = INITIALIZER_NUMBERS;
    int year = 0;
    cout << "There are " << numbers << " atoms initially." << endl;

    do
    {
        int left = numbers;
        for(int i = 1; i <= numbers; ++i)
        {
            if(randomChance(0.5))   left--;
        }
        year++;
        cout << "There are " << left << " atoms at the end of year " << year << '.' << endl;

        numbers = left;
    }while(numbers);

    return 0;
}
