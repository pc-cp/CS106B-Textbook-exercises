
/*
 * File: E-16.cpp
 * ------------------
 * the ob should be added before every vowel in the English word except
 *      Vowels that follow other vowels
 *      An e that occurs at the end of the word
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Function prototypes */
string obenglobish(string str);

/* Main program */
int main() {

    while (true)
    {
        string word = getLine("Enter a word: ");
        if (word == "")
            break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    return 0;

}

/*
 * Function: obenglobish
 * Usage: string translation = obenglobish(word);
 * -------------------------------------------------
 * 如果当前元音字母不在其他元音的后面或者当前字母是e且为最后一个，则将"ob"+ch加入到新的字符串中
 */

string obenglobish(string str)
{
    string newStr;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != 'a' && str[i] != 'o' && str[i] != 'e' && str[i] != 'i' && str[i] != 'u')
            newStr += str[i];
        else if(i && (str[i-1] == 'a' || str[i-1] == 'o' || str[i-1] == 'e' || str[i-1] == 'i' || str[i-1] == 'u'))
            newStr += str[i];
        else if(str[i] == 'e' && i == str.length()-1)
            newStr += str[i];
        else
        {
            newStr += "ob";
            newStr += str[i];
        }
    }
    return newStr;
}

