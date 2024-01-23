
/*
 * File: E-13.cpp
 * --------------
 * returns the ordinal form of the number n as a string.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include "error.h"
using namespace std;


/* 函数原型 */
string createOrdinalForm(int n);

/* 主函数 */
int main(void)
{

    cout << createOrdinalForm(104) << endl;
    cout << createOrdinalForm(122) << endl;
    cout << createOrdinalForm(-111) << endl;
    return 0;
}


/*
 * 函数名： createOrdinalForm
 * 使用方式： string numberToOrdinalForm = createOrdinalForm(n);
 * ------------------------------------------------------------
 * 实现方式：得到数字的个位数字，同时对一些数字(11, 12, 13)进行特判
 *      如果数字以1结尾（除了11之外），在数字后添加 "st"，例如 1st, 21st, 31st 等。
 *      如果数字以2结尾（除了12之外），在数字后添加 "nd"，例如 2nd, 22nd, 32nd 等。
 *      如果数字以3结尾（除了13之外），在数字后添加 "rd"，例如 3rd, 23rd, 33rd 等。
 *      对于所有其他数字（包括以0, 4, 5, 6, 7, 8, 9结尾的数字，以及11, 12, 13），在数字后添加 "th"，例如 4th, 11th, 20th, 25th 等。
 */
string createOrdinalForm(int n)
{
    string newStr;
    bool negative = false;

    if(n == 0)
        newStr += '0';
    else
    {
        int temp = 0;
        if(n > 0)
            temp = n;
        else
        {
            negative = true;
            // newStr += '-';
            temp = abs(n);
        }
        while(temp)
        {
            newStr += temp % 10 + '0';
            temp /= 10;
        }
    }

    if(negative) newStr += '-';

    for(int i = 0; i < newStr.length()/2; ++i)
    {
        char ch = newStr[i];
        newStr[i] = newStr[newStr.length()-1-i];
        newStr[newStr.length()-1-i] = ch;
    }
    cout << newStr << endl;

    int lastDigit = abs(n) % 10;
    switch (lastDigit)
    {
        case 1:
            if(int(abs(n))%100 == 11)
                newStr += "th";
            else
                newStr += "st";
            break;
        case 2:
            if(int(abs(n))/100 == 12)
                newStr += "th";
            else
                newStr += "nd";
            break;
        case 3:
            if(int(abs(n))%100 == 13)
                newStr += "th";
            else
                newStr += "rd";
            break;
        default:
            newStr += "th";
            break;
    }
    return newStr;
}
