
/*
 * File: E-11.cpp
 * --------------
 * Write a predicate function isSentencePalindrome(str) that
 * returns true if the string str fits this definition of a sentence palindrome.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* 函数原型 */
bool isSentencePalindrome(string str);

/* 主函数 */
int main(void)
{
    string str;
    cout << "This program tests for sentence palindromes." << endl;
    cout << "Indicate the end of the input with a blank line." << endl;

    while(true)
    {
        cout << "Enter a sentence: ";
        getline(cin, str);
        if(str == "")
            break;

        if(isSentencePalindrome(str))
            cout << "That sentence is a palindrome." << endl;
        else
            cout << "That sentence is not a palindrome." << endl;
    }

    return 0;
}


/*
 * 函数名： isSentencePalindrome(str)
 * 使用方式： if(isSentencePalindrome(str))
 *              ....
 * ------------------------------------------------------------
 * 直接创建一个变量，将str中所有字母类型的字符统一大小写之后读入，然后进行常规操作即可。
 */

bool isSentencePalindrome(string str)
{
    string newStr;
    for(int i = 0; i < str.length(); ++i)
    {
        if(isalpha(str[i])) newStr += tolower(str[i]);
    }

    bool palindrome = true;
    for(int i = 0; i < newStr.length()/2; ++i)
    {
        if(newStr[i] != newStr[newStr.length()-i-1])
        {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}
