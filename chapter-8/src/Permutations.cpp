
/*
 * File: Permutation.cpp
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
        cout << " \"" << s << " \"" << endl;
    }
    return 0;
}

/*
 * Function: generatePermutations
 * Usage: Set<string> permutations = generatePermutations(str);
 * ------------------------------------------------------------
 * Returns a set consisting of all permutations of the specified string.
 * This implementation uses the recursive insight that you can generate
 * all permutations of a string by selecting each character in turn,
 * generating all permutations of the string without that character,
 * and then concatenating the selected character on the front of each
 * string generated.
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
        for(int i = 0; i < str.length(); ++i)
        {
            char ch = str[i];
            string rest = str.substr(0, i) + str.substr(i+1);
            Set<string> resultRest = generatePermutations(rest);
            for(auto s : resultRest)
            {
                result.add(ch + s);
            }
        }
    }
    return result;
}

