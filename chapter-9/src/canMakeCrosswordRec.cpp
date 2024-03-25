
#include <iostream>
#include "set.h"
#include "lexicon.h"
#include "simpio.h"
#include "vector.h"
#include "grid.h"
using namespace std;

bool canMakeCrosswordRec(Grid<char>& crossword,
                         int nextRow,
                         const Lexicon& rowWords,
                         const Lexicon& colWords) {
    if(nextRow == crossword.numRows()) {
        return true;
    }
    else {
        for(auto str : rowWords) {
            if(str.size() == crossword.numCols()) {
                for(int i = 0; i < crossword.numCols(); ++i) {
                    crossword[nextRow][i] = str[i];
                }
                bool satisfiedPrefix = true;
                for(int i = 0; i < crossword.numCols(); ++i) {
                    string wordPrefix = "";
                    for(int j = 0; j <= nextRow; ++j) {
                        wordPrefix += crossword[j][i];
                    }
                    if(!colWords.containsPrefix(wordPrefix)) {
                        satisfiedPrefix = false;
                        break;
                    }
                }
                if(satisfiedPrefix) {
                    if(canMakeCrosswordRec(crossword,
                                               nextRow+1,
                                               rowWords,
                                            colWords)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}


int main(void) {
    Lexicon english("./res/EnglishWords.txt");
    // if(english.contains("merer")) {
    //     cout << "++" << endl;
    // }
    Grid<char> crossword(5, 5);
    if(canMakeCrosswordRec(crossword, 0, english, english)) {
        cout << crossword << endl;
    }
    else {
        cout << "..." << endl;
    }

    return 0;
}
