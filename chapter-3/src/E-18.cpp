
/*
 * File: E-18.cpp
 * ------------------
 * Write a program that implements encryption using a letter-substitution cipher.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Function prototypes */
string encodeCaesarCipher2(string str, string key);

/* Main program */
int main()
{
    string key, word;

    cout << "This program encodes a message using a Caesar cipher." << endl;
    key = getLine("Enter a 26-letter key: ");
    word = getLine("Enter a message: ");
    cout << "Encoded message: " << encodeCaesarCipher2(word, key) << endl;
    return 0;

}

/*
 * Function: encodeCaesarCipher2
 * Usage: string translation = encodeCaesarCipher2(str, key);
 * -----------------------------------------------------------
 * 遍历str，如果str[i]是字母，则进行如下操作：
 *      1. 检查其大小写，若为小写，则bool lower = true，然后全部转为大写 str[i] = toupper(str[i]);
 *      2. 将str[i]替换成其对应的key，即str[i] = key[str[i]-'A'];;
 *      3. if lower = true, str[i] = tolower(str[i]);
 */

string encodeCaesarCipher2(string str, string key)
{
    string newStr;
    for(int i = 0; i < str.length(); ++i)
    {
        char ch = str[i];
        if(isalpha(ch))
        {
            bool lower = false;
            if(ch >= 'a' && ch <= 'z') lower = true;
            ch = toupper(ch);
            ch = key[ch-'A'];
            if(lower) ch = tolower(ch);
        }
        newStr += ch;
    }
    return newStr;
}

