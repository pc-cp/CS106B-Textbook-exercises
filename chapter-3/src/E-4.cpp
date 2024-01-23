/*
 * File: E-4.cpp
 * -------------
 * Implement a function capitalize(str) that returns a string in which
 * the initial character is capitalized (if it is a letter) and all other letters are converted to lowercase.
 * Characters other than letters are not affected.
 */

#include <iostream>
#include <string>
#include <cctype>
#include "error.h"
using namespace std;

/* Function Prototype */
string capitalize(string str);
string wordToCapitalize(string str);

int main(void)
{
    string str = "aBc    def    8ac";
    cout << capitalize(str) << endl;
    return 0;
}

/*
 * Function: capitalize(str);
 * Usage: string newStr = capitalize(str);
 *              ......
 * ---------------------------------------------
 * Implement a function capitalize(str) that returns a string in which
 * the initial character is capitalized (if it is a letter) and all other letters are converted to lowercase.
 * Characters other than letters are not affected.
 */
string capitalize(string line)
{
    string result;
    int start = -1;
    for(int i = 0; i < line.length(); ++i)
    {
        char ch = line[i];
        if(isalnum(ch))
        {
            if(start == -1) start = i;
        }
        else
        {
            if(start >= 0)
            {
                result += wordToCapitalize(line.substr(start, i-start));
                start = -1;
            }
            result += ch;
        }
    }
    if(start >= 0) result += wordToCapitalize(line.substr(start));
    return result;
}

/*
 * Function: wordToCapitalize(str)
 * Usage: string newStr = wordToCapitalize(str);
 * ---------------------------------------------
 * Implement a function capitalize(str) that returns a string in which
 * the initial character is capitalized (if it is a letter) and all other letters are converted to lowercase.
 * Characters other than letters are not affected.
 */
string wordToCapitalize(string str)
{
    for(int i = 0; i < str.length(); ++i)
    {
        if(isalpha(str[i]))
        {
            if(i == 0) str[i] = toupper(str[i]);
            else str[i] = tolower(str[i]);
        }
    }
    return str;
}
