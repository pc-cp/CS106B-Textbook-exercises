
/*
 * File: E-3.cpp
 * -------------
 * implement a free function substr(str, pos, n) that
 * returns the substring of str beginning at position pos and containing at most n characters.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "error.h"
using namespace std;

/* Function Prototype */
string substr(string str, int pos, int n = -1);



int main(void)
{
    string str = "abcdefgh";
    cout << substr(str, 22) << endl;
    return 0;
}

/*
 * Function: trim();
 * Usage: string newStr = substr(str, pos, n);
 *              ......
 * ---------------------------------------------
 * implement a free function substr(str, pos, n) that
 * returns the substring of str beginning at position pos and containing at most n characters.
 */
string substr(string str, int pos, int n)
{
    if(pos >= str.length()) error("Parameter pos out of bounds.");
    if(n == -1 || n > str.length()-pos)
        n = str.length() - pos;

    string sub = "";
    for(int i = pos; i < pos + n; ++i)
        sub += str[i];

    return sub;
}
