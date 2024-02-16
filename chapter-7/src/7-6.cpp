
#include <iostream>

using namespace std;

/* Function prototype */
bool isOdd(unsigned int n);
bool isEven(unsigned int n);

int main(void)
{
    int n;
    cin >> n;
    if(isEven(n))
        cout << "even" << endl;
    else
        cout << "odd" << endl;
    return 0;
}

/*
 * Function: isOdd
 * Usage: if(isOdd(n)) . . .
 * -------------------------
 * Returns true if the unsigned number n is odd. A number is odd
 * if it is not even.
 *
 */
bool isOdd(unsigned int n)
{
    return !isEven(n);
}

/*
 * Function: isEven
 * Usage: if(isEven(n)) . . .
 * --------------------------
 * Returns true if the unsigned number n is even. A number is even
 * either (1) if it is zero or (2) if its predecessor is odd.
 */

bool isEven(unsigned int n)
{
    if(n == 0)
        return true;
    else
        return isOdd(n-1);
}
