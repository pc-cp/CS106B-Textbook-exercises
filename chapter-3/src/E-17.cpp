/*
 * File: E-17.cpp
 * ------------------
 * returns a new string formed by shifting every letter
 * in str forward the number of letters indicated by shift,
 * cycling back to the beginning of the alphabet if necessary.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

// constants
const int NUM_ALPHABET_CHARS = 26;

/* Function prototypes */
string encodeCaesarCipher(string str, int shift);

/* Main program */
int main()
{
    int shift;
    string word;

    cout << "This program encodes a message using a Caesar cipher." << endl;
    shift = getInteger("Enter the number of character positions to shift: ");
    // getchar();
    // cout << "Enter a message: ";
    word = getLine("Enter a message: ");
    // getline(cin, word);
    cout << "Encoded message: " << encodeCaesarCipher(word, shift) << endl;
    return 0;

}

/*
 * Function: encodeCaesarCipher
 * Usage: string translation = encodeCaesarCipher(str, shift);
 * -----------------------------------------------------------
 * 遍历str，如果str[i]是字母，则进行如下操作：
 *      1. 检查其大小写，若为大写，则bool upper = true，然后全部转为小写 str[i] = tolower(str[i]);
 *      2. 将str[i] = (str[i] - 'a' + shift + NUM_ALPHABET_CHARS ) % NUM_ALPHABET_CHARS + 'a';
 *      3. if upper = true, str[i] = toupper(str[i]);
 */

string encodeCaesarCipher(string str, int shift)
{
    string newStr;
    for(int i = 0; i < str.length(); ++i)
    {
        char ch = str[i];
        if(isalpha(ch))
        {
            bool upper = false;
            if(ch >= 'A' && ch <= 'Z') upper = true;
            ch = tolower(ch);
            ch = 'a' + (ch - 'a' + shift + NUM_ALPHABET_CHARS) % NUM_ALPHABET_CHARS;
            if(upper) ch = toupper(ch);
        }
        newStr += ch;
    }
    return newStr;
}

