
/*
 * CS106B Section Handout Test Harness: Section 2
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified for Qt and Ed by Neel
 * Kishnani for Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include "testing/SimpleTest.h"
#include "lexicon.h"
#include "set.h"
#include <string>
using namespace std;

Set<string> embeddedWordsRec(const string & startWord) {
    Set<string> res;
    if(startWord.size() == 0) {
        string elem = "";
        return res + elem;
    }
    else {
        Set<string> subres = embeddedWordsRec(startWord.substr(1));
        for(string str : subres) {
            res.add(startWord[0] + str);
        }
        return res + subres;
    }
}

Set<string> embeddedWords(const string startWord, const Lexicon& words) {
    Set<string> powerSet = embeddedWordsRec(startWord);
    Set<string> res;
    for(auto str : powerSet) {
        if(words.contains(str)) {
            res.add(str);
        }
    }
    return res;
}


static Lexicon& sharedLexicon() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

PROVIDED_TEST("Example from Exercise-8-5") {
    Lexicon& lex = sharedLexicon();
    string startWord = "happy";

    Set<string> res = {"a", "ay", "ha", "hap", "happy", "hay"};
    EXPECT_EQUAL(embeddedWords(startWord, lex), res);
}
