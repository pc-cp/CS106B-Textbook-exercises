
/*
 * File: E-9.cpp
 * -------------
 * returns a new string in which any duplicated characters in str have been replaced by a single copy.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* 函数原型 */
string removeDoubledLetters(string str);

/* 主函数 */
int main(void)
{
    string str = "commmmmitteeee";

    cout << removeDoubledLetters(str) << endl;
    return 0;
}


/*
 * 函数名： removeDoubledLetters
 * 使用方式： string newStr = string removeDoubledLetters(str);
 * ------------------------------------------------------------
 * 创建一个新的string 变量 newStr, 遍历str，如果i为0或者str[i]为与str[i-1]不相同的话，加入到newStr中
 */

string removeDoubledLetters(string str)
{
    string newStr;
    for(int i = 0; i < str.length(); ++i)
    {
        if(i == 0 || str[i] != str[i-1]) newStr += str[i];
    }
    return newStr;
}
