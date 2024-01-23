
/*
 * File: E-14.cpp
 * --------------
 * that takes a string of decimal digits representing a number and
 * returns the string formed by inserting commas at every third position, starting on the right.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include "error.h"
using namespace std;

const int GROUP_LENGTH = 3;

/* 函数原型 */
string addCommas(string digits);

/* 主函数 */
int main()
{

    while (true)
    {
        string digits;
        cout << "Enter a number: ";
        getline(cin, digits);
        if (digits == "")
            break;
        cout << addCommas(digits) << endl;
    }
    return 0;

}


/*
 * 函数名： addCommas
 * 使用方式： string number = createOrdinalForm(digits);
 * ------------------------------------------------------------
 * 因为是从右往左，所以先将digits逆序，然后三个一组返回子串，如果当前不是最后一个子串，则加上','，否则不添加。
 */
string addCommas(string digits)
{
    for(int i = 0; i < digits.length()/2; ++i)
    {
        char ch = digits[i];
        digits[i] = digits[digits.length()-1-i];
        digits[digits.length()-1-i] = ch;
    }

    string newStr;

    for(int pos = 0; ; )
    {
        if(pos >= digits.length())
            break;
        else if(pos > 0)
            newStr += ',';
        newStr += digits.substr(pos, GROUP_LENGTH);
        pos += GROUP_LENGTH;
    }

    for(int i = 0; i < newStr.length()/2; ++i)
    {
        char ch = newStr[i];
        newStr[i] = newStr[newStr.length()-1-i];
        newStr[newStr.length()-1-i] = ch;
    }
    return newStr;
}
