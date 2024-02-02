
/*
 * File: E-22.cpp
 * ----------------------
 * Rewrite the FindAreaCode program so that
 * it creates an inverted map after reading in the data
 * file and then uses that map to list the area codes for a state.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "error.h"
#include "map.h"
#include "strlib.h"
#include "lexicon.h"

using namespace std;

/* Function prototype */
void printPalindrome(Lexicon english);
bool isPalindrome(string word);

/* Main function */
int main(void)
{
    Lexicon english("EnglishWords.dat");
    printPalindrome(english);
    return 0;
}

void printPalindrome(Lexicon english)
{
    for(string word: english)
    {
        cout << word << endl;
        if(isPalindrome(word))
        {
            cout << word << endl;
        }
    }
}

bool isPalindrome(string word)
{
    for(int i = 0; i < word.length()/2; ++i)
    {
        if(word[i] != word[word.length()-1-i])
            return false;
    }
    return true;
}
