
/*
 * File: E-5.cpp
 * -------------
 * Write a program that reads in words and prints out their score in Scrabble,
 * not counting any of the other bonuses that occur in the game.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;

const int LETTER_TO_POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

/* Function Prototype */
int wordToScore(string str);
vector<string> lineToWord(string line);

int main(void)
{
    string str = "aBc    def    8ac FARM.";
    vector<string> words = lineToWord(str);
    for(auto word : words)
    {
        cout << word << ": " << wordToScore(word) << endl;
    }
    return 0;
}

/*
 * Function: capitalize(str);
 * Usage: vectot<string> words = lineToWord(line);
 *              ......
 * ---------------------------------------------
 */
vector<string> lineToWord(string line)
{
    vector<string> result;

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
                // result += line.substr(start, i-start);
                result.push_back(line.substr(start, i-start));
                start = -1;
            }
            // result += ch;
        }
    }
    // if(start >= 0) result += line.substr(start);
    if(start >= 0) result.push_back(line.substr(start));
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
int wordToScore(string str)
{
    int ans = 0;
    for(auto x : str)
    {
        if(x >= 'A' && x <= 'Z')
            ans += LETTER_TO_POINTS[x-'A'];
    }
    return ans;
}
