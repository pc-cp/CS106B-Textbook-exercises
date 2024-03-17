

/*
 * File: E-8-8.cpp
 * ---------------------
 * This file generates all permutations of an input string.
 */

#include <iostream>
#include "set.h"
#include "simpio.h"
using namespace std;

/* Function prototype */
Set<string> generatePermutations(string str);

/* Main function */

int main(void)
{
    string str = getLine("Enter a string: ");
    cout << "The permutations of \"" << str << "\" are :" << endl;
    Set<string> set = generatePermutations(str);
    for(auto s : set)
    {
        cout << "\"" << s << "\"" << endl;
    }
    return 0;
}

/*
 * Function: generatePermutations
 * Usage: Set<string> permutations = generatePermutations(str);
 * ------------------------------------------------------------
 * Reimplement the Permutations program so that it uses this new strategy.
 *      Remove the first character from the string and store it in the variable ch.
 *      Generate the set containing all permutations of the remaining characters.
 *      Form a new set by inserting ch in every possible position in each of those permutations.
 */

Set<string> generatePermutations(string str)
{
    Set<string> result;
    if(str == "")
    {
        result += "";
    }
    else
    {
        char ch = str[0];
        Set<string> subResult = generatePermutations(str.substr(1));

        for(string s: subResult) {
            for(int i = 0; i <= s.size(); ++i) {
                result.add(s.substr(0, i) + ch + s.substr(i));
            }
        }

        // for(int i = 0; i < str.length(); ++i)
        // {
        //     char ch = str[i];
        //     string rest = str.substr(0, i) + str.substr(i+1);
        //     Set<string> resultRest = generatePermutations(rest);
        //     for(auto s : resultRest)
        //     {
        //         result.add(ch + s);
        //     }
        // }
    }
    return result;
}

