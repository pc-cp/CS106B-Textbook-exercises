

/*
 * File: E-8-9.cpp
 * ---------------------
 * This file generates all permutations of an input string.
 */

#include <iostream>
#include "set.h"
#include "simpio.h"
                 using namespace std;

/* Function prototype */
void listPermutations(string str);
void listPermutationsRec(string &str, size_t pos);

/* Main function */

int main(void)
{
    string str = getLine("Enter a string: ");
    cout << "The permutations of \"" << str << "\" are :" << endl;
    listPermutations(str);
    return 0;
}

/*
 * Function: generatePermutations
 * Usage: Set<string> permutations = generatePermutations(str);
 * ------------------------------------------------------------
 * Reimplement the Permutations program so that it uses this new strategy.
 *      At each level, pass the entire string along with an index that indicates where the permutation process starts.
 *      Characters in the string before this index stay where they are; characters at or
 *      after that position must go through all their permutations.
 *
 *      The simple case occurs when the index reaches the end of the string.
 *
 *      The recursive case operates by swapping the character at the index position with every other character
 *      in the string and then generating every permutation starting with the next higher index and
 *      then swapping the characters back to ensure that the original order is restored.
 */

void listPermutations(string str) {
    listPermutationsRec(str, 0);
}

void listPermutationsRec(string &str, size_t pos) {
    if(pos == str.size()) {
        cout << str << endl;
    }
    else {
        for(int i = pos; i < str.size(); ++i) {
            if(pos == i || str[pos] != str[i]) {
                swap(str[pos], str[i]);
                listPermutationsRec(str, pos+1);
                swap(str[pos], str[i]);
            }
        }
    }
}
