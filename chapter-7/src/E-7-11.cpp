

/*
 * File: E-7-11.cpp
 * Reimplement this function without
 * using streams by exploiting the
 * recursive decomposition of an
 * integer outlined in exercise 7.
 */
#include <iostream>
#include <string>

using namespace std;

/* Function prototype */
string integerToString(int n);

int main(void)
{
    cout << integerToString(1234) << endl;
    return 0;
}
/*
 * Function: integerToString
 * Usage: string str = integerToString(172)
 * ---------------------------------------
 * Reimplement this function without
 * using streams by exploiting the recursive
 * decomposition of an integer outlined in exercise 7.
 *
 *
 */
string integerToString(int n)
{
    if(n < 10)
        return string("") + char('0' + n);
    else
        return integerToString(n/10) + string("") + char('0' + n%10);
}

/*
string integerToString(int n)
{
    ostringstream stream;
    // the output is directed to a string value
    // stored internally as part of the ostringstream object.
    stream << n;
    return stream.str();
}
*/
