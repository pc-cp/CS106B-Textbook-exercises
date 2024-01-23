/*
 * File: E-2.cpp
 * -------------
 * Implement the function trim(str) that returns a new string
 * formed by removing all whitespace characters from the beginning and end of str.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "error.h"
using namespace std;

/* Function Prototype */
string trim(string str);



int main(void)
{
    string str = "     ";
    cout << trim(str) << ' ' << trim(str).length() << endl;
    return 0;
}

/*
 * Function: trim();
 * Usage: string newStr = trim(str);
 *              ......
 * ---------------------------------------------
 * returns a new string formed by removing all whitespace characters from the beginning and end of str.
 */
string trim(string str)
{
    int start = -1, end = -1;

    for(int i = 0; i < str.length(); ++i)
    {
        if(!isspace(str[i]))
        {
            start = i;
            break;
        }
    }

    for(int i = str.length()-1; i >= 0; --i)
    {
        if(!isspace(str[i]))
        {
            end = i;
            break;
        }
    }

    if(start == end && start == -1) error("this string is not exist characters except whitespace characters");
    return str.substr(start, end+1-start);

}
