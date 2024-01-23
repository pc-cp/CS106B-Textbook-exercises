/*
 * File: E-8.cpp
 * -------------
 * returns a new string consisting of the characters in str after removing all instances of the characters in remove.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* 函数原型 */
void removeCharactersInPlace(string &str, string remove);

/* 主函数 */
int main(void)
{
    string str = "cntrrvltnrs";
    removeCharactersInPlace(str, "aeiou");
    cout << str << endl;
    return 0;
}


/*
 * 函数名： removeCharactersInPlace(string str, string remove);
 * 使用方式： removeCharactersInPlace(str, remove);
 * ------------------------------------------------------------
 * 双指针走起
 */

void removeCharactersInPlace(string &str, string remove)
{
    int len = 0;
    for(int i = 0; i < str.length(); ++i)
    {
        if(remove.find(str[i]) == std::string::npos)
            str[len++] = str[i];
    }
    str.erase(len, str.length()-len);
}
