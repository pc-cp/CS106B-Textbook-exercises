
#include <iostream>
#include "set.h"
#include "lexicon.h"
#include "simpio.h"
#include "vector.h"
using namespace std;

bool isShrinkableWords (Lexicon &lex,
                       const string& words,
                       Vector<string> &res) {
    if(!lex.contains(words)) {
        return false;
    }
    else if (words.size() == 1) {
        // res += words;
        res.add(words);
        return true;
    }
    else {
        for(int i = 0; i < words.size(); ++i) {
            string newWords = words.substr(0, i) + words.substr(i+1);
            if(isShrinkableWords(lex, newWords, res)) {
                // res += words;
                res.add(words);
                return true;
            }
        }
        return false;
    }
}

int main(void) {
    Lexicon english("./res/EnglishWords.txt");
    while(true) {
        string input = getLine("input a string: ");
        if(input == "")
            break;
        Vector<string> res = {};
        if(isShrinkableWords(english, input, res)) {
            cout << input << " is a shrinkable word." << endl;
            cout << res << endl;
        }
        else {
            cout << input << " is not a shrinkable word." << endl;
            cout << res << endl;
        }
    }

    return 0;
}
