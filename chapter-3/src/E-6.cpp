
/*
 * File: E-6.cpp
 * -------------
 * function acronym that takes a string and returns the acronym formed from that string.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "error.h"
using namespace std;


/* Function Prototype */
char acronym(string str);
vector<string> lineToWord(string line);

int main(void)
{
    string str = "Acquired Immune Deficiency Syndrome";
    vector<string> words = lineToWord(str);
    for(auto word : words)
    {
        cout << acronym(word);
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
        if(isalpha(ch))
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
 * Function: acronym(str)
 * Usage: char ch = acronym(str);
 * ---------------------------------------------
 * takes a string and returns the acronym formed from that string.
 */
char acronym(string str)
{
    return str[0];
}
