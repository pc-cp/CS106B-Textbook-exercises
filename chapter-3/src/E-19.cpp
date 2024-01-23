
/*
 * File: E-19.cpp
 * ------------------
 * Write a program that implements encryption using a letter-substitution cipher.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Function prototypes */
string invertKey(string key);

/* Main program */
int main()
{
    string key, word;

    cout << "This program encodes a message using a Caesar cipher." << endl;
    key = getLine("Enter a 26-letter key: ");
    cout << "invertKey: " << invertKey(key) << endl;
    return 0;
}

/*
 * Function: invertKey(string key)
 * Usage: string translation = invertKey(key);
 * -----------------------------------------------------------
 * 创建一个新的字符数组char newStr[26], 遍历key, 将key[i]映射到newStr[key[i]-'A']中, 即newStr[key[i]-'A'] = i+'A';
 * 然后将newStr转换成string对象
 */

string invertKey(string key)
{
    char newStr[26];
    for(int i = 0; i < key.length(); ++i)
    {
        newStr[key[i]-'A'] = i + 'A';
    }
    return string(newStr);
}

